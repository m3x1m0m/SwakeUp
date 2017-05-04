/*
 * core.h
 *
 * Created: 3/1/2017 12:29:48 AM
 *  Author: elmar
 */


#ifndef CORE_H_
#define CORE_H_

#include "../util/event.h"
#include "../util/module.h"
#include "../modules/timekeeper.h"

/** This event will get fired when a time change request occurs */
EVENT_EXP(TIME_CHANGE);
/** This event will get fired when a weather change request occurs */
EVENT_EXP(WEATHER_CHANGE);
/** This event will get fired when a social media change request occurs */
EVENT_EXP(SOCIAL_MEDIA);

void core_time_set(uint8_t h, uint8_t m, uint8_t s);
void core_time_get(struct TimeKeeper * time);
void core_screen(uint8_t on);

MODULE_EXP(CORE);

#endif /* CORE_H_ */
