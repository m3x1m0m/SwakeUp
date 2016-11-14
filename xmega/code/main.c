/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */

#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "util/module.h"
#include "util/event.h"

#include "drivers/host/uart.h"  //Breach of layering 
#include "drivers/host/timer.h" //Breach of layering 

#include "modules/screen.h"
#include "pin_definitions.h"

static void callback(Event * event, uint8_t * data);

const static char strin[6] = "Hallo\n";

int main(void) {
    SSD1306_PORT |=  SSD1306_CS  | SSD1306_DC | (1 << 2);
    module_init(&UART);
    module_init(&TIMER);
    //module_init(&Screen);
    sei();
    uart_job(strin, sizeof(strin), 0);
    event_addListener(&EVENT_UART_JOB, callback);
    event_addListener(&EVENT_TIMER_1_HZ, callback);
    while (1) {
        event_process();
    }
}


static void callback(Event * event, uint8_t * data) {
    if (event == &EVENT_UART_JOB) {
        //toggle led
    } else if (event == &EVENT_TIMER_1_HZ) {
        uart_job(strin, sizeof(strin), 0);
    }
}