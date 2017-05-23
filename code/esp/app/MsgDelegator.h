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
#include <stdio.h>

#include <SmingCore/HardwareSerial.h>

static void sendRest(MsgFrame * frame) {
	// Seems a little redundant to do this every time
	// TODO have a predefined location struct do this
	strncpy(frame->location.city, ActiveConfig.city.c_str(), sizeof(frame->location.city));
	strncpy(frame->location.country, ActiveConfig.country.c_str(), sizeof(frame->location.country));

	restStream.writeMessage(frame);
}

void msgCallback(MsgFrame * frame, void * stream) {
	switch (frame->typ) {
	case MsgType_MSG_TYPE_NONE:
		break;
	case MsgType_MSG_TYPE_POWER:
		break;
	case MsgType_MSG_TYPE_LOCATION:
		break;
	case MsgType_MSG_TYPE_DATE_TIME:
		if (stream == (void*) &restStream) {
			//print it out for debug purposes
			char clockbuf[11];
			sprintf(clockbuf, "20%02d/%02d/%02d", frame->pl.dateAndTime.year, frame->pl.dateAndTime.month, frame->pl.dateAndTime.day);
			ActiveConfig.date = String((const char *) clockbuf);
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
	case MsgType_MSG_TYPE_EMAIL:
		break;
	case MsgType_MSG_TYPE_ALARM_PUT:
		break;
	case MsgType_MSG_TYPE_ALARM_GET:
		break;
	}
}

#endif /* APP_MSGDELEGATOR_H_ */
