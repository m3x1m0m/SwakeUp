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

float setFrequency_PWMRed(float frequency){
	uint16_t period = 0;
	uint16_t alternative1 = 0;
	uint16_t alternative2 = 0;
	
	if( (frequency > PWM_MAX_FREQ) || (frequency < PWM_MIN_FREQ) )
		return 1;
	period = (uint16_t)( (float)(PWM_MAX_FREQ*8) / frequency  -1 );
	if( (period % 8) != 0){
		alternative1 = period + (period % 8);
		alternative2 = period - (period % 8);
		if( abs(period - alternative1) < abs(period - alternative2)){
			if( (alternative1 > PWM_MAX_PERIOD) )
				period = alternative2;
			else
				period = alternative1;
		}
		else{
			if( (alternative2 < PWM_MIN_PERIOD) )
				period = alternative1;
			else
				period = alternative2;
		}
	}
	setPeriod_PWMRed(period);
	return ( (float)PWM_MAX_FREQ * 8) / ( (float)period + 1.0 );
}

static uint8_t init(void) {
	// Initialize all PWM channels needed
	//pwm_init();
	init_PWMRed(PWM_FREQ_500KHZ);
	return 1;
}

static uint8_t deinit(void) {
	return 1;
}

MODULE_DEFINE(PWM, "PWM", &init, &deinit);
