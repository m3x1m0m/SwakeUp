/////////////////////////////////////////////////////////////////////////////////
// ADC driver for the ATxmega128A4U. Simple, single-ended, single conversion.
//
// Author:				Maximilian Stiefel
// Last Modification:	11.05.2017
/////////////////////////////////////////////////////////////////////////////////

#ifndef XMEGA_DRIVERS_HOST_ADC_H_
#define XMEGA_DRIVERS_HOST_ADC_H_

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////
#define NU_AVERAGING_VALS 1
#define VREF 2.275
#define ADC_RESOLUTION 12

#define ADC_RED_CHANNEL		ADCA.CH0
#define ADC_RED_INTFLAG		ADC_CH0IF_bm
#define ADC_RED_STARTFLAG	ADC_CH0START_bm
#define ADC_RED_RESULTREG	ADCA.CH0.RES
#define ADC_RED_VECT		ADCA_CH0_vect

#define ADC_BLUE_CHANNEL	ADCA.CH1
#define ADC_BLUE_INTFLAG	ADC_CH1IF_bm
#define ADC_BLUE_STARTFLAG	ADC_CH1START_bm
#define ADC_BLUE_RESULTREG	ADCA.CH1.RES
#define ADC_BLUE_VECT		ADCA_CH1_vect

#define ADC_GREEN_CHANNEL	ADCA.CH2
#define ADC_GREEN_INTFLAG	ADC_CH2IF_bm
#define ADC_GREEN_STARTFLAG	ADC_CH2START_bm
#define ADC_GREEN_RESULTREG	ADCA.CH2.RES
#define ADC_GREEN_VECT		ADCA_CH2_vect

#define ADC_OLED_CHANNEL	ADCA.CH3
#define ADC_OLED_INTFLAG	ADC_CH3IF_bm
#define ADC_OLED_STARTFLAG	ADC_CH3START_bm
#define ADC_OLED_RESULTREG	ADCA.CH3.RES
#define ADC_OLED_VECT		ADCA_CH3_vect

/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////
void init_ADCA(void);
uint16_t getVal_ADCRed(void);
uint16_t getVal_ADCBlue(void);
uint16_t getVal_ADCGreen(void);
uint16_t getVal_ADCOLED(void);

static uint8_t init(void);
static uint8_t deinit(void);

MODULE_EXP(ADC)

#endif /* XMEGA_DRIVERS_HOST_ADC_H_ */