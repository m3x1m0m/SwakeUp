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

uint8_t terminal_write(char * format, ...);
void terminal_write_force(char * format, ...);
void terminal_write_block(char * format, ...);

uint8_t terminal_format(const char *fmt, va_list va);
uint8_t terminal_format_p(const char *fmt, va_list va);
void terminal_format_blocking(const char *fmt, va_list va);

void terminal_format_buffer(char *fmt, va_list va);

void terminal_putc(char c);
void terminal_flush(void);
char terminal_getc(void);

void terminal_default_sink(void);
void terminal_set_sink(void (*putcf) (void*, char));
void (*terminal_current_sink(void))(void *, char );

MODULE_EXP(TERMINAL);

#endif /* TERMINAL_H_ */