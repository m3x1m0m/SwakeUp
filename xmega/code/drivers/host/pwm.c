/*
 * pwm.c
 *
 *  Created on: 14 Nov 2016
 *      Author: maximilian
 */

#include <avr/io.h>
#include "../../util/module.h"
#include "pwm.h"

static uint8_t init(void) {
	// Set corresponding pin as output
	DDRD |= (1 << DDD6);

	// PD6 is now an output
	// set PWM for 50% duty cycle
	OCR0A = 220;

	// set none-inverting mode
	TCCR0A |= (1 << COM0A1);

	// set fast PWM Mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);

	// set prescaler to 8 and starts PWM
	TCCR0B |= (1 << CS00);

	return 1;
}

static uint8_t deinit(void) {
	// Successful
	return 1;
}

MODULE_DEFINE(PWM, "PWM", init, deinit);
