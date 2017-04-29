#ifndef STREAM_H_
#define STREAM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "protobuf/pb.h"
#include "protobuf/pb_encode.h"
#include "protobuf/pb_decode.h"

#include "protobuf/swakeup.pb.h"

#define MAX_IN_SIZE MsgFrame_size
#define MAX_OUT_SIZE MsgFrame_size
typedef struct stream_t Stream;

enum ProtocolState {
    PREFIX_AA, PREFIX_BB, PREFIX_CC, PREFIX_DD, SIZE_1, SIZE_2, DATAS
};

struct stream_in {
    pb_istream_t stream;
    uint8_t readBuffer[MAX_IN_SIZE];
    size_t readBufferPos;
    size_t writeBufferPos;
    uint16_t toRead;
};

struct stream_out {
    pb_ostream_t stream;
};

typedef struct stream_t {
    struct stream_out outputStream;
    struct stream_in inputStream;
    enum ProtocolState state;
    MsgFrame * msgPointer;
    uint8_t idleTimer;
} Stream;

#define STREAM_INIT(WRITEPOINTER,READPOINTER)             \
     {                                          \
        .outputStream.stream.callback = WRITEPOINTER,                   \
        .outputStream.stream.max_size = MAX_OUT_SIZE,                   \
        .inputStream.stream.callback = READPOINTER,                     \
        .inputStream.readBufferPos = 0,                                 \
        .inputStream.writeBufferPos = 0,                                \
        .inputStream.toRead = 0,                                        \
        .idleTimer = 0,                                                 \
        .msgPointer = NULL,                                             \
        .state = PREFIX_AA                                              \
    };

uint8_t stream_readCallback(pb_istream_t *stream, const pb_byte_t *buf, size_t count);
uint8_t stream_readByte(Stream * stream, uint8_t byte);
void stream_init(Stream * stream);

#ifdef __cplusplus
}
#endif

#endif /* STREAM_H_ */
