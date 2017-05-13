/*
 * timekeeper.c
 *
 * Created: 3/3/2017 1:13:49 PM
 *  Author: elmar
 */
#include <string.h>
#include "timekeeper.h"
#include "../drivers/host/timer.h"
#include "log.h"

LOG_INIT("Timekeeper");

EVENT_REGISTER(TIME_CHANGE, "Time and Date change");

static TimeKeeper timeKeeper;

uint8_t updated = TIMEKEEPER_UPDATE_NOTHING;

static uint8_t isLeap(uint8_t year) {
    return year % 4 == 0;
}

static uint8_t days(uint8_t month, uint8_t leap) {
    switch (month) {
    case TIMEKEEPER_MONTHS_JANUARY    :
    case TIMEKEEPER_MONTHS_MARCH      :
    case TIMEKEEPER_MONTHS_MAY        :
    case TIMEKEEPER_MONTHS_JULY       :
    case TIMEKEEPER_MONTHS_AUGUST     :
    case TIMEKEEPER_MONTHS_OCTOBER    :
    case TIMEKEEPER_MONTHS_DECEMBER   :
        return 31;
    case TIMEKEEPER_MONTHS_FEBRUARY   :
        return (leap) ? 29 : 28;
    case TIMEKEEPER_MONTHS_APRIL      :
    case TIMEKEEPER_MONTHS_JUNE       :
    case TIMEKEEPER_MONTHS_SEPTEMBER  :
    case TIMEKEEPER_MONTHS_NOVEMBER   :
        return 30;
    }
    LOG_WARNING("Converting month to days, but unknown month! %d", month);
    return 255;
}

static void updateDayDate(void) {
    uint8_t leap = isLeap(timeKeeper.date.day);
    timeKeeper.date.day++;
    updated |= TIMEKEEPER_UPDATE_DAY_BP;
    if (timeKeeper.date.day > days(timeKeeper.date.month, leap)) {
        timeKeeper.date.day = 0;
        timeKeeper.date.month++;
        updated |= TIMEKEEPER_UPDATE_MONTH_BP;
        if (timeKeeper.date.month > 12) {
            timeKeeper.date.month = 0;
            timeKeeper.date.year++;
            updated |= TIMEKEEPER_UPDATE_YEAR_BP;
        }
    }
}

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
    if (event == &EVENT_TIMER_1_HZ) {
        timeKeeper.time.second++;
        updated |= TIMEKEEPER_UPDATE_SEC_BP;
        if (timeKeeper.time.second >= 60) {
            timeKeeper.time.second = 0;
            timeKeeper.time.minute++;
            updated |= TIMEKEEPER_UPDATE_MIN_BP;
            if (timeKeeper.time.minute >= 60) {
                timeKeeper.time.minute = 0;
                timeKeeper.time.hour++;
                updated |= TIMEKEEPER_UPDATE_HOUR_BP;
                switch (timeKeeper.time.amPm) {
                case 1:
                    if (timeKeeper.time.hour >= 12) {
                        timeKeeper.time.hour = 0;
                        timeKeeper.time.amPm = 2;
                    }
                    break;
                case 2:
                    if (timeKeeper.time.hour >= 12) {
                        timeKeeper.time.hour = 0;
                        timeKeeper.time.amPm = 1;
                        updateDayDate();
                    }
                    break;
                case 3:
                    if (timeKeeper.time.hour >= 24) {
                        timeKeeper.time.hour = 0;
                        updateDayDate();
                    }
                    break;
                }
            }
        }
        event_fire(&TIME_CHANGE, (void *)updated);
        updated = TIMEKEEPER_UPDATE_NOTHING;
    }
}

void timekeeper_time_set(uint8_t h, uint8_t m, uint8_t s) {
    timeKeeper.time.hour = h;
    timeKeeper.time.minute = m;
    timeKeeper.time.second = s;
    updated = TIMEKEEPER_UPDATE_TIME;
    LOG_SYSTEM("Time set to: %d:%d:%d", h, m, s);
    event_fire(&TIME_CHANGE, (void *)updated);
    updated = TIMEKEEPER_UPDATE_NOTHING;
}

void timekeeper_date_set(uint8_t y, uint8_t m, uint8_t d) {
    timeKeeper.date.year = y;
    timeKeeper.date.month = m;
    timeKeeper.date.day = d;
    updated = TIMEKEEPER_UPDATE_DATE;
    LOG_SYSTEM("Time set to: %d:%d:%d", 2000 + y, m, d);
    event_fire(&TIME_CHANGE, (void *)updated);
    updated = TIMEKEEPER_UPDATE_NOTHING;
}

void timekeeper_alarm_set(uint8_t days, struct timekeepertime_s time) {
    timeKeeper.alarm.days = days;
    timeKeeper.alarm.time = time;
}
void timekeeper_set(uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s) {
    timekeeper_time_set(h, mi, s);
    timekeeper_date_set(y, mo, d);
}

struct timekeepertime_s timekeeper_time_get(void) {
    return timeKeeper.time;
}

struct timekeeperdate_s timekeeper_date_get(void) {
    return timeKeeper.date;
}

struct timekeeperalarm_s timekeeper_alarm_get(void) {
    return timeKeeper.alarm;
}

TimeKeeper timekeeper_get (void) {
    return timeKeeper;
}

static uint8_t init(void) {
    event_addListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    timekeeper_set(0, 1, 1, 0, 0, 0);                   // THE YEAR IS 2000/1/1
    timeKeeper.time.amPm = 3;
    return 1;
}
static uint8_t deinit(void) {
    event_removeListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    return 1;
}

MODULE_DEFINE(TIME, "Time keeper", init, deinit, &TIMER);