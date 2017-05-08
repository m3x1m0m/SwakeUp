/*
 * StreamWebsocket.h
 *
 *  Created on: May 3, 2017
 *      Author: elmar
 */

#ifndef APP_STREAMWEBSOCKET_H_
#define APP_STREAMWEBSOCKET_H_

#include <SmingCore/Network/WebsocketClient.h>
#include "ProtoStream.h"

class StreamWebsocket {
public:
	StreamWebsocket();
	void connect();
	void sendMsg();
	virtual ~StreamWebsocket();
private:
	WebsocketClient websockClient;
};

#endif /* APP_STREAMWEBSOCKET_H_ */
