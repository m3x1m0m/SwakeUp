#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include "SerialReadingDelegateDemo.h"
#include "StreamXmega.h"
#include "StreamRest.h"
#include "swakeup.pb.h"

#ifndef WIFI_SSID
#define WIFI_SSID "Abcdeff" // Put you SSID and Password here
#define WIFI_PWD "ElmarElmar"
#endif

Timer procTimer;
SerialReadingDelegateDemo delegateDemoClass;
int helloCounter = 0;
bool state = true;

void blink()
{
	digitalWrite(2, state);
	state = !state;
}

void sayHello() {
	Serial.print("Hello Sming! Let's do smart things.");
	Serial.print(" Time : ");
	Serial.println(micros());
	Serial.println();

	Serial.printf("This is Hello message %d \r\n", ++helloCounter);
}

void testPrintf() {

}

void testXmega(MsgFrame frame) {
	//xmegaStream.writeMessage(frame);
}

void testRest(MsgFrame frame) {
	restStream.writeMessage(frame);
}

void protoTest() {
	blink();
	MsgFrame frame;
	frame.typ = MsgType_MSG_TYPE_TIME;
	frame.which_pl = MsgFrame_time_tag;
	frame.pl.time.hour = (12 & 0xFF);
	frame.pl.time.minute = (12 & 0xFF);
	frame.pl.time.second = (12 & 0xFF);
	testRest(frame);
}

void periodTest() {
	procTimer.initializeMs(20 * 1000, protoTest).start(true); // every 20 seconds
}

void init() {
	pinMode(2, OUTPUT);
	Serial.systemDebugOutput(true); // Debug output to serial
	//periodTest();
	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiStation.enable(true);
	WifiAccessPoint.enable(false);

	// Run our method when station was connected to AP (or not connected)
	WifiStation.waitConnection(periodTest);
}
