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

//class ProtoStream;

typedef bool (t_write_callback)(pb_ostream_t * stream __attribute__ ((unused)), const pb_byte_t *buf, size_t count);
typedef void (*t_msg_callback)(MsgFrame * frame, void * receiver);

class ProtoStream {
public:
	ProtoStream(t_write_callback write_callback);
	void writeMessage(MsgFrame * frame);
	void setMsgCallback(t_msg_callback callback);
	virtual ~ProtoStream();
protected:
	virtual void flush();
	;bool processByte(uint8_t byte);
	enum ProtocolState {
		PREFIX_AA, PREFIX_BB, PREFIX_CC, PREFIX_DD, SIZE_1, SIZE_2, DATAS
	};
	t_msg_callback receiveCallback;
	ProtocolState state = PREFIX_AA;
	pb_ostream_t ostream;
	pb_istream_t istream;
private:
	uint8_t readBuffer[MAX_IN_SIZE];
	size_t readBufferPos = 0;
	size_t writeBufferPos = 0;
	uint16_t toRead = 0;
};

#endif /* APP_STREAMS_PROTOSTREAM_H_ */
