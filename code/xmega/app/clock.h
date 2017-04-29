/*
 * clock.h
 *
 * Created: 3/1/2017 12:29:56 AM
 *  Author: elmar
 */


#ifndef CLOCK_H_
#define CLOCK_H_

#define CLOCK_WIDTH         96
#define CLOCK_HEIGHT        96
#define CLOCK_CENTER        48

#define CLOCK_SECOND_LEN    48
#define CLOCK_MINUTE_LEN    40
#define CLOCK_HOUR_LEN      32

#define CLOCK_ANALOGUE      0

#include <stdint.h>
#include "core.h"

void clock_time_set(struct TimeKeeper * time);
struct TimeKeeper * clock_time_get(void);
void clock_alarm_set(struct TimeKeeper * time);
struct TimeKeeper * clock_alarm_get(void);
void clock_draw();
void clock_init(uint16_t drawX, uint16_t drawY);
void clock_deinit(void);
#endif /* CLOCK_H_ */