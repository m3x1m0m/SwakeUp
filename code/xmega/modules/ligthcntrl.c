/////////////////////////////////////////////////////////////////////////////////
// Light controller, which simple allows to post colors with a duration to a 
// queue and takes care of execution.
//
// Author:				Maximilian Stiefel
// Last Modification:	25.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdio.h>
#include "../util/fixedpoint.h"
#include "ligthcntrl.h"
#include "../drivers/host/pwm.h"
#include "../util/event.h"
#include "../drivers/host/timer.h"
#include "../modules/log.h"
#include "../pin_rev_1.h"

LOG_INIT("LIGHT");

/////////////////////////////////////////////////////////////////////////////////
// Typedefs
/////////////////////////////////////////////////////////////////////////////////
typedef enum mycolorstate_t {IDLE, PLAY_COLOR, PLAY_COLOR_SMOOTH} mycolorstate_t;

/////////////////////////////////////////////////////////////////////////////////
// Globale Vars
/////////////////////////////////////////////////////////////////////////////////
static volatile myrgbcolor_t *patternQueue[QUEUE_LENGTH] = {NULL};
static volatile uint16_t readInd;
static volatile uint16_t writeInd;
uint8_t repeatMode = 0;

/////////////////////////////////////////////////////////////////////////////////
// Increase indRead Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
static inline incReadInd(uint16_t *i)
{
	if( (*i) < (writeInd-1) )
		(*i)++;
	else
		(*i) = 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Increase indRead Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
static inline incWriteInd(uint16_t *i)
{
	if( (*i) < QUEUE_LENGTH)
		(*i)++;
	else
		(*i) = 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Set Colors
/////////////////////////////////////////////////////////////////////////////////
static inline setRGB(myrgbcolor_t *color)
{
	// TODO: In a later HW revision the PID controller has to be included here.
	if(color == NULL)
	{
		setDutyCycle_PWMRED(0);
		setDutyCycle_PWMBLUE(0);
		setDutyCycle_PWMGREEN(0);
	}
	else
	{
		setDutyCycle_PWMRED(color->red);
		setDutyCycle_PWMBLUE(color->blue);
		setDutyCycle_PWMGREEN(color->green);	
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Add another Color to the Light Queue
/////////////////////////////////////////////////////////////////////////////////
uint8_t addToLigthPattern(myrgbcolor_t *color)
{
	if( patternQueue[writeInd] == NULL)				// Check if queue is already full
	{
		patternQueue[writeInd] = color;
		incWriteInd(&writeInd);
		return 1;									// Successfully added element 
	}
	else
		return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Get Gradient between two Vals
/////////////////////////////////////////////////////////////////////////////////
static inline myfixedpoint32_t getGradient(uint8_t ia, uint8_t ib, uint16_t idx)
{
	// Variables
	myfixedpoint32_t a = FROMINT(ia);
	myfixedpoint32_t b = FROMINT(ib);
	myfixedpoint32_t dx = FROMINT(idx);
	
	// Action
	return fixedPt_div( (b-a), dx );  
}

/////////////////////////////////////////////////////////////////////////////////
// Next Smooth Value
/////////////////////////////////////////////////////////////////////////////////
static inline myrgbcolor_t nextSmoothVal(myrgbcolor_t colora, myrgbcolor_t colorb)
{
	// Variables
	myrgbcolor_t newVal = colora;
	
	// Action
	
	newVal.red = colora.red + TOUINT8T(getGradient(colora.red, colorb.red, colora.duration));
	newVal.blue = colora.blue + TOUINT8T(getGradient(colora.blue, colorb.blue, colora.duration));
	newVal.green = colora.green + TOUINT8T(getGradient(colora.green, colorb.green, colora.duration));
	
	
	#ifdef SHOW_INTERPOLATED_COLORS
		LOG_DEBUG("RBG: %d, %d, %d", newVal.red, newVal.blue, newVal.green); 
		LOG_DEBUG("Gradients RBG: %d, %d, %d", TOUINT8T(getGradient(colora.red, colorb.red, colora.duration)),\
		TOUINT8T(getGradient(colora.blue, colorb.blue, colora.duration)),\
		TOUINT8T(getGradient(colora.green, colorb.green, colora.duration))); 
	#endif	
	return newVal;				
}

/////////////////////////////////////////////////////////////////////////////////
// Executet every 100 ms
/////////////////////////////////////////////////////////////////////////////////
static void light(Event * event, uint8_t * data __attribute__ ((unused))) 
{
	static volatile mycolorstate_t currentState = IDLE;
	static volatile myrgbcolor_t currentColor;
	static volatile myrgbcolor_t nextColor;
	
	if (event == &EVENT_TIMER_10_HZ) 
	{
		switch (currentState)
		{
		case IDLE:
			if(patternQueue[readInd] != NULL)
			{
				currentColor = *(patternQueue[readInd]);						// Copy color out of queue
				setRGB(&currentColor);											// Set light to color
				currentColor.duration--;
				if(currentColor.smoothing)
				{
					currentState = PLAY_COLOR_SMOOTH;
					nextColor = *(patternQueue[readInd + 1]);
				}
				else
				{
					currentState = PLAY_COLOR;
				}
			}
			else
			{
				setRGB(NULL);													// Dark
			}
			break;
		case PLAY_COLOR:
				if( currentColor.duration > 0)
				{
					currentColor.duration--;
				}
				else
				{
					if(!repeatMode)						
						patternQueue[readInd] = NULL;							// Remove element
					incReadInd(&readInd);
					currentState = IDLE;
				}
			break;
		case PLAY_COLOR_SMOOTH:
				if( currentColor.duration > 0)
				{
					currentColor = nextSmoothVal(currentColor, nextColor);
					setRGB(&currentColor);
					currentColor.duration--;
				}
				else
				{
					if(!repeatMode)
						patternQueue[readInd] = NULL;							// Remove element
					incReadInd(&readInd);
					currentState = IDLE;
				}		
				break;
		}
		#ifdef SHOW_INTERPOLATED_COLORS
			LOG_DEBUG("State: %d", currentState);
			LOG_DEBUG("Duration: %d", currentColor.duration);
			LOG_DEBUG("Current Color: %s", currentColor.name);
			LOG_DEBUG("----------------------");
		#endif
	}
}
/////////////////////////////////////////////////////////////////////////////////
// Enable Light Controller
/////////////////////////////////////////////////////////////////////////////////
void enableLightCnt(uint8_t repeat)
{
	repeatMode = repeat;
	LOG_DEBUG("Ligth controller enabled.");
	event_addListener(&EVENT_TIMER_10_HZ, light);
}

/////////////////////////////////////////////////////////////////////////////////
// Disable Light Controller
/////////////////////////////////////////////////////////////////////////////////
void stopLightCnt(void)
{
	LOG_DEBUG("Ligth controller disabled.");
	event_removeListener(&EVENT_TIMER_10_HZ, light);
}
