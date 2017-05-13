/*
 * clock_2.c
 *
 * Created: 5/13/2017 10:47:28 AM
 *  Author: elmar
 */

#include "../modules/timekeeper.h"
#include "../modules/screen.h"
#include "../util/number.h"
#include "clock.h"

static uint8_t screenEnabled = 0;
static uint16_t x, y;

static uint16_t bckgrColor = COLOR_TO656(0, 0, 0);


#define CLOCK_DISPLAY_LARGE         (1<<0)
#define CLOCK_DISPLAY_SMALL         (1<<1)
#define CLOCK_DISPLAY_ALARM         (1<<2)
#define CLOCK_DISPLAY_DATE          (1<<3)
#define CLOCK_DISPLAY_NOTHING       (0x00)
#define CLOCK_DISPLAY_ALL           (CLOCK_DISPLAY_LARGE | CLOCK_DISPLAY_SMALL | CLOCK_DISPLAY_ALARM | CLOCK_DISPLAY_DATE)

static uint8_t displayWhat =    CLOCK_DISPLAY_NOTHING;

void clock_draw(uint8_t update, uint8_t display) {
    //hour : min : sec + \0
    //day/month/year + \0
    char clockbuf[11];
    if (update & TIMEKEEPER_UPDATE_TIME) {
        struct timekeepertime_s displayTime = timekeeper_time_get();
        if (display & CLOCK_DISPLAY_LARGE && (update & TIMEKEEPER_UPDATE_HOUR_BP || update & TIMEKEEPER_UPDATE_MIN_BP)) {
            screen_draw_begin(FILLED);
            screen_color(bckgrColor);
            if (display & CLOCK_DISPLAY_SMALL && (update & TIMEKEEPER_UPDATE_HOUR_BP || update & TIMEKEEPER_UPDATE_MIN_BP || update & TIMEKEEPER_UPDATE_SEC_BP)) {
                clockbuf[0] = displayTime.hour / 10 + '0';
                clockbuf[1] = displayTime.hour % 10 + '0';
                clockbuf[2] = ':';
                clockbuf[3] = displayTime.minute / 10 + '0';
                clockbuf[4] = displayTime.minute % 10 + '0';
                clockbuf[5] = ':';
                clockbuf[6] = displayTime.second / 10 + '0';
                clockbuf[7] = displayTime.second % 10 + '0';
                screen_color(COLOR_TO656(255, 255, 255));
                screen_text(clockbuf, 8, 160 - 8 * 8, y + CLOCK_HEIGHT + 1);
            }
            if (update & TIMEKEEPER_UPDATE_HOUR_BP) {
                screen_rect(x, y + 10, 24, 60);
                screen_sub_image(&numberImg, x, y + 10, (displayTime.hour / 10) * 24, 0, 24, 60);
                screen_rect(x + 24 * 1, y + 10, 24, 60);
                screen_sub_image(&numberImg, x + 24, y + 10, (displayTime.hour % 10) * 24, 0, 24, 60);
            }
            if (update & TIMEKEEPER_UPDATE_MIN_BP) {
                screen_rect(x + 24 * 2, y + 10, 24, 60);
                screen_sub_image(&numberImg, x + 48, y + 10, (displayTime.minute / 10) * 24, 0, 24, 60);
                screen_rect(x + 24 * 3, y + 10, 24, 60);
                screen_sub_image(&numberImg, x + 72, y + 10, (displayTime.minute % 10) * 24, 0, 24, 60);
            }
            screen_draw_end();
        }
    }
    if (display & CLOCK_DISPLAY_ALARM && update & TIMEKEEPER_UPDATE_ALARM_BP) {
        struct timekeeperalarm_s alarm = timekeeper_alarm_get();
        clockbuf[0] = alarm.time.hour / 10 + '0';
        clockbuf[1] = alarm.time.hour % 10 + '0';
        clockbuf[2] = ':';
        clockbuf[3] = alarm.time.minute / 10 + '0';
        clockbuf[4] = alarm.time.minute % 10 + '0';
        clockbuf[5] = ':';
        clockbuf[6] = alarm.time.second / 10 + '0';
        clockbuf[7] = alarm.time.second % 10 + '0';
        screen_color(COLOR_TO656(200, 80, 120));
        screen_text(clockbuf, 8, 160 - 8 * 8, y + CLOCK_HEIGHT + 1 + 8);
        screen_color(COLOR_TO656(255, 255, 255));
    }
    if (update & TIMEKEEPER_UPDATE_DATE) {
        struct timekeeperdate_s data = timekeeper_date_get();
        //2000/01/01
        snprintf(clockbuf, 11, "20%02d/%02d/%02d", data.year, data.month, data.day);
        screen_color(COLOR_TO656(200, 30, 50));
        screen_text(clockbuf, 10, 160 - 8 * 10, y + CLOCK_HEIGHT + 1 + 8 + 8);
        screen_color(COLOR_TO656(255, 255, 255));
    }
}
static void callback(Event * event, uint8_t * data) {
    if (event == &TIME_CHANGE && screenEnabled) {
        clock_draw((uint8_t)data, displayWhat);
    }
}
void clock_init_screen(uint16_t drawX, uint16_t drawY, uint8_t on) {
    x = drawX;
    y = drawY;
    screenEnabled = on;
    displayWhat = CLOCK_DISPLAY_ALL;
}
void clock_init(void) {
    event_addListener(&TIME_CHANGE, callback);
}
void clock_deinit(void) {
    event_removeListener(&TIME_CHANGE, callback);
    displayWhat = CLOCK_DISPLAY_NOTHING;
}