#ifndef STREAM_H_
#define STREAM_H_

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
    uint8_t (*flush)(struct stream_t *);
};

typedef struct stream_t {
    struct stream_out outputStream;
    struct stream_in inputStream;
    enum ProtocolState state;
    MsgFrame * msgPointer;
    uint8_t idleTimer;
} Stream;

#define STREAM_INIT(WRITEPOINTER,READPOINTER,FLUSH)             \
     {                                          \
        .outputStream.stream.callback = WRITEPOINTER,                   \
        .outputStream.stream.max_size = MAX_OUT_SIZE,                   \
        .outputStream.flush = FLUSH,                                    \
        .inputStream.stream.callback = READPOINTER,                     \
        .inputStream.readBufferPos = 0,                                 \
        .inputStream.writeBufferPos = 0,                                \
        .inputStream.toRead = 0,                                        \
        .idleTimer = 0,                                                 \
        .msgPointer = NULL,                                             \
        .state = PREFIX_AA,                                             \
    };

uint8_t stream_readCallback(pb_istream_t *stream, uint8_t *buf, size_t count);
uint8_t stream_readByte(Stream * stream, uint8_t byte);
void stream_init(Stream * stream);

#endif /* STREAM_H_ */
