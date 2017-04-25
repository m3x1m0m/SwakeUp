/*
 * timekeeper.h
 *
 * Created: 3/3/2017 1:06:47 PM
 *  Author: elmar
 */


#ifndef TIMEKEEPER_H_
#define TIMEKEEPER_H_

#include "../util/event.h"
#include "../util/module.h"

struct TimeKeeper {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t zone;
    uint8_t amPm;   //1 am, 2 pm, 3 24 hours display
    uint32_t posix;
} ;

void timekeeper_time_set(uint8_t h, uint8_t m, uint8_t s);
void timekeeper_time_get(struct TimeKeeper * tim);

MODULE_EXP(TIME);



#endif /* TIMEKEEPER_H_ */