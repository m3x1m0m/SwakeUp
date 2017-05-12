/*
 * weather.h
 *
 * Created: 3/1/2017 1:02:14 AM
 *  Author: elmar
 */


#ifndef WEATHER_H_
#define WEATHER_H_

#include "../util/protobuf/swakeup.pb.h"

void weather_set(Weather weather);
Weather weather_get(void);
void weather_draw(void);
void weather_init(uint16_t drawX, uint16_t drawY);
void weather_deinit(void);

#endif /* WEATHER_H_ */