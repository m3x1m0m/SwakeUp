/*
 * uart.h
 *
 * Created: 11/9/2016 12:37:33 AM
 *  Author: elmar
 */


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#include "../../util/event.h"
#include "../../util/module.h"
#include "../../util/job.h"

EVENT_EXP(EVENT_UART_JOB);
EVENT_EXP(EVENT_UART_DELIMITER);

#define UART_MAX_DELIMITERS     3
#define UART_MAX_IN_BUFFER      128
#define UART_MAX_OUT_BUFFER     128
#define UART_MAX_JOBS           4

//TODO move this struct to the C
struct UartDelimiter {
    USART_t * port;
    char delimiter;
    uint8_t length;
};

typedef enum {
    B115200, B38400, B9600, B4800, B2400
} UART_BAUDRATE;

void uart_speed(UART_BAUDRATE baudrate, USART_t * port);
uint8_t uart_job(char * data, uint8_t len, void (* callback)(struct Job *), USART_t * port);
uint8_t uart_write(const char * const data, uint8_t len, USART_t * const port);
uint8_t uart_writes(const char data, USART_t * const port);
uint8_t uart_buffer_out_level(const USART_t * const port);
uint8_t uart_buffer_in_level(const USART_t * const port);
void uart_write_blocked(char data, USART_t * const port);
void uart_writes_blocked(const char * const data, uint8_t len, USART_t * const port);
uint8_t uart_read_blocked(char * data, uint8_t len, USART_t * const port);
char uart_reads_blocked(const USART_t * const port);
uint8_t uart_read_buffer(char * data, uint8_t len, USART_t * const port);
uint8_t uart_reads_buffer(char * data, USART_t * const port);
uint8_t uart_add_delimiter(char delimiter, USART_t * const port);
void uart_delimiter_handled(struct UartDelimiter * delimiter);
MODULE_EXP(UART);

#endif /* UART_H_ */