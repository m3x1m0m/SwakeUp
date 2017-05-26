/////////////////////////////////////////////////////////////////////////////////
// PWM driver for the ATxmega128A4U with high extension resolution plus 
// (x8 the input freq. of the system clock).
// 
// Author:				Maximilian Stiefel
// Last Modification:	26.05.2017
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
// Timer TCD0 functions
/////////////////////////////////////////////////////////////////////////////////
void init_TCD0(uint16_t period)
{
	if(period < PWM_MIN_PERIOD) period = PWM_MIN_PERIOD;
	HIRESD.CTRLA |= HIRES_HREN0_bm;										// Activate high resolution plus mode
	TCD0.PER = period-(period%4);										// Avoid that the last two bits are set
																		// Acc. to the datasheet this is necessary for proper operation
	TCD0.CTRLB |= TC_WGMODE_SINGLESLOPE_gc;								// Single slope PWM and TCD0 enable
	TCD0.CTRLA |= TC_CLKSEL_DIV1_gc;									// Activate timer
}

void deinit_TCD0()
{
	TCD0.CTRLA &= ~TC_CLKSEL_DIV1_gc;									// Deactivate timer
}

uint16_t getPeriod_TCD0()
{
	return TCD0.PER;
}

/////////////////////////////////////////////////////////////////////////////////
// Timer TCD1 functions. Only relevant if revision 1 is used.
/////////////////////////////////////////////////////////////////////////////////
#ifdef REV_1
void init_TCD1(uint16_t period)
{
	if(period < PWM_MIN_PERIOD)
	period = PWM_MIN_PERIOD;
	HIRESD.CTRLA |= HIRES_HREN1_bm | HIRES_HRPLUS_bm ;					// Activate high resolution plus mode
	TCD1.PER = period-(period%8);										// Avoid that the last two bits are set
																		// Acc. to the datasheet this is necessary for proper operation
	TCD1.CTRLB |= TC_WGMODE_SINGLESLOPE_gc;								// Single slope PWM and TCD0 enable
	TCD1.CTRLA |= TC_CLKSEL_DIV1_gc;									// Activate timer
}

uint16_t getPeriod_TCD1()
{
	return TCD1.PER;
}
#endif


/////////////////////////////////////////////////////////////////////////////////
// Macros for Compare Channel Setup
/////////////////////////////////////////////////////////////////////////////////
#define CREATE_SET_DUTY_CYCLE(CHANNEL_NAME, TIMER_NAME, CHANNEL_ID, GET_PER)\
void setDutyCycle_PWM ##CHANNEL_NAME(uint16_t cycle)\
{\
	uint16_t period = 0;\
	period = GET_PER();\
	if (cycle < period){\
		TIMER_NAME.CHANNEL_ID = cycle;\
		while( !(TIMER_NAME.INTFLAGS & TC0_OVFIF_bm) );\
		TIMER_NAME.INTFLAGS &= ~TC1_OVFIF_bm;\
	}\
}

#define INIT_PWM_CHANNEL(CHANNEL_NAME, PIN_NU, TIMER_NAME, COMPARE_ENABLE)\
PWM_PORT.DIRSET |= (1 << PIN_NU);\
TIMER_NAME.CTRLB |= TC_WGMODE_SINGLESLOPE_gc | COMPARE_ENABLE;\
setDutyCycle_PWM ##CHANNEL_NAME(PWM_INIT_CYCLE);

#define  CREATE_GET_DUTY_CYCLE(CHANNEL_NAME, TIMER_NAME, CHANNEL_ID)\
uint16_t getDutyCycle_PWM ##CHANNEL_NAME(void)\
{\
	return TIMER_NAME.CHANNEL_ID;\
}

/////////////////////////////////////////////////////////////////////////////////
// PWM Channel Functions
/////////////////////////////////////////////////////////////////////////////////
CREATE_SET_DUTY_CYCLE(RED, PWM_RED_TIMER, PWM_RED_CHANNEL, PWM_RED_GET_PERIOD);							// Channel name, timer name, channel on HW (A, B, C or D)
CREATE_GET_DUTY_CYCLE(RED, PWM_RED_TIMER, PWM_RED_CHANNEL);

CREATE_SET_DUTY_CYCLE(GREEN, PWM_GREEN_TIMER, PWM_GREEN_CHANNEL, PWM_GREEN_GET_PERIOD);							
CREATE_GET_DUTY_CYCLE(GREEN, PWM_GREEN_TIMER, PWM_GREEN_CHANNEL);

CREATE_SET_DUTY_CYCLE(BLUE, PWM_BLUE_TIMER, PWM_BLUE_CHANNEL, PWM_BLUE_GET_PERIOD);
CREATE_GET_DUTY_CYCLE(BLUE, PWM_BLUE_TIMER, PWM_BLUE_CHANNEL);

CREATE_SET_DUTY_CYCLE(OLED, PWM_OLED_TIMER, PWM_OLED_CHANNEL, PWM_OLED_GET_PERIOD);
CREATE_GET_DUTY_CYCLE(OLED, PWM_OLED_TIMER, PWM_OLED_CHANNEL);

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
		setDutyCycle_PWMRED(cycle);
		break;
		case 'B':
		LOG_DEBUG("Cycle: %d", cycle);
		LOG_DEBUG("Apply new settings to PWM_BLUE.");
		setDutyCycle_PWMBLUE(cycle);
		break;
		case 'G':
		LOG_DEBUG("Cycle: %d", cycle);
		LOG_DEBUG("Apply new settings to PWM_GREEN.");
		setDutyCycle_PWMGREEN(cycle);
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
	
	init_TCD0(PWM_FREQ_16KHZ);
	#ifdef REV_1																					// Revision 1 works with two timers
	init_TCD1(PWM_FREQ_16KHZ);
	#endif
	INIT_PWM_CHANNEL(RED, PWM_RED_PIN_NU, PWM_RED_TIMER, PWM_RED_ENABLE_FLAG);
	INIT_PWM_CHANNEL(GREEN, PWM_GREEN_PIN_NU, PWM_GREEN_TIMER, PWM_GREEN_ENABLE_FLAG);
	INIT_PWM_CHANNEL(BLUE, PWM_BLUE_PIN_NU, PWM_BLUE_TIMER, PWM_BLUE_ENABLE_FLAG);
	INIT_PWM_CHANNEL(OLED, PWM_OLED_PIN_NU, PWM_OLED_TIMER, PWM_OLED_ENABLE_FLAG);
	LOG_DEBUG("PWM initialized.");
	return 1;
}

static uint8_t deinit(void) 
{
	deinit_TCD0();
	return 1;
}

MODULE_DEFINE(PWM, "PWM", &init, &deinit);
