/////////////////////////////////////////////////////////////////////////////////
// PID controller to run with a certain frequency.
//
// Author:				Maximilian Stiefel
// Last Modification:	16.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../modules/log.h"
#include "../../util/fixedpoint.h"
#include "adc.h"
#include "pwm.h"
#include "pid.h"

LOG_INIT("PID");

/////////////////////////////////////////////////////////////////////////////////
// Global Variables
/////////////////////////////////////////////////////////////////////////////////
uint16_t setPoint = 0;

/////////////////////////////////////////////////////////////////////////////////
// Hook  for 100 Hz event (actual PID algorithm)
/////////////////////////////////////////////////////////////////////////////////
static void pid(Event * event, uint8_t * data __attribute__ ((unused))) {
	//Variables
	static volatile myfixedpoint32_t drive = 0;
	static volatile myfixedpoint32_t previousError = 0;
	static volatile myfixedpoint32_t integral = 0;
	
	myfixedpoint32_t error = 0;
	myfixedpoint32_t derivative = 0;
	myfixedpoint32_t proportional = 0;
	int16_t actualValue = 0;
	
	//Action
	if (event == &EVENT_TIMER_1_HZ) {
		actualValue = getVal_ADCOLED();
		if (actualValue < 0) actualValue = 0;
		error = FROMINT(setPoint) - FROMINT(actualValue);
		proportional = fixedPt_mul(error,KP);
		integral = integral + fixedPt_mul(error,DT);
		integral = fixedPt_mul(integral, KI);
		derivative = error-previousError;
		derivative = fixedPt_mul(derivative, KD);
		drive = proportional + integral + derivative;
		if(drive < 0) drive = 0;
		setDutyCycle_PWMOLED(TOUINT16T(drive));
		#ifdef PID_PRINT_MODE
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
		previousError = error;

	}
}

/////////////////////////////////////////////////////////////////////////////////
// Start PID controller
/////////////////////////////////////////////////////////////////////////////////
void start_PID(uint16_t isetpoint)
{
	LOG_DEBUG("PID started.");
	setPoint = isetpoint;
	event_addListener(&EVENT_TIMER_1_HZ, pid);
}

/////////////////////////////////////////////////////////////////////////////////
// Stop PID controller
/////////////////////////////////////////////////////////////////////////////////
void stop_PID()
{
	LOG_DEBUG("PID stopped.");
	event_removeListener(&EVENT_TIMER_1_HZ, pid);
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init(void)
{
	start_PID(200);
	return EXIT_SUCCESS;
}

static uint8_t deinit(void)
{
	return EXIT_SUCCESS;
}

MODULE_DEFINE(PID, "PID Controller", &init, &deinit);