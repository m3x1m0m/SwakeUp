/*
 * gpio.c
 *
 * Created: 3/7/2017 2:08:15 PM
 *  Author: elmar
 */

#include "gpio.h"

PORT_t * gpio_ports[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};