/*
 * uart.c
 *
 * Created: 11/9/2016 12:37:41 AM
 *  Author: elmar
 */

#include "uart.h"
#include "../../util/job.h"
#include <avr/io.h>
#include <avr/interrupt.h>

JOB_BUFFER_INIT(UartJobs, UART_MAX_JOBS);
EVENT_REGISTER(EVENT_UART_JOB,      "Completed UART job");
EVENT_REGISTER(EVENT_UART_DELIMITER, "Got UART delimiter");

#define UART_MAX_DELIMITERS     3
#define UART_MAX_IN_BUFFER      64

struct UartDelimiter {
    char delimiter;
    uint8_t readDelimiter;
    uint8_t tempReadDelimiter;
};

struct UartDelimiter delimiters [UART_MAX_DELIMITERS];
uint8_t delimiters_head         = 0;
uint8_t delimiters_tail         = 0;
uint8_t delimiters_size         = 0;

char inBuffer                   [UART_MAX_IN_BUFFER];
uint8_t inBuffer_head           = 0;
uint8_t inBuffer_tail           = 0;
uint8_t inBuffer_size           = 0;

static uint8_t sending          = 0;

static void _send();

#define F_CPU 1000000
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

void uart_speed(UART_BAUDRATE baudrate) {
    switch (baudrate) {
    case B2400:
        UBRR0L  = 51;
        break;
    case B4800:
        UBRR0L  = 25;
        break;
    case B9600:
        UBRR0L  = 12;
        break;
    }
}


uint8_t uart_job(char * data, uint8_t len, void (* callback)(void)) {
    if (job_add(&UartJobs, data, len, callback) == 0) {
        //we are full boi
        return 0;
    }
    if (!sending) _send();
    return 1;
}

uint8_t uart_buffer_level(void) {
    if (inBuffer_head < inBuffer_tail) {
        return UART_MAX_IN_BUFFER;
    }
    return 0;
}

void uart_write_blocked(char * data, uint8_t len) {
    uint8_t i = 0;
    while (i < len) {
        /*Data buffer must be empty*/
        while (!(UCSR0A & (1 << UDRE0)));
        /*Write character by character*/
        UDR0 = data[i];
        i++;
    }
}

uint8_t uart_read_blocked(char * data, uint8_t len) {
    uint8_t readLen = 0;
    /*Clue character to character*/
    while (readLen < len) {
        while (!(UCSR0A & (1 << RXC0)));
        data[readLen] = UDR0;
        readLen++;
    }
    return readLen;
}

uint8_t uart_add_delimiter(char delimiter, void(*callback)(char *, uint8_t)) {
    if (delimiters_size == UART_MAX_DELIMITERS) {
        //we are full boi
        return 0;
    }
    struct UartDelimiter * curDelimiter = &delimiters[delimiters_head];
    curDelimiter->delimiter = delimiter;
    curDelimiter->readDelimiter = 0;
    delimiters_size++;
    if (delimiters_head++ == UART_MAX_DELIMITERS) delimiters_head = 0;
    return 1;
}
static inline uint8_t writeInBuf(uint8_t data) {
    if (inBuffer_size == UART_MAX_IN_BUFFER) {
        //we are full boi
        return 0;
    }
    inBuffer[inBuffer_head] = data;
    inBuffer_size++;
    if (inBuffer_head++ == UART_MAX_DELIMITERS) inBuffer_head = 0;
    return 1;
}
//RX Complete interrupt service routine
ISR(USART_RX_vect) {
    uint8_t read = UDR0;
    if (writeInBuf(read)) {
        uint8_t i = 0;
        for (; i < UART_MAX_DELIMITERS; i++) {
            char delimitChar = delimiters[i].delimiter;
            if (delimitChar == 0) {
                if (delimiters[i].readDelimiter > 0) {
                    if (delimiters[i].tempReadDelimiter == 0) {
                        event_fire(&EVENT_UART_DELIMITER, SYSTEM_ADDRESS_CAST & delimiters[i]);
                    } else {
                        delimiters[i].tempReadDelimiter--;
                    }
                }
            } else if (delimitChar == read) {
                event_fire(&EVENT_UART_DELIMITER, SYSTEM_ADDRESS_CAST & delimiters[i]);
            }
        }
    } else {
        //TODO buffer is full, whats next? Disable the read interrupt at least
        UCSR0B &= ~((1 << RXEN0) | (1 << RXCIE0));
    }
}

static struct Job * curJob = 0;

static void _send() {
    sending = 1;
    if (!job_get(&UartJobs, &curJob)) {
        //Error, we are trying to send but we are empty
        return;
    }
    UCSR0B |= (1 << TXEN0) | (1 << UDRIE0); //enable the interrupts!
}

//UDR0 Empty interrupt service routine
ISR(USART_UDRE_vect) {
    if (curJob == 0) {
        //Error!
        return;
    }
    UDR0 = curJob->data[curJob->i];
    if (curJob->i++ == curJob->len) {
        event_fire(&EVENT_UART_JOB, SYSTEM_ADDRESS_CAST curJob);
        if (!job_get(&UartJobs, curJob)) {
            curJob = 0;
            //disable transmission and UDR0 empty interrupt
            UCSR0B &= ~((1 << TXEN0) | (1 << UDRIE0));
        }
    }
}

static uint8_t init(void) {
    uart_speed(B9600);
    UCSR0A |= 1 << U2X0;
    UCSR0B |= (1 << RXEN0)  | (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0);  // Enable receiver and transmitter, also interrupts
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);                                // Set frame: 8data, 1 stp
    return 1;
}

MODULE_DEFINE(UART, "Uart", init, 0);