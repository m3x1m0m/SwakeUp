/*
 * pwm.c
 *
 *  Created on: May 4, 2017
 *      Author: maximilian
 */

#include <avr/io.h>
#include "../../util/module.h"
#include "pwm.h"

void init()
{
}

void init_PWMRed(uint16_t period){
	// Configuring timer TCD0
	PORTD.DIR |= PWM_RED;
	TCD0.PER = period;
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;			// No prescaling
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc;		// Single slope
	TCD0.CTRLB |= TC0_CCAEN_bm;					// Activate channel A (red)
}

void setPeriod_PWMRed(uint16_t period){
	if(period < MIN_PERIOD)
		period = 3;
	TCD0.PER = period;
}

void setDutyCycle_PWMRed(uint16_t cycle){
	if(cycle < 0)
		cycle = 0;
	TCD0.CCABUF = cycle;
	while( (TCD0.INTFLAGS &&  0x01) == 0);
	TCD0.INTFLAGS = 0x00;
}

static uint8_t init(void) {
	// Initialize all PWM channels needed
	init_PWMRed(1024);
	return 1;
}

static uint8_t deinit(void) {
	return 1;
}

MODULE_DEFINE(PWM, "PWM", init, deinit);
