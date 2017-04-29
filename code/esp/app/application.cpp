#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include "SerialReadingDelegateDemo.h"
#include "StreamXmega.h"
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

void init() {
	StreamXmega xmegaStream;
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(false);
	/*uint8_t sendArr[] = { 0xAA, 0xBB, 0xCC, 0xDD, 11, 0, 8, 17, 138, 1, 6, 8,
			12, 16, 12, 24, 12 };
	uint8_t i = 0;
	for (; i < sizeof(sendArr); i++) {
		Serial.write(sendArr[i]);
	}*/
	MsgFrame frame;

	frame.typ = MsgType_MSG_TYPE_TIME;
	frame.which_pl = MsgFrame_time_tag;
	frame.pl.time.hour = (12 & 0xFF);
	frame.pl.time.minute = (12 & 0xFF);
	frame.pl.time.second = (12 & 0xFF);
	xmegaStream.writeMessage(frame);
	/// Reading callback example:
	//  * Option 1
	//	Set Serial Callback to global routine:
	//	   Serial.setCallback(onDataCallback);

	// 	* Option 2
	//  Instantiate hwsDelegateDemo which includes Serial Delegate class
	//delegateDemoClass.begin();
}
