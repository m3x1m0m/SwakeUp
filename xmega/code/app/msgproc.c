/*
 * msgproc.c
 *
 * Created: 4/24/2017 1:28:53 PM
 *  Author: elmar
 */

#include "../modules/log.h"
#include "../util/protobuf/swakeup.pb.h"
#include "../util/stream.h"
#include "msgproc.h"
#include "core.h"
#include "weather.h"

LOG_INIT("MsgProc");

void processMessage(Stream * stream, MsgFrame * message) {
    LOG_INFO("Received message: %d", message->typ);
    switch (message->typ) {
    case MsgType_MSG_TUPE_LOCATION:
        break;
    case MsgType_MSG_TYPE_TIME: {
        Time * tim = &message->pl.time;
        core_time_set(tim->hour, tim->minute, tim->second);
    }
    break;
    case MsgType_MSG_TYPE_DATE:
        break;
    case MsgType_MSG_TYPE_WEATHER:
        weather_set(message->pl.weather);
        break;
    case MsgType_MSG_TYPE_SOCIAL:
        break;
    case MsgType_MSG_TYPE_MAIL:
        break;
    }
}