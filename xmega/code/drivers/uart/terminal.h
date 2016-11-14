/*
 * terminal.h
 *
 * Created: 11/14/2016 2:46:57 PM
 *  Author: elmar
 */


#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <stdint.h>
#include <stdarg.h>
#include "../../util/module.h"

#define TERMINAL_MAX_LINE   32
#define TERMINAL_LINES      4

uint8_t terminal_write(char * format, ...);
void terminal_write_force(char * format, ...);
void terminal_write_block(char * format, ...);

uint8_t terminal_format(char *fmt, va_list va);
void terminal_format_force(char *fmt, va_list va);
void terminal_format_blocking(char *fmt, va_list va);

void terminal_format_buffer(char *fmt, va_list va);

void terminal_putc(char c);
void terminal_flush(void);
char terminal_getc(void);
uint8_t terminal_level_in(void);

MODULE_EXP(TERMINAL);

#endif /* TERMINAL_H_ */