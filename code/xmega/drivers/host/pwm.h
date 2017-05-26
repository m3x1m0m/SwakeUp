/////////////////////////////////////////////////////////////////////////////////
// PWM driver for the ATxmega128A4U with high extension resolution plus
// (x8 the input freq. of the system clock).
//
// Author:				Maximilian Stiefel
// Last Modification:	26.05.2017
/////////////////////////////////////////////////////////////////////////////////

#ifndef XMEGA_DRIVERS_HOST_PWM_H_
#define XMEGA_DRIVERS_HOST_PWM_H_

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////

// Predefined period register values for certain freq. 
// High resolution extension plus (x8) has to be activated for these values to be correct.
#define PWM_MIN_PERIOD 8
#define PWM_MAX_PERIOD 65535
#define GET_PER(FPWM) (F_CPU*8-FPWM)/FPWM
						
#define PWM_FREQ_2MHZ GET_PER(2e6)
#define PWM_FREQ_1MHZ GET_PER(1e6)
#define PWM_FREQ_800KHZ GET_PER(800e3)
#define PWM_FREQ_500KHZ GET_PER(500e3)
#define PWM_FREQ_250KHZ GET_PER(250e3)
#define PWM_FREQ_125KHZ GET_PER(125e3)
#define PWM_FREQ_64KHZ GET_PER(64e3)  
#define PWM_FREQ_16KHZ GET_PER(16e3)

#define PWM_INIT_CYCLE 0

// Was not available although it is declared in avr/iox128a4u.h.
#define HIRES_HRPLUS_bm  0x04  /* High Resolution Plus bit mask. */

/////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////
#define EXPORT_PWM_CHANNEL_FUNCS(CHANNEL_NAME)\
void init_PWM ##CHANNEL_NAME(uint16_t period);\
void setDutyCycle_PWM ##CHANNEL_NAME(uint16_t cycle);\
uint16_t getDutyCycle_PWM ##CHANNEL_NAME(void);


/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////

EXPORT_PWM_CHANNEL_FUNCS(RED);
EXPORT_PWM_CHANNEL_FUNCS(GREEN);
EXPORT_PWM_CHANNEL_FUNCS(BLUE);
EXPORT_PWM_CHANNEL_FUNCS(OLED);

MODULE_EXP(PWM);

#endif /* XMEGA_DRIVERS_HOST_PWM_H_ */
