/*
 * pwm.h
 *
 *  Created on: May 4, 2017
 *      Author: maximilian
 */

#ifndef XMEGA_DRIVERS_HOST_PWM_H_
#define XMEGA_DRIVERS_HOST_PWM_H_

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////

// PWM Pins
#define PWM_RED (1 << 0)
#define PWM_GREEN (1 << 4)

// Predefined period register values for certain freq. 
// High resolution extension plus (x8) has to be activated for these values to be correct.
#define MIN_PERIOD 8
#define PWM_FREQ_2MHZ 63
#define PWM_FREQ_1MHZ 127
#define PWM_FREQ_800KHZ 159
#define PWM_FREQ_500KHZ 255
#define PWM_FREQ_250KHZ 511
#define PWM_FREQ_125KHZ 1020
#define PWM_FREQ_64KHZ 2000  

#define INIT_DUTY_CYCLE 0.1

// Was not available although it is declared in avr/iox128a4u.h.
#define HIRES_HRPLUS_bm  0x04  /* High Resolution Plus bit mask. */


/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////
void init_PWMRed(uint16_t period);
void init_PWMGreen(uint16_t period);
void setDutyCycle_PWMRed(float cycle);
void setPeriod_PWMRed(uint16_t period);

MODULE_EXP(PWM)

#endif /* XMEGA_DRIVERS_HOST_PWM_H_ */
