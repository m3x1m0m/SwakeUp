/////////////////////////////////////////////////////////////////////////////////
//
//
// Author:				Maximilian Stiefel
// Last Modification:	16.05.2017
/////////////////////////////////////////////////////////////////////////////////

#include <avr/io.h>
#include "pid.h"
#include <stdarg.h>

void init_PID()
{
	
}

MODULE_DEFINE(PID, "PID Controller", init, deinit, &PWM, &ADC);

