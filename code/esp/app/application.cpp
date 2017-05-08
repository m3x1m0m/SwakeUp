#include <user_config.h>
#include <SmingCore/SmingCore.h>
// #include "streams/StreamWebsocket.h"
#include "StreamXmega.h"
#include "swakeup.pb.h"
#include "application.h"
#include "MsgDelegator.h"

#ifndef WIFI_SSID
#define WIFI_SSID "U&L" // Put you SSID and Password here
#define WIFI_PWD "BESTunalejla123"
#endif

Timer procTimer;
int helloCounter = 0;
bool state = true;

void blink() {
	digitalWrite(2, state);
	state = !state;
	MsgFrame frame;
	frame.typ = MsgType_MSG_TYPE_DATE_TIME;
	msgCallback(&frame, NULL);
}

String city = "Graz";
String country = "Austria";

void periodTest() {
	//web.connect();
	MsgFrame frame;
	frame.typ = MsgType_MSG_TYPE_DATE_TIME;
	msgCallback(&frame, NULL);
	procTimer.initializeMs(10 * 1000, blink).start(true); // every 20 seconds

}

void init() {
	pinMode(2, OUTPUT);
	Serial.begin(SERIAL_BAUD_RATE);
	Serial.systemDebugOutput(true); // Debug output to serial

	// TODO this should be set from the web interface
	userSettings.city = city;
	userSettings.country = country;

	// TODO this should be moved out here, constructor?
	// Setting callback for receiving the messages
	restStream.setMsgCallback(&msgCallback);

	//periodTest();
	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiStation.enable(true);
	WifiAccessPoint.enable(false);

	// Run our method when station was connected to AP (or not connected)
	WifiStation.waitConnection(periodTest);
}
