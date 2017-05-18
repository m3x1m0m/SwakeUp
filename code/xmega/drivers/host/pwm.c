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
#include "../../util/module.h"
#include "../../modules/log.h"
#include "../../pin_definitions.h"
#include "../../modules/command.h"
#include "pwm.h"

LOG_INIT("PWM");

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////

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

#ifdef REV_1
/////////////////////////////////////////////////////////////////////////////////
// Timer TCD1 functions
/////////////////////////////////////////////////////////////////////////////////
void setPeriod_TCD1(uint16_t period)
{
	if(period < PWM_MIN_PERIOD)
	period = PWM_MIN_PERIOD;
	HIRESD.CTRLA |= HIRES_HREN1_bm | HIRES_HRPLUS_bm ;					// Activate high resolution plus mode
	TCD1.PER = period-(period%8);										// Avoid that the last two bits are set
	// Acc. to the datasheet this is necessary for proper operation
}

uint16_t getPeriod_TCD1()
{
	return TCD1.PER;
}
#endif


/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_RED, TCD0A
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
// Functions for PWM_GREEN, TCD0C/TCD1A
/////////////////////////////////////////////////////////////////////////////////
#ifdef REV_1
void init_PWMGreen(uint16_t period)
{
	// Configuring timer TCD0 and compare channel B
	PWM_PORT.DIRSET |= PWM_GREEN;										// Set the port PWM_RED as output
	setPeriod_TCD1(period);												// Set period
	TCD1.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC1_CCAEN_bm;				// Single slope PWM and TCD1 enable
	TCD1.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMGreen(PWM_INIT_CYCLE);
}

void setDutyCycle_PWMGreen(uint16_t cycle)
{
	uint16_t period = 0;
	period = getPeriod_TCD0();
	if (cycle < period){
		TCD1.CCABUF = cycle;
		while( !(TCD1.INTFLAGS & TC1_OVFIF_bm) );
		TCD1.INTFLAGS &= ~TC1_OVFIF_bm;
	}
}

uint16_t getDutyCycle_PWMGreen(void)
{
	return TCD1.CCA;
}
#endif 

#ifdef REV_2
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
#endif

/////////////////////////////////////////////////////////////////////////////////
// Functions for PWM_OLED, TCD0D/TCD1B
/////////////////////////////////////////////////////////////////////////////////
#ifdef REV_1
void init_PWMOLED(uint16_t period)
{
	// Configuring timer TCD0 and compare channel B
	PWM_PORT.DIRSET |= PWM_OLED;										// Set the port PWM_RED as output
	setPeriod_TCD1(period);												// Set period
	TCD1.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | TC1_CCBEN_bm;				// Single slope PWM and TCD0 enable
	TCD1.CTRLA |= TC_CLKSEL_DIV1_gc;
	setDutyCycle_PWMOLED(PWM_INIT_CYCLE);
}

void setDutyCycle_PWMOLED(uint16_t cycle)
{
	uint16_t period = 0;
	period = getPeriod_TCD1();
	if (cycle < period){
		TCD1.CCBBUF = cycle;
		while( !(TCD1.INTFLAGS & TC1_OVFIF_bm) );
		TCD1.INTFLAGS &= ~TC1_OVFIF_bm;
	}
}

uint16_t getDutyCycle_PWMOLED(void)
{
	return TCD1.CCB;
}
#endif

#ifdef REV_2
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
#endif
/////////////////////////////////////////////////////////////////////////////////
// Terminal commands for debugging
/////////////////////////////////////////////////////////////////////////////////
static void pwmCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
	uint8_t index = 1;
	uint16_t cycle;
	char channel = data[index];
	LOG_DEBUG("Channel: %c", channel);
	cycle = command_next_int(&index, data, len);
	switch(channel){
		case 'R':
		LOG_DEBUG("Cycle: %d", cycle);
		LOG_DEBUG("Apply new settings to PWM_RED.");
		setDutyCycle_PWMRed(cycle);
		break;
		case 'B':
		LOG_DEBUG("Cycle: %d", cycle);
		LOG_DEBUG("Apply new settings to PWM_BLUE.");
		setDutyCycle_PWMBlue(cycle);
		break;
		case 'G':
		LOG_DEBUG("Cycle: %d", cycle);
		LOG_DEBUG("Apply new settings to PWM_GREEN.");
		setDutyCycle_PWMGreen(cycle);
		break;
		case 'O':
		LOG_DEBUG("Cycle: %d", cycle);
		LOG_DEBUG("Apply new settings to PWM_OLED.");
		setDutyCycle_PWMOLED(cycle);
		break;
		default:
		LOG_DEBUG("Channel does not exist.");
	}
}
											
 /*static void TCD0Command(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
	 uint8_t index = 1;
	 uint16_t period;
	 char option = data[index];
	 LOG_DEBUG("Option: %c", option);
	 switch(option){
		case 'G':
		LOG_DEBUG("Current period is: %d", getPeriod_TCD0());
		break;
		case 'S':
		period = command_next_int(&index, data, len);
		#ifdef REV_2
		setPeriod_TCD0(period);
		#else
		setPeriod_TCD1(period);
		#endif
		break;
		default:
		LOG_DEBUG("Not a valid option.");
	 }
 }*/
  
/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init()
{
	command_hook_description('P', &pwmCommand,	"P <channel> <intensity>\r\n\t"
												"Set PWM channel compare value.");
	/*command_hook_description('N', &TCD0Command,	"N <G(Get) / S(Set)> (<PER register>)\r\n\t"
												"Get / Set TCD0 PER register.");*/
	init_PWMRed(PWM_FREQ_16KHZ);
	init_PWMBlue(PWM_FREQ_16KHZ);
	init_PWMGreen(PWM_FREQ_16KHZ);
	init_PWMOLED(PWM_FREQ_16KHZ);
	return 1;
}

static uint8_t deinit(void) 
{
	return 1;
}

MODULE_DEFINE(PWM, "PWM", &init, &deinit);
