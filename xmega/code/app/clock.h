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

#include <stdint.h>

struct Time {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t zone;
    uint32_t posix;
};

void clock_time_set(struct Time * time);
struct Time * clock_time_get(void);
void clock_alarm_set(struct Time * time);
struct Time * clock_alarm_get(void);
void clock_draw(uint16_t x, uint16_t y);
void clock_init(void);
void clock_deinit(void);
#endif /* CLOCK_H_ */