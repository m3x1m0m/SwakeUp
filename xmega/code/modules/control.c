
#include "log.h"
#include "../drivers/uart/esp8266.h"
#include "control.h"
#include "../util/protobuf/pb_decode.h"
#include "../util/protobuf/pb_encode.h"
#include <stdio.h>
#include "control.h"

static MsgFrame message;

LOG_INIT("Control");

EVENT_REGISTER(streamSent, "When a message has been sent");

void resetInstreamStream(Stream * stream) {
    stream->inputStream.toRead = 0;
    stream->inputStream.readBufferPos = 0;
    stream->inputStream.writeBufferPos = 0;
    stream->idleTimer = 0;
    stream->state = PREFIX_AA;
}

void writeMessage(Stream * stream, MsgFrame * frame) {
    pb_encode(&stream->outputStream.stream, MsgFrame_fields, frame);
    stream->outputStream.flush(stream);
}


void messageReceived(Stream * stream) {
    stream->msgPointer = &message;
    uint8_t status = pb_decode(&stream->inputStream.stream, MsgFrame_fields, &message);
    if (status) {
        processMessage(stream, &message);
    } else {
        LOG_WARNING("Decoding failed: %s\n", stream->inputStream.stream.errmsg);
    }
    resetInstreamStream(stream);
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
