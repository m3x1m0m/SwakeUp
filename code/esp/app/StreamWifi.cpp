/*
 * StreamWifi.cpp
 *
 *  Created on: Apr 29, 2017
 *      Author: elmar
 */

#include "StreamWifi.h"

//StreamWifi wifiStream;

static bool writeSerial(pb_ostream_t * stream __attribute__ ((unused)),
		const pb_byte_t *buf, size_t count) {
	return 1;//wifiStream.writeBytes((char*) buf, count);
}

StreamWifi::StreamWifi() :
		ProtoStream(&writeSerial), client(true){
				//TcpClientDataDelegate(&StreamWifi::onReceive, &wifiStream)) {
}

bool StreamWifi::onReceive(TcpClient& client, char *data, int size) {
	int i = 0;
	for (; i < size; i++) {
		processByte(data[i]);
	}
	return true;
}

bool StreamWifi::writeByte(const char byte) {
	return client.write(&byte, 1, 0) == 1;
}

bool StreamWifi::writeBytes(const char * byte, int len) {
	return client.write(byte, len, 0) == len;
}

StreamWifi::~StreamWifi() {
	// TODO Auto-generated destructor stub
}

