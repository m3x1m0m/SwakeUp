#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include "SerialReadingDelegateDemo.h"
#include "StreamXmega.h"
#include "StreamRest.h"
#include "swakeup.pb.h"

Timer procTimer;
SerialReadingDelegateDemo delegateDemoClass;
int helloCounter = 0;

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
	xmegaStream.writeMessage(frame);
}

void testRest(MsgFrame frame) {
	restStream.writeMessage(frame);
}

void init() {
	MsgFrame frame;
	frame.typ = MsgType_MSG_TYPE_TIME;
	frame.which_pl = MsgFrame_time_tag;
	frame.pl.time.hour = (12 & 0xFF);
	frame.pl.time.minute = (12 & 0xFF);
	frame.pl.time.second = (12 & 0xFF);
	testRest(frame);
}
