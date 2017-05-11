/*
* uart.c
*
* Created: 11/9/2016 12:37:41 AM
*  Author: elmar
*/

#include "../../pin_definitions.h"
#include "../uart/terminal.h"
#include "../../util/stream.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

static const char _bufOverRun[] = "\n\r Uart buffer overrun \n\r";
static const char _emptyJob[] = "\n\r No more jobs \n\r";
static const char _fullJob[] = "\n\r Jobs are full \n\r";
static const char _zeroJob[] = "\n\r Zero job \n\r";
static const char _noImpl[] = "\n\r Not implemented \n\r";

JOB_BUFFER_INIT(CpUartJobs, 0);                 //Debug uart doesnt use jobs, but a direct buffer
JOB_BUFFER_INIT(EspUartJobs, UART_MAX_JOBS);

struct JobBuffer * uartBuffers[2] = {&CpUartJobs, &EspUartJobs};

EVENT_REGISTER(EVENT_UART_JOB,      "Completed UART job");
EVENT_REGISTER(EVENT_UART_DELIMITER, "Got UART delimiter");

#define UART_MAX_DELIMITERS     3
#define UART_CHANNELS           2

struct UartStatus {
    void (*callback)(char);
    struct UartBuffer delimiterBuffer;
    struct UartBuffer inBuffer;
    struct UartBuffer outBuffer;
};

static struct UartStatus uartStatus    [UART_CHANNELS] = {{0}, {0}};

static struct UartDelimiter delimiters [UART_CHANNELS][UART_MAX_DELIMITERS];

static char inBuffer                   [UART_CHANNELS][UART_MAX_IN_BUFFER];

static char outBuffer                  [UART_CHANNELS][UART_MAX_OUT_BUFFER];

static volatile uint8_t outBufferLock  [UART_CHANNELS] = {0, 0};

static volatile uint8_t sending        [UART_CHANNELS] = {0, 0};

#define lock(id) while (outBufferLock[id]); outBufferLock[id] = 1
#define unlock(id) outBufferLock[id] = 0

static inline uint8_t softlock(uint8_t id) {
    if (outBufferLock[id]) return 0;
    outBufferLock[id] = 1;
    return 1;
}

//static void _send(USART_t * port, struct JobBuffer * uartJob);
#define ESP_ID  0

#define CP_ID   1

static inline uint8_t getId(const USART_t * const port) {
#ifdef REV_1
    return port == &USARTE0;    //port == CP_ID
#endif
#ifdef REV_2
    return port == &USARTD1;    //port == CP_ID
#endif
}

uint8_t uart_buffer_out_level(const USART_t * const port) {
    return uartStatus[getId(port)].outBuffer.size;
}

uint8_t uart_buffer_in_level(const USART_t * const port) {
    return uartStatus[getId(port)].inBuffer.size;
}

void uart_speed(UART_BAUDRATE baudrate, USART_t * port) {
    switch (baudrate) {
    case B2400:
        break;
    case B4800:
        port->BAUDCTRLA = 207;
        port->BAUDCTRLB = -4;
        break;
    case B9600:
        port->BAUDCTRLA = 103;
        port->BAUDCTRLB = 0;
        break;
    case B38400:
        port->BAUDCTRLA = 25;
        port->BAUDCTRLB = 0;
        break;
    case B115200:
        port->BAUDCTRLA = 8;
        port->BAUDCTRLB = 0;
        break;
    }
}


uint8_t uart_job(char * data, uint8_t len, void (* callback)(struct Job *), USART_t * const port) {
    (void)callback; //TODO make this working again, or remove it
    uart_writes_blocked(_noImpl, sizeof(_noImpl), &DEBUG_UART);
    uart_writes_blocked(data, len, port);
    event_fire(&EVENT_UART_JOB, (uint8_t*)port);//(uint8_t *) callback);
    return 1;
}

static inline void incr_wrap(struct UartBuffer * buffer, uint8_t max) {
    buffer->head = (buffer->head + 1 >= max) ? 0 : buffer->head + 1;
    buffer->size++;
}

uint8_t uart_write(const char * const data, uint8_t len, USART_t * const port) {
    uint8_t id = getId(port), written = 0;
    while (written < len) {
        if (uartStatus[id].outBuffer.size >= UART_MAX_OUT_BUFFER) return written;
        lock(id);
        outBuffer[id][uartStatus[id].outBuffer.head] = data[written];
        incr_wrap(&uartStatus[id].outBuffer, UART_MAX_OUT_BUFFER);
        if (!sending[id]) {
            port->CTRLA |= USART_DREINTLVL0_bm;
            // sending[id] = 1; //TODO implement this ?
        }
        written++;
        unlock(id);
    }
    return written;
}

#define UART_THRESHOLD 16

uint8_t uart_writes(char data, USART_t * const port) {
    uint8_t id = getId(port);
    while (uartStatus[id].outBuffer.size >= UART_MAX_OUT_BUFFER - 1); // TODO make this nicer
    lock(id);
    outBuffer[id][uartStatus[id].outBuffer.head] = data;
    incr_wrap(&uartStatus[id].outBuffer, UART_MAX_OUT_BUFFER);
    if (!sending[id]) {
        port->CTRLA |= USART_DREINTLVL0_bm;
        // sending[id] = 1; //TODO implement this ?
    }
    unlock(id);
    return 1;
}

uint8_t uart_buffer_level(const USART_t * port) {
    struct UartStatus * tempStatus = (struct UartStatus*)&uartStatus[getId(port)];
    if (tempStatus->inBuffer.head < tempStatus->inBuffer.tail) {
        return UART_MAX_IN_BUFFER;
    }
    return 0;
}

void uart_write_blocked(const char data, USART_t * port) {
    register8_t backUp =  port->CTRLA;
    port->CTRLA &= ~USART_DREINTLVL_LO_gc;
    (*port).DATA = data;
    while (!((*port).STATUS & USART_DREIF_bm));
    port->CTRLA = backUp;
}

void uart_writes_blocked(const char * data, uint8_t len, USART_t * const port) {
    register8_t backUp =  port->CTRLA;
    port->CTRLA &= ~USART_DREINTLVL_LO_gc;
    uint8_t i = 0;
    while (i < len) {
        /*Write character by character*/
        (*port).DATA = data[i];
        i++;
        /*Data buffer must be empty*/
        while (!((*port).STATUS & USART_DREIF_bm));
    }
    port->CTRLA = backUp;
}

uint8_t uart_read_blocked(char * data, uint8_t len, USART_t * port) {
    uint8_t readLen = 0;
    /*Clue character to character*/
    while (readLen < len) {
        while (!((*port).STATUS & USART_RXCIF_bm));
        data[readLen] = (*port).DATA;
        readLen++;
    }
    return readLen;
}

char uart_reads_blocked(const USART_t * const port) {
    while (!((*port).STATUS & USART_RXCIF_bm));
    return (*port).DATA;
}

uint8_t uart_read_buffer(char * data, uint8_t len, USART_t * port) {
    uint8_t id = getId(port);
    uint8_t l = 0;
    while (l < len && uartStatus[id].inBuffer.size > 0) {
        data[l] = inBuffer[id][uartStatus[id].inBuffer.tail];
        if (++uartStatus[id].inBuffer.tail == UART_MAX_IN_BUFFER) uartStatus[id].inBuffer.tail = 0;
        uartStatus[id].inBuffer.size--;
    }
    return l;
}

uint8_t uart_reads_buffer(char * data, USART_t * port) {
    uint8_t id = getId(port);
    if (uartStatus[id].inBuffer.size == 0) return 0;
    (*data) = inBuffer[id][uartStatus[id].inBuffer.tail ];
    if (++uartStatus[id].inBuffer.tail  == UART_MAX_IN_BUFFER) uartStatus[id].inBuffer.tail  = 0;
    uartStatus[id].inBuffer.size--;
    return 1;
}

void uart_flush_buffer(USART_t * port) {
    (void)port; // TODO this can be used!
    uart_writes_blocked(_noImpl, sizeof(_noImpl), &DEBUG_UART);
    //uint8_t id = getId(port);
}

uint8_t uart_add_delimiter(char delimiter, USART_t * port) {
    uint8_t id = getId(port);
    struct UartStatus * tempStatus = (struct UartStatus *)&uartStatus[id];
    if (tempStatus->delimiterBuffer.size == UART_MAX_DELIMITERS) {
        //we are full
        //  LOG_ERROR("No free delimiters");
        LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    struct UartDelimiter * curDelimiter = &delimiters[id][tempStatus->delimiterBuffer.head];
    curDelimiter->delimiter = delimiter;
    curDelimiter->length = 0;
    tempStatus->delimiterBuffer.size++;
    if (tempStatus->delimiterBuffer.size++ == UART_MAX_DELIMITERS) tempStatus->delimiterBuffer.head = 0;
    return 1;
}
void uart_delimiter_handled(struct UartDelimiter * delimiter) {
    delimiter->length = 0;
}
static inline uint8_t writeInBuf(uint8_t data, USART_t * port) {
    uint8_t id = getId(port);
    struct UartStatus * tempStatus = (struct UartStatus*)&uartStatus[id];
    if (tempStatus->inBuffer.size == UART_MAX_IN_BUFFER) {
        //LOG_ERROR("UART buffer overrun");
        //LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    inBuffer[id][tempStatus->inBuffer.head] = data;
    tempStatus->inBuffer.size++;
    if (++tempStatus->inBuffer.head == UART_MAX_IN_BUFFER) tempStatus->inBuffer.head = 0;
    tempStatus->callback(data);
    return 1;
}

#define USARTRXCISR(NAME, PORT, USART_ID)            \
ISR(NAME##_RXC_vect) {                             \
    uint8_t read = PORT.DATA;                    \
    if (writeInBuf(read, &PORT)) {               \
        uint8_t i = 0;                              \
        for (; i < UART_MAX_DELIMITERS; i++) {      \
            if (delimiters[USART_ID][i].delimiter != 0) {  \
                delimiters[USART_ID][i].length++;          \
                if (read == delimiters[USART_ID][i].delimiter) {   \
                    delimiters[USART_ID][i].port = &PORT;       \
                    event_fire(&EVENT_UART_DELIMITER, SYSTEM_ADDRESS_CAST (&delimiters[USART_ID][i])); \
                }   \
            }   \
        }   \
        } else {/*buffer full */    \
        CP_PORT.CTRLA &= ~(USART_RXCINTLVL_LO_gc);  \
    }   \
}

#define USARTDREISR(NAME, PORT, USART_ID)\
ISR(NAME##_DRE_vect) {             \
    uint8_t size = uartStatus[USART_ID].outBuffer.size;    \
    if (size > 0) { \
        if (softlock(USART_ID)) {\
            uint8_t tail = uartStatus[USART_ID].outBuffer.tail;\
            PORT.DATA = outBuffer[USART_ID][tail];  \
            uartStatus[USART_ID].outBuffer.size--; \
            tail++; \
            if (tail >= UART_MAX_OUT_BUFFER) tail = 0;\
            uartStatus[USART_ID].outBuffer.tail = tail;\
            unlock(USART_ID);  \
        }\
        } else {\
        sending[USART_ID] = 0;\
        PORT.CTRLA &= ~(USART_DREINTLVL0_bm);\
    }\
}

static void emptyCallback(char data __attribute__ ((unused))) {
}

void uart_set_callback(void (*callback)(char), USART_t * const port) {
    uartStatus[getId(port)].callback = callback;
}

struct UartBuffer * getInBuffer(USART_t * const port) {
    return &uartStatus[getId(port)].inBuffer;
}
struct UartBuffer * getOutBuffer(USART_t * const port) {
    return &uartStatus[getId(port)].outBuffer;
}

#ifdef REV_1
USARTRXCISR(USARTE0, DEBUG_UART,     CP_ID);
USARTDREISR(USARTE0, DEBUG_UART,     CP_ID);
USARTRXCISR(USARTD1, ESP_UART_PORT,  ESP_ID);
USARTDREISR(USARTD1, ESP_UART_PORT,  ESP_ID);
#endif
#ifdef REV_2
USARTRXCISR(USARTD1, DEBUG_UART,     CP_ID);
USARTDREISR(USARTD1, DEBUG_UART,     CP_ID);
USARTRXCISR(USARTC0, ESP_UART_PORT,  ESP_ID);
USARTDREISR(USARTC0, ESP_UART_PORT,  ESP_ID);
#endif
static const char _initialized[] = "\fUART initialized\n\r";

static uint8_t init(void) {
    uartStatus[ESP_ID].outBuffer.head = 0;
    uartStatus[CP_ID].outBuffer.head = 0;
    uart_set_callback(emptyCallback, &ESP_UART_PORT);
    uart_set_callback(emptyCallback, &CP_PORT);
    ESP_UART_PIN_PORT.DIRCLR          = ESP_UART_RX;
    ESP_UART_PIN_PORT.OUTCLR          = ESP_UART_RX;
    ESP_UART_PIN_PORT.DIRSET          = ESP_UART_TX;
    ESP_UART_PIN_PORT.OUTSET          = ESP_UART_TX;
#ifdef REV_1
    ESP_UART_PIN_PORT.REMAP           = PORT_USART0_bm;
#endif
    ESP_UART_PORT.CTRLA         = USART_RXCINTLVL_LO_gc;
    ESP_UART_PORT.CTRLB         = USART_RXEN_bm |  USART_TXEN_bm;
    ESP_UART_PORT.CTRLC         = USART_CHSIZE_8BIT_gc;
    uart_speed(B115200, &ESP_UART_PORT);
    CP_PIN_PORT.DIRCLR          = CP_RX_PIN;
    CP_PIN_PORT.DIRSET          = CP_TX_PIN;
    CP_PIN_PORT.OUTCLR          = CP_RX_PIN;
    CP_PIN_PORT.OUTSET          = CP_TX_PIN;
#ifdef REV_2
    CP_PIN_PORT.REMAP           = PORT_USART0_bm;
#endif
    DEBUG_UART.CTRLA               = USART_RXCINTLVL_MED_gc;
    DEBUG_UART.CTRLB               = USART_RXEN_bm |  USART_TXEN_bm;
    DEBUG_UART.CTRLC               = USART_CHSIZE_8BIT_gc;
    uart_speed(B115200, &CP_PORT);
    uart_writes_blocked(_initialized, sizeof(_initialized), &DEBUG_UART);
    return 1;
}

MODULE_DEFINE(UART, "Uart", init, 0);
