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

void log_error() {
    while (1) {
        LED_PORT = LED_PORT ^ LED_ERROR;
        _delay_ms(500);
    }
}