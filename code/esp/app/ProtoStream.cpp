/*
 * ProtoStream.cpp
 *
 *  Created on: Apr 28, 2017
 *      Author: elmar
 */

#include "ProtoStream.h"

static const pb_byte_t startDelimitation[] = { 0xAA, 0xBB, 0xCC, 0xDD };

ProtoStream::ProtoStream(t_write_callback write_callback) {
	ostream.callback = write_callback;
	ostream.max_size = 128;
	// TODO Auto-generated constructor stub
}

void ProtoStream::writeMessage(MsgFrame frame) {
	size_t size;
	pb_get_encoded_size(&size, MsgFrame_fields, &frame);
	ostream.bytes_written = 0; //TODO this should not be required
	const pb_byte_t tempSize[] = { static_cast<pb_byte_t>((size) & 0xFF),
			static_cast<pb_byte_t>((size >> 8) & 0xFF) };
	ostream.callback(&ostream, startDelimitation, 4);
	ostream.callback(&ostream, tempSize, 2);
	pb_encode(&ostream, MsgFrame_fields, &frame);
	Serial.printf("PB size: %d error: %s \r\n", size, ostream.errmsg);
	flush();
}
void ProtoStream::flush(){

}
bool ProtoStream::processByte(uint8_t byte) {
	switch (state) {
	case PREFIX_AA:
		if (byte == 0xAA) {
			state = PREFIX_BB;
		} else if (byte == 0xBB) {
			state = PREFIX_CC;
		} else {
			//TODO
		}
		break;
	case PREFIX_BB:
		if (byte == 0xBB) {
			state = PREFIX_CC;
		} else {
			state = PREFIX_AA;
			//TODO
		}
		break;
	case PREFIX_CC:
		if (byte == 0xCC) {
			state = PREFIX_DD;
		} else {
			state = PREFIX_AA;
			//TODO
		}
		break;
	case PREFIX_DD:
		if (byte == 0xDD) {
			state = SIZE_1;
		} else {
			//logErrorExpected(0xDD, byte);
			state = PREFIX_AA;
		}
		break;
	case SIZE_1:
		toRead = byte;
		state = SIZE_2;
		break;
	case SIZE_2: {
		uint8_t temp1 = toRead;
		uint8_t temp2 = byte;
		toRead = (temp1) | temp2 << 8;
		state = DATAS;
		if (toRead > MAX_IN_SIZE) {
			//LOG_ERROR("Max input-size exceeded"); TODO
			return false;
		}
	}
		break;
	case DATAS:
		readBuffer[writeBufferPos] = byte;
		writeBufferPos++;
		if (writeBufferPos >= toRead) {
			istream = pb_istream_from_buffer(readBuffer, toRead);
			state = PREFIX_AA;
			return true;
		}
		break;
	}
	return false;
}

ProtoStream::~ProtoStream() {
	// TODO Auto-generated destructor stub
}

