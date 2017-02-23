/*
* uart.c
*
* Created: 11/9/2016 12:37:41 AM
*  Author: elmar
*/

#include "../../pin_definitions.h"
#include "../uart/terminal.h"
#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

static const char _bufOverRun[] = "\n\r Uart buffer overrun \n\r";
static const char _emptyJob[] = "\n\r No more jobs \n\r";
static const char _fullJob[] = "\n\r Jobs are full \n\r";
static const char _zeroJob[] = "\n\r Zero job \n\r";

JOB_BUFFER_INIT(CpUartJobs, 0);                 //Debug uart doesnt use jobs, but a direct buffer
JOB_BUFFER_INIT(EspUartJobs, UART_MAX_JOBS);

struct JobBuffer * uartBuffers[2] = {&CpUartJobs, &EspUartJobs};

EVENT_REGISTER(EVENT_UART_JOB,      "Completed UART job");
EVENT_REGISTER(EVENT_UART_DELIMITER, "Got UART delimiter");

#define UART_MAX_DELIMITERS     3
#define UART_CHANNELS           2

struct UartStatus {
    uint8_t delimiters_head;
    uint8_t delimiters_tail;
    uint8_t delimiters_size;
    uint8_t inBuffer_head;
    uint8_t inBuffer_tail;
    uint8_t inBuffer_size;
    uint8_t outBuffer_head;
    uint8_t outBuffer_tail;
    uint8_t outBuffer_size;
};

volatile struct UartStatus uartStatus    [UART_CHANNELS] = {{0}, {0}};

struct UartDelimiter delimiters [UART_CHANNELS][UART_MAX_DELIMITERS];

char inBuffer                   [UART_CHANNELS][UART_MAX_IN_BUFFER];

char outBuffer                  [UART_CHANNELS][UART_MAX_OUT_BUFFER];

volatile uint8_t outBufferLock  [UART_CHANNELS] = {{0}, {0}};

volatile static uint8_t sending          [UART_CHANNELS] = {0, 0};

#define lock(id) while (outBufferLock[id]); outBufferLock[id] = 1
#define unlock(id) outBufferLock[id] = 0

inline uint8_t softlock(uint8_t id) {
    if (outBufferLock[id]) return 0;
    outBufferLock[id] = 1;
    return 1;
}

//static void _send(USART_t * port, struct JobBuffer * uartJob);
#define USARTE_ID 0

#define USARTC_ID 1

static inline uint8_t getId(USART_t * port) {
    return port == &USARTC0;
}

uint8_t uart_buffer_out_level(USART_t * port) {
    return uartStatus[getId(port)].outBuffer_size;
}

void uart_speed(UART_BAUDRATE baudrate, USART_t * port) {
    switch (baudrate) {
    case B2400:
        break;
    case B4800:
        port->BAUDCTRLA = 3317;
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


uint8_t uart_job(char * data, uint8_t len, void (* callback)(struct Job *), USART_t * port) {
    uart_writes_blocked(data, len, port);
    event_fire(&EVENT_UART_JOB, (uint8_t*)port);//(uint8_t *) callback);
    return 1;
}

uint8_t uart_write(char * data, uint8_t len, USART_t * port) {
    uint8_t id = getId(port), written = 0;
    while (written < len) {
        if (uartStatus[id].outBuffer_size >= UART_MAX_OUT_BUFFER) return written;
        outBuffer[id][uartStatus[id].outBuffer_head] = data[written];
        uartStatus[id].outBuffer_head = (uartStatus[id].outBuffer_head + 1 >= UART_MAX_OUT_BUFFER) ? 0 : uartStatus[id].outBuffer_head + 1;
        uartStatus[id].outBuffer_size++;
        if (!sending[id]) {
            port->CTRLA |= USART_DREINTLVL0_bm;
            // sending[id] = 1; //TODO implement this ?
        }
        written++;
    }
    return written;
}

#define UART_THRESHOLD 16

uint8_t uart_writes(char data, USART_t * port) {
    uint8_t id = getId(port);
    while (uartStatus[id].outBuffer_size >= UART_MAX_OUT_BUFFER - 1); // TODO make this nicer
    lock(id);
    outBuffer[id][uartStatus[id].outBuffer_head] = data;
    uartStatus[id].outBuffer_head = (uartStatus[id].outBuffer_head + 1 >= UART_MAX_OUT_BUFFER) ? 0 : uartStatus[id].outBuffer_head + 1;
    uartStatus[id].outBuffer_size++;
    if (!sending[id]) {
        port->CTRLA |= USART_DREINTLVL0_bm;
        // sending[id] = 1; //TODO implement this ?
    }
    unlock(id);
    return 1;
}

uint8_t uart_buffer_level(USART_t * port) {
    struct UartStatus * tempStatus = &uartStatus[getId(port)];
    if (tempStatus->inBuffer_head < tempStatus->inBuffer_tail) {
        return UART_MAX_IN_BUFFER;
    }
    return 0;
}

void uart_write_blocked(char data, USART_t * port) {
    register8_t backUp =  port->CTRLA;
    port->CTRLA &= ~USART_DREINTLVL_LO_gc;
    (*port).DATA = data;
    while (!((*port).STATUS & USART_DREIF_bm));
    port->CTRLA = backUp;
}

void uart_writes_blocked(char * data, uint8_t len, USART_t * port) {
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

char uart_reads_blocked(USART_t * port) {
    while (!((*port).STATUS & USART_RXCIF_bm));
    return (*port).DATA;
}

uint8_t uart_read_buffer(char * data, uint8_t len, USART_t * port) {
    uint8_t id = getId(port);
    uint8_t l = 0;
    while (l < len && uartStatus[id].inBuffer_size > 0) {
        data[l] = inBuffer[id][uartStatus[id].inBuffer_tail];
        if (++uartStatus[id].inBuffer_tail == UART_MAX_IN_BUFFER) uartStatus[id].inBuffer_tail = 0;
        uartStatus[id].inBuffer_size--;
    }
    return l;
}

uint8_t uart_reads_buffer(char * data, USART_t * port) {
    uint8_t id = getId(port);
    if (uartStatus[id].inBuffer_size == 0) return 0;
    (*data) = inBuffer[id][uartStatus[id].inBuffer_tail];
    if (++uartStatus[id].inBuffer_tail == UART_MAX_IN_BUFFER) uartStatus[id].inBuffer_tail = 0;
    uartStatus[id].inBuffer_size--;
    return 1;
}

void uart_flush_buffer(USART_t * port) {
    uint8_t id = getId(port);
}

uint8_t uart_add_delimiter(char delimiter, USART_t * port) {
    uint8_t id = getId(port);
    struct UartStatus * tempStatus = &uartStatus[id];
    if (tempStatus->delimiters_size == UART_MAX_DELIMITERS) {
        //we are full
        //  LOG_ERROR("No free delimiters");
        LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    struct UartDelimiter * curDelimiter = &delimiters[id][tempStatus->delimiters_head];
    curDelimiter->delimiter = delimiter;
    curDelimiter->length = 0;
    tempStatus->delimiters_size++;
    if (tempStatus->delimiters_head++ == UART_MAX_DELIMITERS) tempStatus->delimiters_head = 0;
    return 1;
}
void uart_delimiter_handled(struct UartDelimiter * delimiter) {
    delimiter->length = 0;
}
static inline uint8_t writeInBuf(uint8_t data, USART_t * port) {
    uint8_t id = getId(port);
    struct UartStatus * tempStatus = &uartStatus[id];
    if (tempStatus->inBuffer_size == UART_MAX_IN_BUFFER) {
        //LOG_ERROR("UART buffer overrun");
        //LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    inBuffer[id][tempStatus->inBuffer_head] = data;
    tempStatus->inBuffer_size++;
    if (++tempStatus->inBuffer_head == UART_MAX_IN_BUFFER) tempStatus->inBuffer_head = 0;
    return 1;
}

ISR(USARTE0_RXC_vect) {
    uint8_t read = USARTE0.DATA;
    if (writeInBuf(read, &USARTE0)) {
        uint8_t i = 0;
        for (; i < UART_MAX_DELIMITERS; i++) {
            if (delimiters[USARTE_ID][i].delimiter != 0) {
                delimiters[USARTE_ID][i].length++;
                if (read == delimiters[USARTE_ID][i].delimiter) {
                    delimiters[USARTE_ID][i].port = &USARTE0;
                    event_fire(&EVENT_UART_DELIMITER, SYSTEM_ADDRESS_CAST (&delimiters[USARTE_ID][i]));
                }
            }
        }
    } else {
        //TODO buffer is full, whats next? Disable the read interrupt at least
        CP_PORT.CTRLA &= ~(USART_RXCINTLVL_LO_gc);
    }
}

ISR(USARTE0_DRE_vect) {
    uint8_t size = uartStatus[USARTE_ID].outBuffer_size;
    if (size > 0) {
        if (softlock(USARTE_ID)) {
            uint8_t tail = uartStatus[USARTE_ID].outBuffer_tail;
            //uint8_t head = uartStatus[USARTE_ID].outBuffer_head;
            USARTE0.DATA = outBuffer[USARTE_ID][tail];
            uartStatus[USARTE_ID].outBuffer_size--;
            tail++;
            if (tail >= UART_MAX_OUT_BUFFER) tail = 0;
            uartStatus[USARTE_ID].outBuffer_tail = tail;
            unlock(USARTE_ID);
        }
    } else {
        sending[USARTE_ID] = 0;
        USARTE0.CTRLA &= ~(USART_DREINTLVL0_bm);
    }
}

const static char _initialized[] = "\n\nUART initialized\n\r";

static uint8_t init(void) {
    uartStatus[USARTE_ID].outBuffer_head = 1;
    uartStatus[USARTC_ID].outBuffer_head = 1;
    ESP_UART_PIN_PORT.REMAP     = PORT_USART0_bm;
    ESP_UART_PIN_PORT.OUT       = ESP_UART_TX;
    ESP_UART_PIN_PORT.DIRSET    = ESP_UART_RX;
    //ESP_UART_PORT.CTRLA         = USART_RXCINTLVL_LO_gc;
    ESP_UART_PORT.CTRLB         = USART_RXEN_bm |  USART_TXEN_bm;
    ESP_UART_PORT.CTRLC         = USART_CHSIZE_8BIT_gc;
    uart_speed(B9600, &ESP_UART_PORT);
    CP_PIN_PORT.DIRCLR          = CP_RX_PIN;
    CP_PIN_PORT.DIRSET          = CP_TX_PIN;
    CP_PIN_PORT.OUTCLR          = CP_RX_PIN;
    CP_PIN_PORT.OUTSET          = CP_TX_PIN;
    CP_PORT.CTRLA               = USART_RXCINTLVL_MED_gc;
    CP_PORT.CTRLB               = USART_RXEN_bm |  USART_TXEN_bm;
    CP_PORT.CTRLC               = USART_CHSIZE_8BIT_gc;
    uart_speed(B115200, &CP_PORT);
    uart_writes_blocked(_initialized, sizeof(_initialized), &DEBUG_UART);
    return 1;
}

MODULE_DEFINE(UART, "Uart", init, 0);