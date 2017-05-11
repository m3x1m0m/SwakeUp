/////////////////////////////////////////////////////////////////////////////////
// ADC driver for the ATxmega128A4U. Simple, single-ended, single conversion.
//
// Author:				Maximilian Stiefel
// Last Modification:	11.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../pin_definitions.h"
#include "../../modules/log.h"
#include "adc.h"


/////////////////////////////////////////////////////////////////////////////////
// Init ADCA
/////////////////////////////////////////////////////////////////////////////////
void init_ADCA(void)
{
	PORTA.DIRCLR |= ADC_RED | ADC_BLUE | ADC_GREEN | ADC_OLED;
	ADCA.CH0.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;				// Set up all channels
	ADCA.CH0.MUXCTRL |= ADC_CH_MUXPOS_PIN7_gc;									
	ADCA.CH0.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;				
	ADCA.CH0.MUXCTRL |= ADC_CH_MUXPOS_PIN6_gc;	
	ADCA.CH0.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;
	ADCA.CH0.MUXCTRL |=ADC_CH_MUXPOS_PIN5_gc;								
	ADCA.CH3.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;				
	ADCA.CH3.MUXCTRL |= ADC_CH_MUXPOS_PIN4_gc;		
	ADCA.REFCTRL |= ADC_REFSEL_INT1V_gc;							// Select bandgap device for reference 1.0 V 							
	ADCA.CTRLA |= ADC_ENABLE_bm;									// Enable ADCA
	for(int i=0; i < 24; i++);										// Wait until ADC is started up
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_RED
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCRed(void)
{
	uint16_t myADCVal = 0;
	ADCA.CTRLA |= ADC_CH0START_bm;									// Start a conversion from ADCA channel 0
	while( !(ADCA.INTFLAGS & ADC_CH0IF_bm) );						// Wait until conversion is finished
	return ADCA.CH0.RES;											// Read out result
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_BLUE
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCBlue(void)
{
	uint16_t myADCVal = 0;
	ADCA.CTRLA |= ADC_CH1START_bm;									// Start a conversion from ADCA channel 1
	while( !(ADCA.INTFLAGS & ADC_CH1IF_bm) );						// Wait until conversion is finished
	return ADCA.CH1.RES;											// Read out result
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_BLUE
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCGreen(void)
{
	uint16_t myADCVal = 0;
	ADCA.CTRLA |= ADC_CH2START_bm;									// Start a conversion from ADCA channel 2
	while( !(ADCA.INTFLAGS & ADC_CH2IF_bm) );						// Wait until conversion is finished
	return ADCA.CH2.RES;											// Read out result
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_OLED
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCOLED(void)
{
	uint16_t myADCVal = 0;
	ADCA.CTRLA |= ADC_CH3START_bm;									// Start a conversion from ADCA channel 3
	while( !(ADCA.INTFLAGS & ADC_CH3IF_bm) );						// Wait until conversion is finished
	return ADCA.CH3.RES;											// Read out result
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init(void)
{
	init_ADCA();
	return 1;
}

static uint8_t deinit(void)
{
	return 1;
}

MODULE_DEFINE(ADC, "ADC", &init, &deinit);
