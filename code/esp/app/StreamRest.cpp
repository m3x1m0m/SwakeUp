/*
 * RestStream.cpp
 *
 *  Created on: May 2, 2017
 *      Author: elmar
 */

#include "StreamRest.h"

StreamRest restStream;

static bool writeBuf(pb_ostream_t * stream __attribute__ ((unused)), const pb_byte_t *buf, size_t count) {
	// TODO this is not very nice
	StreamRest * str = (StreamRest*) stream->state;
	return str->writeBytes((char*) buf, count);
}

StreamRest::StreamRest() :
		ProtoStream(&writeBuf) {
	// TODO Auto-generated constructor stub
}

StreamRest::~StreamRest() {
	// TODO Auto-generated destructor stub
}

void StreamRest::flush() {
	String reqString;
	char numstr[4]; // enough to hold all numbers up to 64-bits
	for (int i = 0; i < writePointer; i++) {
		sprintf(numstr, "%d ", buffer[i]);
		reqString += numstr;
	}
	//TODO use binary instead
	setRequestContentType("application/x-www-form-urlencoded");
	setRequestHeader("User-Agent", "Mozilla/5.0");
	setRequestHeader("Accept-Language", "en-US,en;q=0.5");
	setPostBody(reqString);

	downloadString(url, HttpClientCompletedDelegate(&StreamRest::processed, this));
	writePointer = 0;
}

int command_arguments(char *data, int len) {
	int index = 0;
	int arguments = 0;
	while (index < len) {
		if (data[index] == ' ')
			arguments++;
		index++;
	}
	return arguments;
}

void StreamRest::processed(HttpClient& client, bool successful) {
	if (!successful) {
		return;
	}
	String responseString = client.getResponseString();
	char * respChar = (char*) responseString.c_str();
	int args = command_arguments((char *) responseString.c_str(), responseString.length());
	uint8_t * bytes = (uint8_t *) malloc(sizeof(uint8_t) * args);
	int bytesIndex = 0;
	while (*respChar) {
		if (isdigit(*respChar)) {
			bytes[bytesIndex] = strtol(respChar, &respChar, 10);
			bytesIndex++;
		} else {
			respChar++;
		}
	}

	istream = pb_istream_from_buffer(bytes, args);
	MsgFrame message;
	uint8_t status = pb_decode(&istream, MsgFrame_fields, &message);
	this->receiveCallback(&message, this);
	delete bytes;
}

bool StreamRest::writeByte(const char byte) {
	if (writePointer > REST_BUF - 1)
		return false;
	buffer[writePointer];
	return writePointer++;
}

bool StreamRest::writeBytes(const char * byte, int len) {
	for (uint8_t i = 0; i < len; i++) {
		buffer[writePointer] = byte[i];
		writePointer++;
	}
	return true;
}
