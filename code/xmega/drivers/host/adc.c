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
#include <stdlib.h>
#include "../../pin_definitions.h"
#include "../../modules/log.h"
#include "../../modules/command.h"
#include "adc.h"

LOG_INIT("ADC");

/////////////////////////////////////////////////////////////////////////////////
// Define
/////////////////////////////////////////////////////////////////////////////////
#define LOAD_ADC(adcchannel, semaphore)\
	ADCA.CTRLA |= adcchannel;\
	while(!semaphore)

/////////////////////////////////////////////////////////////////////////////////
// Global vars
/////////////////////////////////////////////////////////////////////////////////
static uint16_t offsetErr = 0;															// Offset error from the ADC

static volatile uint8_t loaded_RED = 0;													// Simple semaphore for the shared buffer
static uint16_t adcVals_RED[NU_AVERAGING_VALS];											// Shared buffer for ADC values

static volatile uint8_t loaded_BLUE = 0;
static uint16_t adcVals_BLUE[NU_AVERAGING_VALS];

static volatile uint8_t loaded_GREEN = 0;
static uint16_t adcVals_GREEN[NU_AVERAGING_VALS];

static volatile uint8_t loaded_OLED = 0;
static uint16_t adcVals_OLED[NU_AVERAGING_VALS];

/////////////////////////////////////////////////////////////////////////////////
// Init ADCA
/////////////////////////////////////////////////////////////////////////////////
void init_ADCA(void)
{
	ADCA.REFCTRL |= ADC_REFSEL_INTVCC_gc;												// Select Vcc/1.6 for reference
	ADCA.PRESCALER |= ADC_PRESCALER_DIV32_gc;											// ADC clock is Clk/32 -> 16 MHz / 32 = 500 kHz
	ADCA.CTRLB |= ADC_CURRLIMIT_MED_gc | ADC_CONMODE_bm;								// Current limit to max 1MSPS 12 bit resolution right
	ADCA.CAL = (0x0FFF & ((PRODSIGNATURES_ADCACAL1 << 8) | PRODSIGNATURES_ADCACAL0));	// Load calibration value
	ADCA.EVCTRL = 0x00;

	
	PORTA.DIRCLR |= ADC_RED | ADC_BLUE | ADC_GREEN | ADC_OLED;
	
	ADCA.CH0.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;									// RED
	ADCA.CH0.MUXCTRL |= ADC_CH_MUXPOS_PIN7_gc;	
	ADCA.INTFLAGS = ADC_CH0IF_bm;
	ADCA.CH0.INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm;													
	
	ADCA.CH1.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;									// BLUE			
	ADCA.CH1.MUXCTRL |= ADC_CH_MUXPOS_PIN6_gc;	
	ADCA.INTFLAGS = ADC_CH1IF_bm;
	ADCA.CH1.INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm;							
	
	ADCA.CH2.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;									// GREEN
	ADCA.CH2.MUXCTRL |=ADC_CH_MUXPOS_PIN5_gc;			
	ADCA.INTFLAGS = ADC_CH2IF_bm;
	ADCA.CH2.INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm;									
	
	ADCA.CH3.CTRL |= ADC_CH_INPUTMODE_SINGLEENDED_gc;									// OLED
	ADCA.CH3.MUXCTRL |= ADC_CH_MUXPOS_PIN4_gc;	
	ADCA.INTFLAGS = ADC_CH3IF_bm;
	ADCA.CH3.INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm;							
	
	ADCA.CTRLA |= ADC_ENABLE_bm;														// Enable ADCA
	for(int i=0; i < 24; i++)															// Wait until ADC is started up (in every case less than 24 cycles)
	{
		asm("nop");
		if(i == 23)
		{
			LOG_DEBUG("Waited for %d cycles for ADC to start up.", i+1);	
		}
	}
	
	compensateOffset_ADCA();
	
	LOG_DEBUG("ADC initialized.");
}

/////////////////////////////////////////////////////////////////////////////////
// Offset compensation
/////////////////////////////////////////////////////////////////////////////////
void compensateOffset_ADCA()
{
	// TODO: Write a calibration algorithm here, which checks the result at a 
	// pin which is connected to GND. 
	LOG_DEBUG("Offset error of %d will be substracted.", offsetErr);
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_RED
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCRed(void)
{
	// Variables
	uint16_t result = 0;
	uint16_t i = 0;
	
	// Action
	LOAD_ADC(ADC_CH1START_bm, loaded_BLUE);
	while(i < NU_AVERAGING_VALS)
	result += adcVals_BLUE[i++];									// Read out result
	loaded_OLED = 0;												// Set semaphore back after emptying
	return ( (result / NU_AVERAGING_VALS) - offsetErr);
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_BLUE
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCBlue(void)
{
	// Variables
	uint16_t result = 0;
	uint16_t i = 0;
	
	// Action
	LOAD_ADC(ADC_CH1START_bm, loaded_BLUE);
	while(i < NU_AVERAGING_VALS)
	result += adcVals_BLUE[i++];									// Read out result
	loaded_OLED = 0;												// Set semaphore back after emptying
	return ( (result / NU_AVERAGING_VALS) - offsetErr);
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_GREEN
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCGreen(void)
{
	// Variables
	uint16_t result = 0;
	uint16_t i = 0;
	
	// Action
	LOAD_ADC(ADC_CH2START_bm, loaded_GREEN);
	while(i < NU_AVERAGING_VALS)
	result += adcVals_GREEN[i++];									// Read out result
	loaded_OLED = 0;												// Set semaphore back after emptying
	return ( (result / NU_AVERAGING_VALS) - offsetErr);
}

/////////////////////////////////////////////////////////////////////////////////
// Get value from ADC_OLED
/////////////////////////////////////////////////////////////////////////////////
uint16_t getVal_ADCOLED(void)
{
	// Variables
	uint16_t result = 0;
	uint16_t i = 0;
	
	// Action
	LOAD_ADC(ADC_CH3START_bm, loaded_OLED);
	while(i < NU_AVERAGING_VALS)
		result += adcVals_OLED[i++];									// Read out result
	loaded_OLED = 0;													// Set semaphore back after emptying
	return ( (result / NU_AVERAGING_VALS) - offsetErr);					
}

/////////////////////////////////////////////////////////////////////////////////
// ISR ADC_RED
/////////////////////////////////////////////////////////////////////////////////
ISR(ADCA_CH0_vect)
{
	static cycles = 0;
	if(!loaded_OLED)
	{
		adcVals_OLED[cycles++] = ADCA.CH0.RES;
		if(cycles < NU_AVERAGING_VALS)
		ADCA.CTRLA |= ADC_CH0START_bm;
		else
		{
			loaded_OLED = 1;
			cycles = 0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
// ISR ADC_BLUE
/////////////////////////////////////////////////////////////////////////////////
ISR(ADCA_CH1_vect)
{
	static cycles = 0;
	if(!loaded_OLED)
	{
		adcVals_OLED[cycles++] = ADCA.CH1.RES;
		if(cycles < NU_AVERAGING_VALS)
		ADCA.CTRLA |= ADC_CH1START_bm;
		else
		{
			loaded_OLED = 1;
			cycles = 0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
// ISR ADC_GREEN
/////////////////////////////////////////////////////////////////////////////////
ISR(ADCA_CH2_vect)
{
	static cycles = 0;
	if(!loaded_OLED)
	{
		adcVals_OLED[cycles++] = ADCA.CH2.RES; 
		if(cycles < NU_AVERAGING_VALS)									
			ADCA.CTRLA |= ADC_CH2START_bm;
		else 
		{
			loaded_OLED = 1;
			cycles = 0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
// ISR ADC_OLED
/////////////////////////////////////////////////////////////////////////////////
ISR(ADCA_CH3_vect)
{
	static cycles = 0;
	if(!loaded_OLED)
	{
		adcVals_OLED[cycles++] = ADCA.CH3.RES;
		if(cycles < NU_AVERAGING_VALS)									// Start another conversion from ADCA channel 3 if not enough values are there
		ADCA.CTRLA |= ADC_CH3START_bm;
		else
		{
			loaded_OLED = 1;
			cycles = 0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Terminal commands for debugging
/////////////////////////////////////////////////////////////////////////////////
static void adcCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
	uint8_t index = 1;
	uint16_t cycle;
	char channel = data[index];
	LOG_DEBUG("Channel: %c", channel);
	cycle = command_next_int(&index, data, len);
	switch(channel){
		case 'R':
		LOG_DEBUG("ADC_RED value is %d.", getVal_ADCRed());
		break;
		case 'B':
		LOG_DEBUG("ADC_BLUE value is %d.", getVal_ADCBlue());
		break;
		case 'G':
		LOG_DEBUG("ADC_GREEN value is %d.", getVal_ADCGreen());
		break;
		case 'O':
		LOG_DEBUG("ADC_OLED value is %d.", getVal_ADCOLED() );
		break;
		default:
		LOG_DEBUG("Channel does not exist.");
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init(void)
{
	command_hook_description('M', &adcCommand,	"M <channel>\r\n\t"
												"ADC readout for one channel.");
	init_ADCA();
	return EXIT_SUCCESS;
}

static uint8_t deinit(void)
{
	return EXIT_SUCCESS;
}

MODULE_DEFINE(ADC, "ADC", &init, &deinit);
