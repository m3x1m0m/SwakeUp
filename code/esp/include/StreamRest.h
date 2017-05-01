/*
 * RestStream.h
 *
 *  Created on: May 2, 2017
 *      Author: elmar
 */

#ifndef APP_RESTSTREAM_H_
#define APP_RESTSTREAM_H_

#include "ProtoStream.h"
#include <string.h>

#define REST_BUF 128

class StreamRest : public ProtoStream, protected HttpClient {
public:
	StreamRest();
	bool writeByte(const char byte);
	void flush() override;
	bool writeBytes(const char * byte, int len);
	void processed(HttpClient& client, bool successful)		{
	}
	virtual ~StreamRest();
private:
	const char *url = "http://enigmatic-savannah-85833.herokuapp.com/swakeup";
	int writePointer = 0;
	uint8_t buffer[128];	//TODO this can be abottleneck
};
extern StreamRest restStream;
#endif /* APP_RESTSTREAM_H_ */
