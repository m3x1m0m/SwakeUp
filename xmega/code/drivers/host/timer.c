/*
 * timer.c
 *
 * Created: 11/14/2016 1:11:06 AM
 *  Author: elmar
 */


#include <avr/interrupt.h>
#include "timer.h"
#include "../../modules/log.h"

EVENT_REGISTER(EVENT_TIMER_1_HZ, "1 second pulse");
LOG_INIT("Timer");

ISR(TIMER1_COMPA_vect) {
    event_fire(&EVENT_TIMER_1_HZ, 0);
}

static uint8_t init(void) {
    // set compare match register to desired timer count:
    OCR1A = 976;   //  1s / 1 / 1000000hZ / 1024prescaler
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    LOG_SYSTEM("Timer initialized with OCR1A(%d)", OCR1A);
}

static uint8_t deinit(void) {
}

MODULE_DEFINE(TIMER, "Timer", init, deinit);