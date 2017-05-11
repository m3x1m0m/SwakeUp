/////////////////////////////////////////////////////////////////////////////////
// PWM driver for the ATxmega128A4U with high extension resolution plus 
// (x8 the input freq. of the system clock).
// 
// Author:				Maximilian Stiefel
// Last Modification:	10.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdarg.h>
#include "../../util/module.h"
#include "../../modules/log.h"
#include "pwm.h"
#include "../../pin_definitions.h"

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////
#define WORKING

/////////////////////////////////////////////////////////////////////////////////
// Timer TCD0 functions
/////////////////////////////////////////////////////////////////////////////////
void setPeriod_TCD0(uint16_t period)
{
	if(period < PWM_MIN_PERIOD)
		period = PWM_MIN_PERIOD;
	HIRESD.CTRLA |= HIRES_HREN0_bm | HIRES_HRPLUS_bm ;					// Activate high resolution plus mode 
	TCD0.PER = period-(period%8);										// Avoid that the last two bits are set
																		// Acc. to the datasheet this is necessary for proper operation
}

uint16_t getPeriod_TCD0()
{
	return TCD0.PER;
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_RED, TC0A
/////////////////////////////////////////////////////////////////////////////////
void init_PWMRed(uint16_t period)
{
	// Configuring timer TCD0 and compare channel A
	PORTD.DIRSET |= PWM_RED;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period 
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCAEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;				
	setDutyCycle_PWMRed(PWM_INIT_CYCLE);								             
}

void setDutyCycle_PWMRed(uint16_t cycle)
{
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0.CCABUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC1_OVFIF_bm;
	}
}

uint16_t getDutyCycle_PWMRed(void)
{
	return TCD0.CCA;
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_BLUE, TC0B
/////////////////////////////////////////////////////////////////////////////////
void init_PWMBlue(uint16_t period)
{
	// Configuring timer TCD0 and compare channel B
	PWM_PORT.DIRSET |= PWM_BLUE;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCBEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMBlue(PWM_INIT_CYCLE);								
}

void setDutyCycle_PWMBlue(uint16_t cycle)
{
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0.CCBBUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC0_OVFIF_bm;
	}
}

uint16_t getDutyCycle_PWMBlue(void)
{
	return TCD0.CCB;
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_GREEN, TC0C
/////////////////////////////////////////////////////////////////////////////////
void init_PWMGreen(uint16_t period)
{
	// Configuring timer TCD0 and compare channel B
	PWM_PORT.DIRSET |= PWM_GREEN;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCCEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMGreen(PWM_INIT_CYCLE);
}

void setDutyCycle_PWMGreen(uint16_t cycle)
{
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0.CCCBUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC0_OVFIF_bm;
	}
}

uint16_t getDutyCycle_PWMGreen(void)
{
	return TCD0.CCC;
}

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_OLED, TC0C
/////////////////////////////////////////////////////////////////////////////////
void init_PWMOLED(uint16_t period)
{
	// Configuring timer TCD0 and compare channel B
	PWM_PORT.DIRSET |= PWM_OLED;											// Set the port PWM_RED as output
	setPeriod_TCD0(period);												// Set period
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC0_CCDEN_bm;				// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMOLED(PWM_INIT_CYCLE);
}

void setDutyCycle_PWMOLED(uint16_t cycle)
{
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD0.CCDBUF = cycle;
		while( !(TCD0.INTFLAGS & TC0_OVFIF_bm) );
		TCD0.INTFLAGS &= ~TC0_OVFIF_bm;
	}
}

uint16_t getDutyCycle_PWMOLED(void)
{
	return TCD0.CCD; 
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
#ifdef WORKING
static uint8_t init(int num, ...)
{
	init_PWMRed(PWM_FREQ_16KHZ);
	init_PWMBlue(PWM_FREQ_16KHZ);
	init_PWMGreen(PWM_FREQ_16KHZ);
	init_PWMOLED(PWM_FREQ_16KHZ);
	return 1;
}
#else
static uint8_t init(int num, ...)
{
	// Variables
	va_list arguments;
	
	// Action
	va_start(arguments, sum);					// Start variable arguments list
	for(int i = 0; i< num, i++)
	{
		channel = va_arg(arguments, char);
	}
	init_PWMRed(PWM_FREQ_16KHZ);
	init_PWMBlue(PWM_FREQ_16KHZ);
	init_PWMGreen(PWM_FREQ_16KHZ);
	init_PWMOLED(PWM_FREQ_16KHZ);
	return 1;
}
#endif

static uint8_t deinit(void) 
{
	return 1;
}

MODULE_DEFINE(PWM, "PWM", &init, &deinit);
