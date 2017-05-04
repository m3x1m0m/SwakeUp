/*
 * timer.h
 *
 * Created: 11/14/2016 1:11:16 AM
 *  Author: elmar
 */


#ifndef TIMER_H_
#define TIMER_H_

#include "../../util/event.h"
#include "../../util/module.h"

EVENT_EXP(EVENT_TIMER_1_HZ);
EVENT_EXP(EVENT_ALARM);

uint16_t timer_runTime(void);
int8_t   timer_timeOutEvent(uint16_t duration);

MODULE_EXP(TIMER);

#endif /* TIMER_H_ */