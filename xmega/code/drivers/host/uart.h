/*
 * uart.h
 *
 * Created: 11/9/2016 12:37:33 AM
 *  Author: elmar
 */ 


#ifndef UART_H_
#define UART_H_

#include "../../util/event.h"

#ifndef FOSC
#define FOSC 16000000UL
#warning "Warning FOSC not defined for usart.h."
#endif

#define UART_MAX_DELIMITERS		3
#define UART_MAX_IN_BUFFER		64
#define UART_MAX_JOBS			4

#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)


typedef enum{
	B9600, B38400
} UART_BAUDRATE;

void uart_init(UART_BAUDRATE baudrate);
uint8_t uart_job(char * data, uint8_t len, void (* callback)(void));
uint8_t uart_buffer_level(void);
void uart_write_blocked(char * data, uint8_t len);
uint8_t uart_read_blocked(char * data, uint8_t len);
uint8_t uart_add_delimiter(char delimiter, void(*callback)(char *, uint8_t));

#endif /* UART_H_ */