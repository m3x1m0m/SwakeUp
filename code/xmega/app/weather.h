/*
 * weather.h
 *
 * Created: 3/1/2017 1:02:14 AM
 *  Author: elmar
 */


#ifndef WEATHER_H_
#define WEATHER_H_

#include "../util/protobuf/swakeup.pb.h"
#include "../util/event.h"

#define WEATHER_ICON_WIDTH  32
#define WEATHER_ICON_HEIGHT 32
#define WEATHER_INFO_WIDTH  32
#define WEATHER_INFO_HEIGHT 32
#define WEATHER_APP_WIDTH   WEATHER_ICON_WIDTH + WEATHER_INFO_WIDTH
#define WEATHER_APP_HEIGHT  32

/** This event will get fired when a weather change request occurs */
EVENT_EXP(WEATHER_CHANGE);

void weather_set(Weather weather);
Weather weather_get(void);
void weather_draw(void);
void weather_init(uint16_t drawX, uint16_t drawY);
void weather_deinit(void);

#endif /* WEATHER_H_ */