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

JOB_BUFFER_INIT(CpUartJobs, UART_MAX_JOBS);
JOB_BUFFER_INIT(EspUartJobs, UART_MAX_JOBS);

struct JobBuffer * uartBuffers[2] = {&CpUartJobs, &EspUartJobs};


EVENT_REGISTER(EVENT_UART_JOB,      "Completed UART job");
EVENT_REGISTER(EVENT_UART_DELIMITER, "Got UART delimiter");

#define UART_MAX_DELIMITERS     3
#define UART_MAX_IN_BUFFER      64
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
};

struct UartStatus uartStatus    [UART_CHANNELS];

struct UartDelimiter delimiters [UART_CHANNELS][UART_MAX_DELIMITERS];

char inBuffer                   [UART_CHANNELS][UART_MAX_IN_BUFFER];

static uint8_t sending          [UART_CHANNELS] = {0, 0};

static void _send(USART_t * port, struct JobBuffer * uartJob);

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

static uint8_t getId(USART_t * port) {
    return port == &USARTC0;
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
    uint8_t id = getId(port);
    if (job_add(uartBuffers[id], data, len, callback) == 0) {
        //LOG_ERROR("No free jobs");
        //we are full boi
        //LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    if (!sending[id]) _send(port, uartBuffers[id]);
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
    while (!((*port).STATUS & USART_DREIF_bm));
    (*port).DATA = data;
}

void uart_writes_blocked(char * data, uint8_t len, USART_t * port) {
    uint8_t i = 0;
    while (i < len) {
        /*Data buffer must be empty*/
        while (!((*port).STATUS & USART_DREIF_bm));
        /*Write character by character*/
        (*port).DATA = data[i];
        i++;
    }
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

uint8_t uart_add_delimiter(char delimiter, void(*callback)(char *, uint8_t), USART_t * port) {
    uint8_t id = getId(port);
    struct UartStatus * tempStatus = &uartStatus[id];
    if (tempStatus->delimiters_size == UART_MAX_DELIMITERS) {
        //we are full boi
        //  LOG_ERROR("No free delimiters");
        LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    struct UartDelimiter * curDelimiter = &delimiters[id][tempStatus->delimiters_head];
    curDelimiter->delimiter = delimiter;
    curDelimiter->readDelimiter = 0;
    tempStatus->delimiters_size++;
    if (tempStatus->delimiters_head++ == UART_MAX_DELIMITERS) tempStatus->delimiters_head = 0;
    return 1;
}
static inline uint8_t writeInBuf(uint8_t data, USART_t * port) {
    uint8_t id = getId(port);
    struct UartStatus * tempStatus = &uartStatus[id];
    if (tempStatus->inBuffer_size == UART_MAX_IN_BUFFER) {
        // LOG_ERROR("Uart buffer overrun");
        LED_PORT.OUTCLR = LED_PIN;
        return 0;
    }
    inBuffer[id][tempStatus->inBuffer_head] = data;
    tempStatus->inBuffer_size++;
    if (tempStatus->inBuffer_head++ == UART_MAX_DELIMITERS) tempStatus->inBuffer_head = 0;
    return 1;
}
//RX Complete interrupt service routine
// ISR(USARTC0_RXC_vect) {
//     uint8_t read = UDR0;
//     if (writeInBuf(read)) {
//         uint8_t i = 0;
//         for (; i < UART_MAX_DELIMITERS; i++) {
//             char delimitChar = delimiters[i].delimiter;
//             if (delimitChar == 0) {
//                 if (delimiters[i].readDelimiter > 0) {
//                     if (delimiters[i].tempReadDelimiter == 0) {
//                         event_fire(&EVENT_UART_DELIMITER, SYSTEM_ADDRESS_CAST & delimiters[i]);
//                     } else {
//                         delimiters[i].tempReadDelimiter--;
//                     }
//                 }
//             } else if (delimitChar == read) {
//                 event_fire(&EVENT_UART_DELIMITER, SYSTEM_ADDRESS_CAST & delimiters[i]);
//             }
//         }
//     } else {
//         //TODO buffer is full, whats next? Disable the read interrupt at least
//         UCSR0B &= ~((1 << RXEN0) | (1 << RXCIE0));
//     }
// }

static struct Job * curJob[UART_CHANNELS];

static void _send(USART_t * port, struct JobBuffer * uartJob) {
    uint8_t id = getId(port);
    sending[id] = 1;
    if (!job_get(uartJob, &curJob[id])) {
        //LOG_ERROR("Jobs is empty");
        //Error, we are trying to send but we are empty
        LED_PORT.OUTCLR = LED_PIN;
        return;
    }
    port->CTRLA               |= USART_DREINTLVL_LO_gc;
//     struct Job * currentJob = curJob[id];
//     port->DATA = currentJob->data[currentJob->i];
//     if (++currentJob->i != currentJob->len) {
//         port->CTRLA               |= USART_DREINTLVL_LO_gc;
//}
//UCSR0B |= (1 << TXEN0) | (1 << UDRIE0); //enable the interrupts!
}

//UDR0 Empty interrupt service routine

ISR(USARTE0_DRE_vect) {
    //LED_PORT.OUTCLR = LED_PIN;
    uint8_t id = getId(&CP_PORT);
    struct Job * currentJob = curJob[id];
    if (currentJob == 0) {
        return;
    }
    CP_PORT.DATA = currentJob->data[currentJob->i];
    if (++currentJob->i == currentJob->len) {
        event_fire(&EVENT_UART_JOB, SYSTEM_ADDRESS_CAST(currentJob));
        currentJob->i = 0;
        if (!job_get(uartBuffers[id], &currentJob)) {
            curJob[id] = 0;
            //disable UDR0 empty interrupt
            USARTE0.CTRLA &= ~(USART_DREINTLVL_LO_gc);
            sending[id] = 0;
        }
    }
}

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
    return 1;
}

MODULE_DEFINE(UART, "Uart", init, 0);