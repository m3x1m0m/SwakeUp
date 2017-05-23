/////////////////////////////////////////////////////////////////////////////////
// PID controller module with slots for different controllers. The whole module
// i.e. every controller is executed in a certain interval.
//
// Author:				Maximilian Stiefel
// Last Modification:	19.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../modules/log.h"
#include "../../util/fixedpoint.h"
#include "../../defines.h"
#include "pid.h"
#include "adc.h"
#include "pwm.h"
#include "../uart/terminal.h"
#include <avr/pgmspace.h>

LOG_INIT("PID");

/////////////////////////////////////////////////////////////////////////////////
// Global Variables
/////////////////////////////////////////////////////////////////////////////////
static uint8_t nuOfControllers = 0;
static mycontroller_t *controllers[NU_OF_CONTROLLER_SLOTS];

#if defined(PID_PRINT_MODE_LVL3) || defined(PID_PRINT_MODE_LVL4)	
static uint16_t debugMem[DEBUG_MEM_SIZE];
static uint8_t debugMemInd = 0;
#endif

/////////////////////////////////////////////////////////////////////////////////
// Hook  for event which runs all PID controllers
/////////////////////////////////////////////////////////////////////////////////
static void pid(Event * event, uint8_t * data __attribute__ ((unused))) {
	// Variables
	int32_t actualValue = 0;
	uint16_t setPoint = 0;
	
	myfixedpoint32_t error = 0;
	myfixedpoint32_t proportional = 0;
	myfixedpoint32_t integral = 0;
	myfixedpoint32_t derivative = 0;
	myfixedpoint32_t drive = 0;
	myfixedpoint32_t previousError = 0;
	myfixedpoint32_t kp = 0;
	myfixedpoint32_t ki = 0;
	myfixedpoint32_t kd = 0;
	
	//Action
	if (event == &EVENT_TIMER_100_HZ) {
		for(int i=0; i < nuOfControllers; i++)
		{
			if( !(controllers[i]->enabled) ) continue;									// PID is not enabled
			actualValue = controllers[i]->getSensorVal();								// Get values from struct
			setPoint = controllers[i]->setPoint;
			previousError = controllers[i]->previousError;
			integral = controllers[i]->integral;
			kp = controllers[i]->kp;
			ki = controllers[i]->ki;
			kd = controllers[i]->kd;
			
			if (actualValue < 0) actualValue = 0;										// Prevent shit from happening
			error = FROMINT(setPoint) - FROMINT(actualValue);
			proportional = fixedPt_mul(error,kp);
			integral = integral + fixedPt_mul(error,DT);
			integral = fixedPt_mul(integral, ki);
			derivative = error-previousError;
			derivative = fixedPt_mul(derivative, kd);
			drive = proportional + integral + derivative;
			if(drive < 0) drive = 0;													// Prevent shit from happening
			controllers[i]->setActuatorVal(TOUINT16T(drive));
		
			#ifdef PID_PRINT_MODE_LVL2													// Optional printout
			LOG_DEBUG("error: %d", error);
			LOG_DEBUG("previousError: %d", previousError);
			LOG_DEBUG("actualValue: %d", actualValue);
			LOG_DEBUG("set Point: %d", setPoint);
			LOG_DEBUG("proportional: %d", proportional);
			LOG_DEBUG("integral: %d", integral);
			LOG_DEBUG("derivative: %d", TOUINT16T(derivative));
			LOG_DEBUG("drive: %d", TOUINT16T(drive));
			LOG_DEBUG("------------");
			#endif
			
			#ifdef PID_PRINT_MODE_LVL1													// Optional printout
			LOG_DEBUG("actualValue: %d", actualValue);
			LOG_DEBUG("drive: %d", TOUINT16T(drive));
			LOG_DEBUG("------------");
			#endif
			
			#ifdef PID_PRINT_MODE_LVL3															// Optional printout
			LOG_DEBUG("error: %d", error);
			LOG_DEBUG("previousError: %d", previousError);
			LOG_DEBUG("actualValue: %d", actualValue);
			LOG_DEBUG("set Point: %d", setPoint);
			LOG_DEBUG("proportional: %d", proportional);
			LOG_DEBUG("integral: %d", integral);
			LOG_DEBUG("derivative: %d", TOUINT16T(derivative));
			LOG_DEBUG("drive: %d", TOUINT16T(drive));
			LOG_DEBUG("------------");
			if (debugMemInd < DEBUG_MEM_SIZE){
				debugMem[debugMemInd++] = (uint16_t)actualValue;											// Save values
			}
			else
			{
				for (int i=0; i < DEBUG_MEM_SIZE; i++)
				{			
					if(i == (DEBUG_MEM_SIZE-1) )
					{
						terminal_write("%d", debugMem[i]);
					}
					else
					{
						terminal_write("%d, ", debugMem[i]);
					}
				}
				terminal_write("\r\n", debugMem[i]);
				debugMemInd = 0;																// Overwrite old values
			}
			#endif
			
			#ifdef PID_PRINT_MODE_LVL4													
			if (debugMemInd < DEBUG_MEM_SIZE){
				debugMem[debugMemInd++] = (uint16_t)actualValue;											// Save values
			}
			else
			{
				for (int i=0; i < DEBUG_MEM_SIZE; i++)
				{
					if(i == (DEBUG_MEM_SIZE-1) )
					{
						terminal_write("%d", debugMem[i]);
					}
					else
					{
						terminal_write("%d, ", debugMem[i]);
					}
				}
				terminal_write("\r\n", debugMem[i]);
				debugMemInd = 0;																// Overwrite old values
			}
			#endif
			
			controllers[i]->integral = integral;
			controllers[i]->previousError = error;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Add PID controller
/////////////////////////////////////////////////////////////////////////////////
void add_Controller(mycontroller_t *newController)
{
	if(nuOfControllers < NU_OF_CONTROLLER_SLOTS)
	{
		controllers[nuOfControllers++] = newController;
		LOG_DEBUG("New controller added.");
	}
	else
	{
		LOG_DEBUG("All controller slots are used already.");
	}
}


/////////////////////////////////////////////////////////////////////////////////
// Start PID controller
/////////////////////////////////////////////////////////////////////////////////
void start_PID(void)
{
	LOG_DEBUG("PID started.");
	event_addListener(&EVENT_TIMER_100_HZ, pid);
}

/////////////////////////////////////////////////////////////////////////////////
// Stop PID controller
/////////////////////////////////////////////////////////////////////////////////
void stop_PID(void)
{
	LOG_DEBUG("PID stopped.");
	event_removeListener(&EVENT_TIMER_100_HZ, pid);
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init(void)
{
	start_PID();
	return 1;
}

static uint8_t deinit(void)
{
	stop_PID();
	return 1;
}

MODULE_DEFINE(PID, "PID Controller", &init, &deinit, &PWM, &ADC);