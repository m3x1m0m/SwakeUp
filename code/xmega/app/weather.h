/*
 * weather.h
 *
 * Created: 3/1/2017 1:02:14 AM
 *  Author: elmar
 */


#ifndef WEATHER_H_
#define WEATHER_H_

enum Weather {
    SUN, CLOUDS, OVERCAST, SNOW, RAIN, THUNDER
};

void weather_set(enum Weather weather);
enum Weather weather_get(void);
void weather_draw(void);
void weather_init(uint16_t drawX, uint16_t drawY);
void weather_deinit(void);

#endif /* WEATHER_H_ */