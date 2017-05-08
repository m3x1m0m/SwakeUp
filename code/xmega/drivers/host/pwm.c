/*
 * pwm.c
 *
 *  Created on: May 4, 2017
 *      Author: maximilian
 */

#include <avr/io.h>
#include "../../util/module.h"
#include "pwm.h"

/////////////////////////////////////////////////////////////////////////////////
// Timer TCD0 functions
/////////////////////////////////////////////////////////////////////////////////

void setPeriod_TCD0(uint16_t period){
	period+=1;
	if(period < PWM_MIN_PERIOD)
		period = PWM_MIN_PERIOD;
	HIRESD.CTRLA |= HIRES_HREN0_bm | HIRES_HRPLUS_bm ;					// Activate high resolution plus mode 
	TCD0.PER = period-(period%8);										// Avoid that the last two bits are set
																		// Acc. to the datasheet this is necessary for proper operation
}

uint16_t getPeriod_TCD0(){
	return TCD0.PER;
}

/////////////////////////////////////////////////////////////////////////////////
// Timer TCD1 functions
/////////////////////////////////////////////////////////////////////////////////

void setPeriod_TCD1(uint16_t period){
	if(period < PWM_MIN_PERIOD)
	period = PWM_MIN_PERIOD;
	HIRESD.CTRLA |= HIRES_HREN1_bm | HIRES_HRPLUS_bm ;					// Activate high resolution plus mode
	TCD1.PER = period-(period%8);										// Avoid that the last two bits are set
																		// Acc. to the datasheet this is necessary for proper operation
}

uint16_t getPeriod_TCD1(){
	return TCD1.PER;
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_RED, TC0A
/////////////////////////////////////////////////////////////////////////////////

void init_PWMRed(uint16_t period){
	// Configuring timer TCD0 and compare channel A
	PORTD.DIRSET |= PWM_RED;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period 
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCAEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;				
	setDutyCycle_PWMRed(PWM_INIT_CYCLE);								             
}

void setDutyCycle_PWMRed(uint16_t cycle){
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0_CCABUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC1_OVFIF_bm;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_BLUE, TC0B
/////////////////////////////////////////////////////////////////////////////////

void init_PWMBlue(uint16_t period){
	// Configuring timer TCD0 and compare channel B
	PORTD.DIRSET |= PWM_BLUE;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCBEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMBlue(PWM_INIT_CYCLE);								
}

void setDutyCycle_PWMBlue(uint16_t cycle){
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0_CCBBUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC0_OVFIF_bm;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_GREEN, TC0C
/////////////////////////////////////////////////////////////////////////////////

void init_PWMGreen(uint16_t period){
	// Configuring timer TCD0 and compare channel B
	PORTD.DIRSET |= PWM_GREEN;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCCEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMGreen(PWM_INIT_CYCLE);
}

void setDutyCycle_PWMGreen(uint16_t cycle){
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0.CCCBUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC0_OVFIF_bm;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_OLED, TC0C
/////////////////////////////////////////////////////////////////////////////////

void init_PWMOLED(uint16_t period){
	// Configuring timer TCD0 and compare channel B
	PORTD.DIRSET |= PWM_OLED;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCDEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMOLED(PWM_INIT_CYCLE);
}

void setDutyCycle_PWMOLED(uint16_t cycle){
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0.CCDBUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC0_OVFIF_bm;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////

static uint8_t init(void) {
	// Initialize all PWM channels needed
	init_PWMRed(PWM_FREQ_500KHZ);
	init_PWMBlue(PWM_FREQ_500KHZ);
	init_PWMGreen(PWM_FREQ_500KHZ);
	init_PWMOLED(PWM_FREQ_500KHZ);
	return 1;
}

static uint8_t deinit(void) {
	return 1;
}

MODULE_DEFINE(PWM, "PWM", &init, &deinit);
