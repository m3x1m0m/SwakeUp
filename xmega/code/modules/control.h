
#ifndef CONTROL_H_
#define CONTROL_H_

#include <stdlib.h>
#include <stdint.h>
#include "../pin_definitions.h"
#include "../util/stream.h"
#include "../util/event.h"
#include "../util/protobuf/swakeup.pb.h"

EVENT_EXP(ProtoReceive);

/**
 * Streams the controller supports.
 */
typedef enum {
    CTRL_STREAM_USB,
    CTRL_STREAM_ESP,
    CTRL_STREAM_LOOPBACK
} CtrlStreams;

void writeMessage(Stream * stream, MsgFrame * frame);

void messageReceived(Stream * stream);

Stream * ctrlGetStream(CtrlStreams stream);

void resetInstreamStream(Stream * stream);

void processMessage(Stream * stream, MsgFrame * frame);

void messageSent(Stream * stream, MsgFrame * message);

MODULE_EXP(CONTROL);

#endif /* CONTROL_H_ */
