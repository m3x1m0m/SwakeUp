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

typedef enum {
    B115200, B38400, B9600, B4800, B2400
} UART_BAUDRATE;



void uart_speed(UART_BAUDRATE baudrate, USART_t * port);
uint8_t uart_job(char * data, uint8_t len, void (* callback)(struct Job *), USART_t * port);
uint8_t uart_write(char * data, uint8_t len, uint8_t * eventData, USART_t * port);
uint8_t uart_writes(char data, uint8_t * eventData, USART_t * port);
uint8_t uart_buffer_out_level(USART_t * port);
void uart_write_blocked(char data, USART_t * port);
void uart_writes_blocked(char * data, uint8_t len, USART_t * port);
uint8_t uart_read_blocked(char * data, uint8_t len, USART_t * port);
uint8_t uart_add_delimiter(char delimiter, void(*callback)(char *, uint8_t), USART_t * port);

MODULE_EXP(UART);

#endif /* UART_H_ */