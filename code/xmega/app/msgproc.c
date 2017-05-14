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
#include "clock.h"
LOG_INIT("MsgProc");

void processMessage(Stream * stream, MsgFrame * message) {
    (void)stream; //This will be used in the future to send back information
    LOG_INFO("Received message: %d", message->typ);
    switch (message->typ) {
    case   MsgType_MSG_TYPE_NONE:
        LOG_WARNING("Type has not been set! This should not happen");
        break;
    case MsgType_MSG_TYPE_POWER:
        break;
    case MsgType_MSG_TYPE_LOCATION:
        break;
    case MsgType_MSG_TYPE_DATE_TIME: {
        DateAndTime * tim = &message->pl.dateAndTime;
        if (tim->day != 0) {
            //Day will only ever be 0 if there is no date set
            timekeeper_set(tim->year, tim->month, tim->day, tim->hour, tim->minute, tim->second);
        } else {
            timekeeper_time_set(tim->hour, tim->minute, tim->second);
        }
    }
    break;
    case MsgType_MSG_TYPE_WEATHER:
        LOG_DEBUG("Setting weather: %c %c", message->pl.weather.city[0], message->pl.weather.city[1]);
        weather_set(message->pl.weather);
        break;
    case MsgType_MSG_TYPE_SOCIAL:
        break;
    case MsgType_MSG_TYPE_EMAIL:
        break;
    case MsgType_MSG_TYPE_ALARM_GET:
        break;
    case MsgType_MSG_TYPE_ALARM_PUT:
        break;
	case MsgType_MSG_TYPE_ALARM_REMOVE:
		break;
    }
}