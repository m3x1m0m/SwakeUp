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

/** This event will get fired when a social media change request occurs */
EVENT_EXP(SOCIAL_MEDIA);

#define DRAW_CLOCK		1
#define DRAW_WEATHER	1
#define DRAW_STATUS		1
#define DRAW_MAIL		0

#define APP_CLOCK_X     64
#define APP_CLOCK_Y     32

#define APP_WEATHER_X   0
#define APP_WEATHER_Y   96

#define APP_STATUS_X    64
#define APP_STATUS_Y    0

#define APP_MAIL_X      0
#define APP_MAIL_Y      0
//void core_time_set(uint8_t h, uint8_t m, uint8_t s);

//void core_time_get(struct TimeKeeper * time);
void core_screen(uint8_t on);

MODULE_EXP(CORE);

#endif /* CORE_H_ */
