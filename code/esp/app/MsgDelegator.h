/*
 * MsgDelegator.h
 *
 *  Created on: May 8, 2017
 *      Author: elmar
 */

#ifndef APP_MSGDELEGATOR_H_
#define APP_MSGDELEGATOR_H_

#include "ProtoStream.h"
#include "StreamXmega.h"

#include "swakeup.pb.h"

#include "application.h"

#include <SmingCore/HardwareSerial.h>

static void sendRest(MsgFrame * frame) {
	// Seems a little redundant to do this every time
	// TODO have a predefined location struct do this
	strncpy(frame->location.city, userSettings.city.c_str(), sizeof(frame->location.city));
	strncpy(frame->location.country, userSettings.country.c_str(), sizeof(frame->location.country));
	restStream.writeMessage(frame);
}

void msgCallback(MsgFrame * frame, void * stream) {
	switch (frame->typ) {
	case MsgType_MSG_TYPE_NONE:
		break;
	case MsgType_MSG_TYPE_POWER:
		break;
	case MsgType_MSG_TUPE_LOCATION:
		break;
	case MsgType_MSG_TYPE_DATE_TIME:
		if (stream == (void*) &restStream) {
			//print it out for debug purposes
			DateAndTime * dat = &frame->pl.dateAndTime;
			xmegaStream.writeMessage(frame);
		} else if (stream == (void*) &xmegaStream) {
			// Request it?
			sendRest(frame);
		} else {
			sendRest(frame);
		}
		break;
	case MsgType_MSG_TYPE_WEATHER:
		if (stream == (void*) &restStream) {
			Weather * wet = &frame->pl.weather;
			xmegaStream.writeMessage(frame);
		} else if (stream == (void*) &xmegaStream) {
			// Request it?
			sendRest(frame);
		} else {
			sendRest(frame);
		}
		break;
	case MsgType_MSG_TYPE_SOCIAL:
		break;
	case MsgType_MSG_TYPE_MAIL:
		break;
	case MsgType_MSG_TYPE_ALARM_SET:
		break;
	case MsgType_MSG_TYPE_ALARM_GET:
		break;
	}
}

#endif /* APP_MSGDELEGATOR_H_ */
