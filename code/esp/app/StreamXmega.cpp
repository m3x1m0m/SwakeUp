/*
 * StreamXmega.cpp
 *
 *  Created on: Apr 28, 2017
 *      Author: elmar
 */

#include "StreamXmega.h"

StreamXmega xmegaStream;

static bool writeSerial(pb_ostream_t * stream __attribute__ ((unused)),
		const pb_byte_t *buf, size_t count) {
	uint8_t i = 0;
	for (; i < count; i++) {
		Serial.write(buf[i]);
	}
	return i == count;
}

StreamXmega::StreamXmega() :
		ProtoStream(&writeSerial) {
	Serial.setCallback(StreamDataReceivedDelegate(&StreamXmega::onReceive, this));
	Serial.begin(SERIAL_BAUD_RATE);
	Serial.systemDebugOutput(false);
}

void StreamXmega::onReceive(Stream& stream, char arrivedChar, unsigned short availableCharsCount) {
	processByte(arrivedChar);
}

StreamXmega::~StreamXmega() {
	// TODO Auto-generated destructor stub
}

