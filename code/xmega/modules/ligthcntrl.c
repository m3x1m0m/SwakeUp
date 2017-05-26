/////////////////////////////////////////////////////////////////////////////////
// Light controller, which simple allows to post colors with a duration to a 
// queue and takes care of execution.
//
// Author:				Maximilian Stiefel
// Last Modification:	26.05.2017
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
#include "../util/module.h"
#include "../pin_rev_1.h"

LOG_INIT("LIGHT");

/////////////////////////////////////////////////////////////////////////////////
// Typedefs
/////////////////////////////////////////////////////////////////////////////////
typedef enum mycolorstate_t {IDLE, PLAY_COLOR, PLAY_COLOR_SMOOTH} mycolorstate_t;

typedef struct mycolorgradient_t
{
	myfixedpoint32_t red;
	myfixedpoint32_t green;
	myfixedpoint32_t blue;
} mycolorgradient_t;

/////////////////////////////////////////////////////////////////////////////////
// Globale Vars
/////////////////////////////////////////////////////////////////////////////////
static volatile myrgbcolor_t *patternQueue[QUEUE_LENGTH] = {NULL};
static volatile uint16_t readInd;
static volatile uint16_t writeInd;
static volatile uint8_t repeatMode = 0;

/////////////////////////////////////////////////////////////////////////////////
// Increase indRead Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
/*static inline void incReadInd(uint16_t *i)
{
	if( (*i) < (writeInd-1) )
		(*i)++;
	else
		(*i) = 0;
}*/

/////////////////////////////////////////////////////////////////////////////////
// Increase indRead Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
static inline uint16_t incReadInd(uint16_t i)
{
	if( i < (writeInd-1) ) i++;
	else i = 0;
	return i;
}

/////////////////////////////////////////////////////////////////////////////////
// Increase indRead Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
/*static inline void incWriteInd(uint16_t *i)
{
	if( (*i) < QUEUE_LENGTH)
		(*i)++;
	else
		(*i) = 0;
}*/

/////////////////////////////////////////////////////////////////////////////////
// Increase indRead Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
static inline uint16_t incWriteInd(uint16_t i)
{
	if( i < QUEUE_LENGTH) i++;
	else i = 0;
	return i;
}

/////////////////////////////////////////////////////////////////////////////////
// Set Colors
/////////////////////////////////////////////////////////////////////////////////
static inline void setRGB(myrgbcolor_t *color)
{
	uint16_t red = TOUINT16T(color->red);
	uint16_t green = TOUINT16T(color->green);
	uint16_t blue = TOUINT16T(color->blue);
	
	// TODO: In a later HW revision the PID controller has to be included here.
	if(color == NULL)
	{
		setDutyCycle_PWMRED(0);
		setDutyCycle_PWMBLUE(0);
		setDutyCycle_PWMGREEN(0);
	}
	else
	{
		if(red > SECURITY_THRESHOLD )
		{
			LOG_ERROR("R: Security threshold exceeded.");
		}
		else setDutyCycle_PWMRED(red);
		
		if(green > SECURITY_THRESHOLD )
		{
			LOG_ERROR("G: Security threshold exceeded.");
		}
		else setDutyCycle_PWMGREEN(green);
		
		if(blue > SECURITY_THRESHOLD )
		{
			LOG_ERROR("B Security threshold exceeded.");
		}
		else setDutyCycle_PWMBLUE(blue);
		
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Amplify the Colors
/////////////////////////////////////////////////////////////////////////////////
static inline myrgbcolor_t *amplify(myrgbcolor_t *color)
{
	color->red = fixedPt_mul(color->red, color->gain);
	color->green = fixedPt_mul(color->green, color->gain);
	color->blue = fixedPt_mul(color->blue, color->gain);
	return color;
}

/////////////////////////////////////////////////////////////////////////////////
// Add another Color to the Light Queue
/////////////////////////////////////////////////////////////////////////////////
uint8_t addToLigthPattern(myrgbcolor_t *color)
{
	if( patternQueue[writeInd] == NULL)				// Check if queue is already full
	{
		patternQueue[writeInd] = amplify(color);
		writeInd = incWriteInd(writeInd);
		return 1;									// Successfully added element 
	}
	else
		return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Get Gradient between two Vals
/////////////////////////////////////////////////////////////////////////////////
static inline myfixedpoint32_t getGradient(myfixedpoint32_t ia, myfixedpoint32_t ib, uint16_t idx)
{
	// Variables
	volatile myfixedpoint32_t a = ia;
	volatile myfixedpoint32_t b = ib;
	volatile myfixedpoint32_t dx = FROMINT(idx);
		
	// Action
	return fixedPt_div( (a-b), dx );  
}

/////////////////////////////////////////////////////////////////////////////////
// Set New Gradient
/////////////////////////////////////////////////////////////////////////////////
static inline void setGradient(myrgbcolor_t currentColor, myrgbcolor_t nextColor, mycolorgradient_t *gradient)
{
	gradient->red = getGradient(nextColor.red, currentColor.red, currentColor.duration);
	gradient->green = getGradient(nextColor.green, currentColor.green, currentColor.duration);
	gradient->blue = getGradient(nextColor.blue, currentColor.blue, currentColor.duration);	
}

/////////////////////////////////////////////////////////////////////////////////
// Next Smooth Value
/////////////////////////////////////////////////////////////////////////////////
static inline myrgbcolor_t nextSmoothVal(myrgbcolor_t currentColor, mycolorgradient_t *gradient)
{
	// Variables
	myrgbcolor_t newVal = currentColor;					// Transfer duration etc.
	myfixedpoint32_t currentRed = currentColor.red;
	myfixedpoint32_t currentGreen = currentColor.green;
	myfixedpoint32_t currentBlue = currentColor.blue;
	myfixedpoint32_t newRed = 0;
	myfixedpoint32_t newGreen = 0;
	myfixedpoint32_t newBlue = 0;
	
	// Action
	newRed = currentRed + gradient->red;
	newGreen = currentGreen + gradient->green;
	newBlue = currentBlue + gradient->blue;

	#ifdef SHOW_INTERPOLATED_COLORS
		/*LOG_DEBUG("newRed: %d", newRed);
		LOG_DEBUG("newGreen: %d", newGreen);
		LOG_DEBUG("newBlue: %d ", newBlue);*/
	#endif

	newVal.red = ( (newRed >= 0) ? newRed : 0);
	newVal.green = ( (newGreen >= 0) ? newGreen : 0);
	newVal.blue = ( (newBlue >= 0) ? newBlue : 0);
	
	return newVal;				
}

/////////////////////////////////////////////////////////////////////////////////
// Executed every 100 ms
/////////////////////////////////////////////////////////////////////////////////
static void light(Event * event, uint8_t * data __attribute__ ((unused))) 
{
	static mycolorstate_t currentState = IDLE;
	static myrgbcolor_t currentColor;
	static myrgbcolor_t nextColor;
	static mycolorgradient_t gradient;
	
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
				nextColor = *(patternQueue[incReadInd(readInd)]);
				if(currentColor.smoothing)
				{
					currentState = PLAY_COLOR_SMOOTH;
					setGradient(currentColor, nextColor, &gradient);
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
					readInd = incReadInd(readInd);
					currentState = IDLE;
				}
			break;
		case PLAY_COLOR_SMOOTH:
				if( currentColor.duration > 0)
				{
					currentColor = nextSmoothVal(currentColor, &gradient);
					setRGB(&currentColor);
					currentColor.duration--;
				}
				else
				{
					if(!repeatMode)
						patternQueue[readInd] = NULL;							// Remove element
					readInd = incReadInd(readInd);
					currentState = IDLE;
				}		
				break;
		}
		#ifdef SHOW_INTERPOLATED_COLORS
			LOG_DEBUG("State: %d", currentState);
			LOG_DEBUG("Duration: %d", currentColor.duration);
			LOG_DEBUG("Current Color: %s", currentColor.name);
			LOG_DEBUG("Next Color: %s", nextColor.name);
			LOG_DEBUG("RGB: %d, %d, %d", currentColor.red, currentColor.green, currentColor.blue);
			/*LOG_DEBUG("Gradient R: %d", gradient.red);
			LOG_DEBUG("Gradient G: %d", gradient.green);
			LOG_DEBUG("Gradient B: %d", gradient.blue);*/
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

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init()
{
	LOG_DEBUG("Light controller initialized.");
	return 1;
}

static uint8_t deinit(void) 
{
	return 1;
}

MODULE_DEFINE(LIGHTCNTRL, "Light Controller", &init, &deinit, &PWM);