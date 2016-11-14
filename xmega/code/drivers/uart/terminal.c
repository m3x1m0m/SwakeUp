/*
 * terminal.c
 *
 * Created: 11/14/2016 2:46:45 PM
 *  Author: elmar
 */
#include "terminal.h"
#include "../host/uart.h"
#include "../../util/event.h"
#include "../../util/job.h"
#include "../../modules/log.h"
#include "../../tinyprint/printf.h"

#include <stdarg.h>

LOG_INIT("Terminal");

static uint8_t buffer[TERMINAL_LINES][TERMINAL_MAX_LINE];
static uint8_t characterIndex[TERMINAL_LINES];
static uint8_t sendStatus[TERMINAL_LINES];
static uint8_t currentLine = 0;


static void write_block(void * p, char c) {
    uart_write_blocked(c);
}
static void write(void * p, char c) {
    terminal_putc(c);
}
uint8_t terminal_write(char * format, ...) {
    if (sendStatus[currentLine]) return 0;
    init_printf((void*)0, write);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, write, format, arg);
    va_end(arg);
    return 1;
}

void terminal_write_force(char * format, ...) {
    while (sendStatus[currentLine]) {
        event_process();
    }
    init_printf((void*)0, write);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, write, format, arg);
    va_end(arg);
}

uint8_t terminal_format(char *fmt, va_list va) {
    if (sendStatus[currentLine]) return 0;
    init_printf((void*)0, write);
    tfp_format(0, write, fmt, va);
    return 1;
}

void terminal_format_force(char *fmt, va_list va) {
    while (sendStatus[currentLine]) {
        event_process();
    }
    init_printf((void*)0, write);
    tfp_format(0, write, fmt, va);
}

void terminal_format_blocking(char *fmt, va_list va) {
    init_printf((void*)0, write_block);
    tfp_format(0, write_block, fmt, va);
}

void terminal_write_block(char * format, ...) {
    init_printf((void*)0, write_block);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, write_block, format, arg);
    va_end(arg);
}

void terminal_putc(char c) {
    if (sendStatus[currentLine]) {
        uint8_t tempLine = (currentLine + 1 == TERMINAL_LINES) ? 0 : currentLine + 1;
        if (characterIndex[tempLine] < TERMINAL_MAX_LINE - 1) {
            //we are sending, but next line is free
            currentLine = tempLine;
            buffer[currentLine][characterIndex[currentLine]++] = c;
            //todo check if c == \n
            return;
        } else {
            //we are sending and everything else is full
            while (sendStatus[currentLine]) {
                event_process();
            }
            //once we are not sending anymore we resume normally
        }
    }
    buffer[currentLine][characterIndex[currentLine]] = c;
    if (++characterIndex[currentLine] == TERMINAL_MAX_LINE) {
        terminal_flush();  //We are filled up
    } else if (c == '\n') terminal_flush();
}

void terminal_flush(void) {
    if (sendStatus[currentLine] == 1) return; //we are already sending what we can
    sendStatus[currentLine] = 1;
    uart_job(buffer[currentLine], characterIndex[currentLine], 0);
    if (++currentLine == TERMINAL_LINES) {
        currentLine = 0;
    }
}


char terminal_getc(void) {
}

uint8_t terminal_level_in(void) {
}

static void callback(Event * event, uint8_t * data) {
    if (event == &EVENT_UART_JOB) {
        struct Job * job = (struct Job *)data;
        for (uint8_t i = 0; i < TERMINAL_LINES; i++) {
            if (buffer[i] == job->data) {
                characterIndex[i] = 0;
                sendStatus[i] = 0;
                break;
            }
        }
    }
}

static void initalizeCallback(Event * event, uint8_t * data) {
    LOG_SYSTEM("Uart set up");
    event_removeListener(&EVENT_UART_JOB, initalizeCallback);
}

static uint8_t init(void) {
    for (uint8_t i = 0; i < TERMINAL_LINES; i++) {
        characterIndex[i] = 0;
    }
    event_addListener(&EVENT_UART_JOB, callback);
    event_addListener(&EVENT_UART_JOB, initalizeCallback);
    return 1;
}

static uint8_t deinit(void) {
    event_removeListener(&EVENT_UART_JOB, callback);
    event_removeListener(&EVENT_UART_JOB, initalizeCallback);
    return 1;
}

MODULE_DEFINE(TERMINAL, "Uart terminal", init, deinit, &UART);
