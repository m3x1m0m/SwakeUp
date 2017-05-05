/*
 * pwm.c
 *
 *  Created on: May 4, 2017
 *      Author: maximilian
 */

#include <avr/io.h>
#include "../../util/module.h"
#include "pwm.h"

void init_PWMRed(uint16_t period){
	// Configuring timer TCD0
	PORTD.DIRSET |= PWM_RED;											// Set the port PWM_RED as output
	setPeriod_PWMRed(period);											// Set period 
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC1_CCAEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	HIRESD.CTRLA |= HIRES_HREN0_bm | HIRES_HRPLUS_bm ;									
	setDutyCycle_PWMRed(INIT_DUTY_CYCLE);								// Initialize with 5% duty cycle               
}

void init_PWMGreen(uint16_t period){
	
}

void setPeriod_PWMRed(uint16_t period){
	if(period < MIN_PERIOD)
		period = MIN_PERIOD;
	TCD0.PER = period-(period%8);										// Avoid that the last two bits are set
																		// Acc. to the datasheet this is necessary for proper operation
}

void setDutyCycle_PWMRed(float cycle){
	uint16_t period = 0;
	if( !(cycle > 100) && !(cycle < 0) ){ 
		period = TCD0.PER;
		TCD0_CCABUF = ( (uint16_t)( ( cycle/100 ) * (float)( period+1 ) ) );
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC1_OVFIF_bm;
	}
}

static uint8_t init(void) {
	// Initialize all PWM channels needed
	init_PWMRed(PWM_FREQ_500KHZ);
	return 1;
}

static uint8_t deinit(void) {
	return 1;
}

MODULE_DEFINE(PWM, "PWM", &init, &deinit);
