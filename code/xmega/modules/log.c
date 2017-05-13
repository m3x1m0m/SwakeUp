/*
 * log.c
 *
 * Created: 11/14/2016 1:08:09 PM
 *  Author: elmar
 */

#include <avr/io.h>
#include "../pin_definitions.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "log.h"
#include "../drivers/uart/terminal.h"
#include "../drivers/host/uart.h"

LOG_INIT("Logger")

enum LOG_DISPLAY log_display = DEFAULT_LOG_FORMAT;

void log_error() {
    while (uart_buffer_out_level(&DEBUG_UART)); //Write our message
    cli();  //disable interrupts
    while (1) {
        LED_PORT.OUTTGL = LED_PIN;
        _delay_ms(100);
    }
}

void log_set_display(enum LOG_DISPLAY disp) {
    log_display = disp;
}

void (*log_current_sink(void))(void *, char ) {
    return terminal_current_sink();
}
void log_redirectOutput(void (*sink) (void*, char)) {
    terminal_set_sink(sink);
}

void log_defaultOutput(void) {
    terminal_default_sink();
}

void log_message(const char * format, ...) {
    va_list arg;
    va_start (arg, format);
    terminal_format(format, arg);
    va_end (arg);
}

void log_message_p(const char * format, ...) {
    va_list arg;
    va_start (arg, format);
    terminal_format_p(format, arg);
    va_end (arg);
}

uint8_t init(void) {
    LOG_SYSTEM("Logger initialized");
    return 1;
}
uint8_t deinit(void) {
    return 1;
}
MODULE_DEFINE(LOGGER, "Logging", init, deinit, &TERMINAL);