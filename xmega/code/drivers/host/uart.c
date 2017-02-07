/*
* uart.c
*
* Created: 11/9/2016 12:37:41 AM
*  Author: elmar
*/

#include "../../pin_definitions.h"

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

struct UartDelimiter {
    char delimiter;
    uint8_t readDelimiter;
    uint8_t tempReadDelimiter;
};

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

struct UartStatus uartStatus    [UART_CHANNELS] = {{0}, {0}};

struct UartDelimiter delimiters [UART_CHANNELS][UART_MAX_DELIMITERS];

char inBuffer                   [UART_CHANNELS][UART_MAX_IN_BUFFER];

char outBuffer                  [UART_CHANNELS][UART_MAX_OUT_BUFFER];

static uint8_t sending          [UART_CHANNELS] = {0, 0};

//static void _send(USART_t * port, struct JobBuffer * uartJob);

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

#define USARTE_ID 0
#define USARTC_ID 1

static uint8_t getId(USART_t * port) {
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
        port->BAUDCTRLA = 123;
        port->BAUDCTRLB = -4;
        break;
    }
}


uint8_t uart_job(char * data, uint8_t len, void (* callback)(struct Job *), USART_t * port) {
    uart_writes_blocked(data, len, port);
    event_fire(&EVENT_UART_JOB, (uint8_t*)port);//(uint8_t *) callback);
    return 1;
}

uint8_t uart_write(char * data, uint8_t * len, uint8_t * eventData, USART_t * port) {
    uint8_t id = getId(port);
    uint8_t originLen = *len, l = *len, i = 0;
    uint8_t spaceFree = UART_MAX_OUT_BUFFER - uartStatus[id].outBuffer_size;
    *len = 0;
    if (originLen > spaceFree) {
        l = spaceFree;
    }
    for (; i < l; i++) {
        outBuffer[id][uartStatus[id].outBuffer_head] = data[i];
        uartStatus[id].outBuffer_head = (uartStatus[id].outBuffer_head + 1 >= UART_MAX_OUT_BUFFER) ? 0 : uartStatus[id].outBuffer_head + 1;
        uartStatus[id].outBuffer_size++;
        *len++;
    }
    if (!sending[id]) {
        port->CTRLA |= USART_DREINTLVL0_bm;
        // sending[id] = 1; //TODO implement this ?
    }
    return *len == originLen;
}

#define UART_THRESHOLD 16

uint8_t uart_writes(char data, uint8_t * eventData, USART_t * port) {
    uint8_t id = getId(port);
    while (uartStatus[id].outBuffer_size == UART_MAX_OUT_BUFFER);   // TODO make this nicer
    //if (uartStatus[id].outBuffer_size == UART_MAX_OUT_BUFFER) return 0;
    outBuffer[id][uartStatus[id].outBuffer_head] = data;
    uartStatus[id].outBuffer_head = (uartStatus[id].outBuffer_head + 1 >= UART_MAX_OUT_BUFFER) ? 0 : uartStatus[id].outBuffer_head + 1;
    uartStatus[id].outBuffer_size++;
    if (!sending[id]) {
        port->CTRLA |= USART_DREINTLVL0_bm;
        // sending[id] = 1; //TODO implement this ?
    }
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


ISR(USARTE0_DRE_vect) {
    uint8_t size = uartStatus[USARTE_ID].outBuffer_size;
    if (size > 0) {
        uint8_t tail = uartStatus[USARTE_ID].outBuffer_tail;
        //uint8_t head = uartStatus[USARTE_ID].outBuffer_head;
        USARTE0.DATA = outBuffer[USARTE_ID][tail];
        uartStatus[USARTE_ID].outBuffer_size--;
        if (++tail == UART_MAX_OUT_BUFFER) tail = 0;
        uartStatus[USARTE_ID].outBuffer_tail = tail;
    } else {
        sending[USARTE_ID] = 0;
        USARTE0.CTRLA &= ~(USART_DREINTLVL0_bm);
    }
}

const static char _initialized[] = "\n\nUART initialized\n\r";

static uint8_t init(void) {
    ESP_UART_PIN_PORT.REMAP     = PORT_USART0_bm;
    ESP_UART_PIN_PORT.OUT       = ESP_UART_TX;
    ESP_UART_PIN_PORT.DIRSET    = ESP_UART_RX;
    ESP_UART_PORT.CTRLA         = USART_RXCINTLVL_LO_gc;
    ESP_UART_PORT.CTRLB         = USART_RXEN_bm |  USART_TXEN_bm;
    ESP_UART_PORT.CTRLC         = USART_CHSIZE_8BIT_gc;
    uart_speed(B9600, &ESP_UART_PORT);
    CP_PIN_PORT.OUT             = CP_TX_PIN;
    CP_PIN_PORT.DIRSET          = CP_TX_PIN;
    CP_PORT.CTRLA               = USART_RXCINTLVL_LO_gc;
    CP_PORT.CTRLB               = USART_RXEN_bm |  USART_TXEN_bm;
    CP_PORT.CTRLC               = USART_CHSIZE_8BIT_gc;
    uart_speed(B38400, &CP_PORT);
    uart_writes_blocked(_initialized, sizeof(_initialized), &DEBUG_UART);
    return 1;
}

MODULE_DEFINE(UART, "Uart", init, 0);