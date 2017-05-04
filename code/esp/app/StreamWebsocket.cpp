/*
 * StreamWebsocket.cpp
 *
 *  Created on: May 3, 2017
 *      Author: elmar
 */

#include "StreamWebsocket.h"

StreamWebsocket::StreamWebsocket() {

	//websockClient.disconnect();

}
void StreamWebsocket::connect(){

	websockClient.connect("ws://enigmatic-savannah-85833.herokuapp.com/websocket");
}
void StreamWebsocket::sendMsg(){
	websockClient.sendMessage("TEST123");
}

StreamWebsocket::~StreamWebsocket() {
	// TODO Auto-generated destructor stub
}

