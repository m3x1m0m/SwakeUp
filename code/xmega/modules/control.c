
#include "log.h"
#include "../pin_definitions.h"
#include "../drivers/uart/esp8266.h"
#include "control.h"
#include "../util/protobuf/pb_decode.h"
#include "../util/protobuf/pb_encode.h"
#include "../drivers/uart/terminal.h"
#include <stdio.h>
#include "control.h"

static MsgFrame message;

LOG_INIT("Control");

EVENT_REGISTER(PROTO_RECEIVE, "When a message has been received");

void resetInstreamStream(Stream * stream) {
    stream->inputStream.toRead = 0;
    stream->inputStream.readBufferPos = 0;
    stream->inputStream.writeBufferPos = 0;
    stream->idleTimer = 0;
    stream->state = PREFIX_AA;
}

static const pb_byte_t startDelimitation[] = {0xAA, 0xBB, 0xCC, 0xDD} ;

void writeMessage(Stream * stream, MsgFrame * frame) {
    size_t size;
    pb_get_encoded_size(&size, MsgFrame_fields, frame);
    stream->outputStream.stream.bytes_written = 0; //TODO this should not be required
    const pb_byte_t tempSize[] = {(size ) & 0xFF, (size >> 8) & 0xFF};
    LOG_DEBUG("Sending with size: %d ", size);
    stream->outputStream.stream.callback(&stream->outputStream.stream, startDelimitation, 4);
    stream->outputStream.stream.callback(&stream->outputStream.stream, tempSize, 2);
    pb_encode(&stream->outputStream.stream, MsgFrame_fields, frame);
    //stream->outputStream.flush(stream); TODO
}


void messageReceived(Stream * stream) {
    stream->msgPointer = &message;
    event_fire(&PROTO_RECEIVE, (uint8_t *) stream);
}

Stream * ctrlGetStream(CtrlStreams stream) {
    switch (stream) {
    case CTRL_STREAM_USB:
        LOG_ERROR("Wrong stream request");
        //TODO
        break;
    case CTRL_STREAM_ESP:
        ESP8266_stream.msgPointer = &message;
        return &ESP8266_stream;
    case CTRL_STREAM_LOOPBACK:
        LOG_ERROR("Wrong stream request");
        //TODO
        break;
    }
    return NULL;
}

static void callback(Event * event, uint8_t * data) {
    if (event == &PROTO_RECEIVE) {
        Stream * stream = (Stream *) data;
        uint8_t status = pb_decode(&stream->inputStream.stream, MsgFrame_fields, &message);
#ifdef PROTO_PRINT
        LOG_DEBUG("Printing a message with size of: %d", stream->inputStream.toRead);
        terminal_write("\t");
        uint8_t i = 0, l = stream->inputStream.toRead;
        for (; i < l; i++) {
            terminal_write("(%d) ", (uint8_t)stream->inputStream.readBuffer[i]);
        }
        terminal_write("\r\n");
#endif
        if (status) {
            processMessage(stream, &message);
        } else {
            LOG_WARNING("Decoding failed: %s\n", stream->inputStream.stream.errmsg);
        }
        resetInstreamStream(stream);
    }
}

static uint8_t init(void) {
    event_addListener(&PROTO_RECEIVE, callback);
    LOG_SYSTEM("Control initialized");
    return 1;
}
static uint8_t deinit(void) {
    event_removeListener(&PROTO_RECEIVE, callback);
    return 1;
}
MODULE_DEFINE(CONTROL, "Communication Control", init, deinit, &LOGGER, &ESP8266);