/*
 * StreamWifi.h
 *
 *  Created on: Apr 29, 2017
 *      Author: elmar
 */

#ifndef APP_STREAMWIFI_H_
#define APP_STREAMWIFI_H_

#include "ProtoStream.h"
#include <string.h>

class StreamWifi : public ProtoStream {
public:
	StreamWifi();
	bool connect(String ssid, String pass);
	bool writeByte(const char byte);
	bool writeBytes(const char * byte, int len);
	bool onReceive(TcpClient& client, char *data, int size);
	virtual ~StreamWifi();
private:
	TcpClient client;
};

//extern StreamWifi wifiStream;

#endif /* APP_STREAMWIFI_H_ */
