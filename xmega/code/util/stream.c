#include "stream.h"
#include "../modules/log.h"

LOG_INIT("TnStream");

static uint8_t __attribute__((warn_unused_result)) buf_read(pb_istream_t *stream, uint8_t *buf, size_t count) {
    struct stream_in * readStream = stream->state;
    size_t i = 0; //todo remove
    while (i < count) {
        buf[i] = readStream->readBuffer[readStream->readBufferPos];
        readStream->readBufferPos++;
        i++;
    }
    return 1;
}

void stream_init(Stream * stream) {
    stream->inputStream.stream.state = &stream->inputStream;
    stream->outputStream.stream.state = &stream->outputStream;
}

uint8_t stream_readCallback(pb_istream_t *stream, uint8_t *buf, size_t count) {
    LOG_DEBUG("prepare to read:%d bytes!\n", count);
    if (stream->bytes_left < count)
        PB_RETURN_ERROR(stream, "end-of-stream");
    return buf_read(stream, buf, count);
}

void logErrorExpected(uint8_t exp, uint8_t got) {
    LOG_WARNING("Expected %02x but got %02x\n", exp, got);
}

uint8_t stream_readByte(Stream * stream, uint8_t byte) {
    //printf("Byte: %02x state: %d flags: %d \n",byte,stream->state, stream->flags);
    switch (stream->state) {
    case PREFIX_AA:
        if (byte == 0xAA) {
            stream->state = PREFIX_BB;
        } else if (byte == 0xBB) {
            stream->state = PREFIX_CC;
        } else {
            logErrorExpected(0xAA, byte);
            return 0;
        }
        break;
    case PREFIX_BB:
        if (byte == 0xBB) {
            stream->state = PREFIX_CC;
        } else {
            logErrorExpected(0xBB, byte);
        }
        break;
    case PREFIX_CC:
        if (byte == 0xCC) {
            stream->state = PREFIX_DD;
        } else {
            logErrorExpected(0xCC, byte);
        }
        break;
    case PREFIX_DD:
        if (byte == 0xDD) {
            stream->state = SIZE_1;
        } else {
            logErrorExpected(0xDD, byte);
        }
        break;
    case SIZE_1:
        stream->inputStream.toRead = byte;
        stream->state = SIZE_2;
        break;
    case SIZE_2: {
        uint8_t temp1 = stream->inputStream.toRead;
        uint8_t temp2 = byte;
        stream->inputStream.toRead = (temp1 << 8) | temp2;
        stream->state = DATAS;
        if (stream->inputStream.toRead > MAX_IN_SIZE) {
            LOG_WARNING("Max input-size exceeded");
            return 0;
        }
    }
    break;
    case DATAS:
        stream->inputStream.readBuffer[stream->inputStream.writeBufferPos] = byte;
        stream->inputStream.writeBufferPos++;
        if (stream->inputStream.writeBufferPos >= stream->inputStream.toRead) {
            stream->inputStream.stream = pb_istream_from_buffer(stream->inputStream.readBuffer, stream->inputStream.toRead);
            stream->state = PREFIX_AA;
            return 1;
        }
        break;
    }
    return 0;
}
