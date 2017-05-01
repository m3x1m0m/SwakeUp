/*
 * RestStream.cpp
 *
 *  Created on: May 2, 2017
 *      Author: elmar
 */

#include "StreamRest.h"

StreamRest restStream;

static bool writeSerial(pb_ostream_t * stream __attribute__ ((unused)),
		const pb_byte_t *buf, size_t count) {
	return restStream.writeBytes((char*) buf, count);
}

StreamRest::StreamRest() :
		ProtoStream(&writeSerial) {
	// TODO Auto-generated constructor stub
}

StreamRest::~StreamRest() {
	// TODO Auto-generated destructor stub
}

void StreamRest::flush(){
	String reqString;
	for(uint8_t i = 0; i< writePointer; i++){
		reqString+=buffer[i];
	}
    setRequestHeader("User-Agent", "Mozilla/5.0");
    setRequestHeader("Accept-Language", "en-US,en;q=0.5");
    setPostBody(reqString);

	writePointer = 0;
    downloadString(url, HttpClientCompletedDelegate(&StreamRest::processed, this));
}

bool StreamRest::writeByte(const char byte) {
	if (writePointer < REST_BUF)
		return false;
	buffer[writePointer];
	return writePointer++;
}

bool StreamRest::writeBytes(const char * byte, int len) {
	for (uint8_t i = 0; i < len; i++) {
		//const char byt = byte[i];
		if (!writeByte(byte[i]))
			return false;
	}
	return true;
}
