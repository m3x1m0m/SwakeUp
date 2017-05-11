/////////////////////////////////////////////////////////////////////////////////
// PWM driver for the ATxmega128A4U with high extension resolution plus
// (x8 the input freq. of the system clock).
//
// Author:				Maximilian Stiefel
// Last Modification:	10.05.2017
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
#define PWM_FREQ_2MHZ 63
#define PWM_FREQ_1MHZ 127
#define PWM_FREQ_800KHZ 159
#define PWM_FREQ_500KHZ 255
#define PWM_FREQ_250KHZ 511
#define PWM_FREQ_125KHZ 1020
#define PWM_FREQ_64KHZ 2000  
#define PWM_FREQ_16KHZ 7999

#define PWM_INIT_CYCLE 0

// Was not available although it is declared in avr/iox128a4u.h.
#define HIRES_HRPLUS_bm  0x04  /* High Resolution Plus bit mask. */


/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////

// Red
void init_PWMRed(uint16_t period);
void setDutyCycle_PWMRed(uint16_t cycle);
uint16_t getDutyCycle_PWMRed(void);

// Blue
void init_PWMBlue(uint16_t period);
void setDutyCycle_PWMBlue(uint16_t cycle);
uint16_t getDutyCycle_PWMBlue(void);

// Green
void init_PWMGreen(uint16_t period);
void setDutyCycle_PWMGreen(uint16_t cycle);
uint16_t getDutyCycle_PWMGreen(void);

// OLED
void init_PWMOLED(uint16_t period);
void setDutyCycle_PWMOLED(uint16_t cycle);
uint16_t getDutyCycle_PWMOLED(void);

// TCD0
void setPeriod_TCD0(uint16_t period);
uint16_t getPeriod_TCD0();

MODULE_EXP(PWM)

#endif /* XMEGA_DRIVERS_HOST_PWM_H_ */
