/*
 * ProtoStream.h
 *
 *  Created on: Apr 28, 2017
 *      Author: elmar
 */

#ifndef APP_STREAMS_PROTOSTREAM_H_
#define APP_STREAMS_PROTOSTREAM_H_

#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "swakeup.pb.h"

#define MAX_IN_SIZE MsgFrame_size
#define MAX_OUT_SIZE MsgFrame_size

typedef bool (t_write_callback)(pb_ostream_t * stream __attribute__ ((unused)), const pb_byte_t *buf, size_t count);

class ProtoStream {
public:
	ProtoStream(t_write_callback write_callback);
	void writeMessage(MsgFrame frame);
	virtual ~ProtoStream();
protected:
	enum ProtocolState {
		PREFIX_AA, PREFIX_BB, PREFIX_CC, PREFIX_DD, SIZE_1, SIZE_2, DATAS
	};
	ProtocolState state = PREFIX_AA;
	bool processByte(uint8_t byte);
private:
	pb_istream_t istream;
	uint8_t readBuffer[MAX_IN_SIZE];
	size_t readBufferPos = 0;
	size_t writeBufferPos = 0;
	uint16_t toRead = 0;
	pb_ostream_t ostream;
};

#endif /* APP_STREAMS_PROTOSTREAM_H_ */
