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
EVENT_REGISTER(ALARM, "Wakeup Alarm");

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

void checkAlarm(void)
{
	LOG_DEBUG("Day: %d, %d", timeKeeper.date.day, timeKeeper.alarm.days);
	LOG_DEBUG("Hour: %d, %d", timeKeeper.time.hour, timeKeeper.alarm.time.hour);
	LOG_DEBUG("Minute: %d, %d", timeKeeper.time.minute, timeKeeper.alarm.time.minute);
	if ( (timeKeeper.date.day & timeKeeper.alarm.days) &&\
	(timeKeeper.time.hour == timeKeeper.alarm.time.hour) &&\
	(timeKeeper.time.minute == timeKeeper.alarm.time.minute) )
	{
		event_fire(&ALARM, 0);
	}
}

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
    if (event == &EVENT_TIMER_1_HZ) {
		checkAlarm();
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
    if (h != timeKeeper.time.hour) updated |= TIMEKEEPER_UPDATE_HOUR_BP;
    if (m != timeKeeper.time.minute) updated |= TIMEKEEPER_UPDATE_MIN_BP;
    if (s != timeKeeper.time.second) updated |= TIMEKEEPER_UPDATE_SEC_BP;
    timeKeeper.time.hour = h;
    timeKeeper.time.minute = m;
    timeKeeper.time.second = s;
    LOG_SYSTEM("Time set to: %d:%d:%d", h, m, s);
    event_fire(&TIME_CHANGE, (void *)updated);
    updated = TIMEKEEPER_UPDATE_NOTHING;
}

void timekeeper_date_set(uint8_t y, uint8_t m, uint8_t d) {
    timeKeeper.date.year = y;
    timeKeeper.date.month = m;
    timeKeeper.date.day = d;
    updated = TIMEKEEPER_UPDATE_DATE;
    LOG_SYSTEM("Date set to: 2000 + %d:%d:%d", y, m, d);
    event_fire(&TIME_CHANGE, (void *)updated);
    updated = TIMEKEEPER_UPDATE_NOTHING;
}

void timekeeper_alarm_set(uint8_t days, struct timekeepertime_s time) {
    timeKeeper.alarm.days = days;
    timeKeeper.alarm.time = time;
}

uint8_t monthHash(char *month)
{
	uint8_t result = 0;
	for(int i=0; i < 3; i++)
	{
		result+=month[i];
	}
	return result;
}

uint8_t getPrepSeconds(char *time){
	return ( (time[6]-48)*10 + (time[7]-48) );
}

uint8_t getPrepMinutes(char *time){
	return ( (time[3]-48)*10 + (time[4]-48) );
}

uint8_t getPrepHours(char *time){
	return ( (time[0]-48)*10 + (time[1]-48) );
}

uint8_t getPrepDay(char *date){
	return (  ( (date[4] == ' ')? 0 : date[4]-48 ) * 10 + (date[5]-48) );
}

uint8_t getPrepMonth(char *date){
	uint8_t dateHash = monthHash(date);
	switch(dateHash)
	{
		case TIMEKEEPER_HASH_JANUARY:
		return 1;
		break;
		case TIMEKEEPER_HASH_FEBRUARY:
		return 2;
		break;
		case TIMEKEEPER_HASH_MARCH:
		return 3;
		break;
		case TIMEKEEPER_HASH_APRIL:
		return 4;
		break;
		case TIMEKEEPER_HASH_MAY:
		return 5;
		break;
		case TIMEKEEPER_HASH_JUNE:
		return 6;
		break;
		case TIMEKEEPER_HASH_JULY:
		return 7;
		break;
		case TIMEKEEPER_HASH_AUGUST:
		return 8;
		break;
		case TIMEKEEPER_HASH_SEPTEMBER:
		return 9;
		break;
		case TIMEKEEPER_HASH_OCTOBER:
		return 10;
		break;
		case TIMEKEEPER_HASH_NOVEMBER:
		return 11;
		break;
		case TIMEKEEPER_HASH_DECEMBER:
		return 12;
		break;
	}
}

uint8_t getPrepYear(char *date)
{
	return ( (date[9]-48)*10 + (date[10]-48) );
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
    timekeeper_set(getPrepYear(__DATE__), getPrepMonth(__DATE__), \
	getPrepDay(__DATE__), getPrepHours(__TIME__), \
	getPrepMinutes(__TIME__), getPrepSeconds(__TIME__));                   // THE YEAR IS 2000/1/1
    timeKeeper.time.amPm = 3;
    return 1;
}
static uint8_t deinit(void) {
    event_removeListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    return 1;
}

MODULE_DEFINE(TIME, "Time keeper", init, deinit, &TIMER);