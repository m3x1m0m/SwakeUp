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

#define TIMEKEEPER_UPDATE_HOUR_BP        (1<<0)
#define TIMEKEEPER_UPDATE_MIN_BP         (1<<1)
#define TIMEKEEPER_UPDATE_SEC_BP         (1<<2)
#define TIMEKEEPER_UPDATE_YEAR_BP        (1<<3)
#define TIMEKEEPER_UPDATE_MONTH_BP       (1<<4)
#define TIMEKEEPER_UPDATE_DAY_BP         (1<<5)
#define TIMEKEEPER_UPDATE_ALARM_BP       (1<<6)
#define TIMEKEEPER_UPDATE_NOTHING        (0x00)
#define TIMEKEEPER_UPDATE_TIME           TIMEKEEPER_UPDATE_HOUR_BP | TIMEKEEPER_UPDATE_MIN_BP   | TIMEKEEPER_UPDATE_SEC_BP
#define TIMEKEEPER_UPDATE_DATE           TIMEKEEPER_UPDATE_YEAR_BP | TIMEKEEPER_UPDATE_MONTH_BP | TIMEKEEPER_UPDATE_DAY_BP | TIMEKEEPER_UPDATE_ALARM_BP
#define TIMEKEEPER_UPDATE_ALL            TIMEKEEPER_UPDATE_TIME    | TIMEKEEPER_UPDATE_DATE     | TIMEKEEPER_UPDATE_ALARM_BP

#define TIMEKEEPER_DAYS_MONDAY          (1<<1)
#define TIMEKEEPER_DAYS_TUESDAY         (1<<2)
#define TIMEKEEPER_DAYS_WEDNESDAY       (1<<3)
#define TIMEKEEPER_DAYS_THURSDAY        (1<<4)
#define TIMEKEEPER_DAYS_FRIDAY          (1<<5)
#define TIMEKEEPER_DAYS_SATURDAY        (1<<6)
#define TIMEKEEPER_DAYS_SUNDAY          (1<<7)

#define TIMEKEEPER_MONTHS_JANUARY       1
#define TIMEKEEPER_MONTHS_FEBRUARY      2
#define TIMEKEEPER_MONTHS_MARCH         3
#define TIMEKEEPER_MONTHS_APRIL         4
#define TIMEKEEPER_MONTHS_MAY           5
#define TIMEKEEPER_MONTHS_JUNE          6
#define TIMEKEEPER_MONTHS_JULY          7
#define TIMEKEEPER_MONTHS_AUGUST        8
#define TIMEKEEPER_MONTHS_SEPTEMBER     9
#define TIMEKEEPER_MONTHS_OCTOBER       10
#define TIMEKEEPER_MONTHS_NOVEMBER      11
#define TIMEKEEPER_MONTHS_DECEMBER      12


struct timekeepertime_s {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t zone;   // This is handled on the ESP, TODO remove?
    uint8_t amPm;   //1 am, 2 pm, 3 24 hours display
};

struct timekeeperdate_s {
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t week;
};

struct timekeeperalarm_s {
    uint8_t days;
    struct timekeepertime_s time;
};

typedef struct timekeeper_s {
    struct timekeepertime_s time;
    struct timekeeperdate_s date;
    struct timekeeperalarm_s alarm; //TODO make this alarms!!
    uint32_t posix;
} TimeKeeper;



void timekeeper_time_set(uint8_t h, uint8_t m, uint8_t s);
void timekeeper_date_set(uint8_t y, uint8_t m, uint8_t d);
void timekeeper_alarm_set(uint8_t days, struct timekeepertime_s time); //TODO multiple alarms
void timekeeper_set(uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s);

struct timekeepertime_s timekeeper_time_get(void);
struct timekeeperdate_s timekeeper_date_get(void);
struct timekeeperalarm_s timekeeper_alarm_get(void);
TimeKeeper timekeeper_get(void);
/** This event will get fired when a time change request occurs */
EVENT_EXP(TIME_CHANGE);
EVENT_EXP(ALARM);

MODULE_EXP(TIME);



#endif /* TIMEKEEPER_H_ */