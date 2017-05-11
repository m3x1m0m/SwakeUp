/*
 * StreamXmega.h
 *
 *  Created on: Apr 28, 2017
 *      Author: elmar
 */

#ifndef APP_STREAMS_STREAMXMEGA_H_
#define APP_STREAMS_STREAMXMEGA_H_

#include "ProtoStream.h"

class StreamXmega : public ProtoStream{
public:
	StreamXmega();
	void init(void);
	void onReceive(Stream& stream, char arrivedChar, unsigned short availableCharsCount);
	virtual ~StreamXmega();
};
extern StreamXmega xmegaStream;
#endif /* APP_STREAMS_STREAMXMEGA_H_ */
