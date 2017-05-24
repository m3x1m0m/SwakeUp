/////////////////////////////////////////////////////////////////////////////////
// 
//
// Author:				Maximilian Stiefel
// Last Modification:	24.05.2017
/////////////////////////////////////////////////////////////////////////////////


#ifndef XMEGA_MODULES_LIGTHCNTRL_H_
#define XMEGA_MODULES_LIGTHCNTRL_H_

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include "../util/fixedpoint.h"

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////
#define QUEUE_LENGTH 128

/////////////////////////////////////////////////////////////////////////////////
// Typedefs
/////////////////////////////////////////////////////////////////////////////////
typedef struct myrgbcolor_t
{
	uint16_t duration;					// Duration as tics, right now 100 ms = 1 tick
	uint16_t red;
	uint16_t blue;
	uint16_t green;	
	myfixedpoint32_t gain;				
} myrgbcolor_t;

/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////

uint8_t addToLigthPattern(myrgbcolor_t *color);
void enableLightCnt();
void disableLightCnt();

#endif /* XMEGA_MODULES_LIGTHCNTRL_H_ */