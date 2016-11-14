/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */

#define EVENT_SUPPORTS_SLEEP

#include <avr/io.h>
#include <avr/sleep.h>
#include "pin_definitions.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#include "util/module.h"
#include "util/event.h"

#include "modules/log.h"
#include "drivers/uart/terminal.h"

#include "drivers/host/uart.h"  //Breach of layering 
#include "drivers/host/timer.h" //Breach of layering 

#include "modules/screen.h"


static void callback(Event * event, uint8_t * data);

LOG_INIT("Main");

static void sleep(void) {
    sleep_cpu();
}

static void wakeUp(void) {
    sleep_disable();
    //ADCSRA = adcsra;
}

int main(void) {
#ifdef EVENT_SUPPORTS_SLEEP
    event_init(sleep, wakeUp);
    sleep_enable();
    set_sleep_mode(SLEEP_MODE_IDLE);
#endif
    LED_PORT        = 0xFF;
    SSD1306_PORT    |=  SSD1306_CS  | SSD1306_DC | (1 << 2);
    LED_DDRD        |=  LED_ERROR   | LED_SOL;
    module_init(&LOGGER);
    module_init(&TIMER);
    event_addListener(&EVENT_TIMER_1_HZ, callback);
    //module_init(&Screen);
    sei();
    while (1) {
        event_process();
    }
}

uint8_t el = 0;

static void callback(Event * event, uint8_t * data) {
    if (event == &EVENT_TIMER_1_HZ) {
        LOG_DEBUG("Timer event %d", el++);
        LED_PORT = LED_PORT ^ LED_SOL;
//         if (el == 5) {
//             LOG_ERROR("0x%x == %d", &el, 5);
//         }
    }
}

