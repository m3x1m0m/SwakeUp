/*
 * log.c
 *
 * Created: 11/14/2016 1:08:09 PM
 *  Author: elmar
 */

#include <avr/io.h>
#include "../pin_definitions.h"
#include <util/delay.h>
#include "log.h"
#include "../drivers/uart/terminal.h"
#include "../drivers/host/uart.h"

LOG_INIT("Logger")

void log_error() {
    while (1) {
        LED_PORT = LED_PORT ^ LED_ERROR;
        _delay_ms(500);
    }
}

void log_message(const char * format, ...) {
    va_list arg;
    va_start (arg, format);
    terminal_format_force(format, arg);
    va_end (arg);
}

void callback(Event * event, uint8_t * data) {
    event_removeListener(&EVENT_UART_JOB, callback);
    LOG_SYSTEM("Logger initialized");
}

uint8_t init(void) {
    event_addListener(&EVENT_UART_JOB, callback);
    return 1;
}

uint8_t deinit(void) {
    event_removeListener(&EVENT_UART_JOB, callback);
    return 1;
}


MODULE_DEFINE(LOGGER, "Logging", init, deinit, &TERMINAL);