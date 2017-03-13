/*
 * clock.c
 *
 * Created: 3/1/2017 12:34:15 AM
 *  Author: elmar
 */

#include <string.h>
#include <avr/pgmspace.h>

#include "clock.h"
#include "core.h"
#include "../util/event.h"
#include "../modules/log.h"
#include "../modules/screen.h"
#include "../drivers/host/timer.h"  //TODO breach of layering!

LOG_INIT("CLOCK");

static struct Time curTime;
static struct Time prevTime;

static struct Time curAlarm;
static uint8_t alarmEnabled = 0;
static uint8_t clockInitialized = 0;

static uint16_t x = 0, y = 0;

static uint16_t secondColor = COLOR_TO656(255, 0, 0);
static uint16_t minuteColor = COLOR_TO656(0, 255, 0);
static uint16_t hourColor =   COLOR_TO656(0, 0, 255);
static uint16_t bckgrColor = COLOR_TO656(0, 0, 0);
static uint16_t clockColor = COLOR_TO656(20, 30, 160);
#if CLOCK_ANALOGUE
const uint8_t circ48X[60] PROGMEM = {0x30, 0x35, 0x39, 0x3e, 0x43, 0x48, 0x4c, 0x50, 0x53, 0x56, 0x59, 0x5b, 0x5d, 0x5e, 0x5f, 0x60, 0x5f, 0x5e, 0x5d, 0x5b, 0x59, 0x56, 0x53, 0x50, 0x4c, 0x48, 0x43, 0x3e, 0x39, 0x35, 0x30, 0x2a, 0x26, 0x21, 0x1c, 0x18, 0x13, 0x0f, 0x0c, 0x09, 0x06, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x06, 0x09, 0x0c, 0x0f, 0x13, 0x17, 0x1c, 0x21, 0x26, 0x2a};
const uint8_t circ48Y[60] PROGMEM = {0x00, 0x00, 0x01, 0x02, 0x04, 0x06, 0x09, 0x0c, 0x0f, 0x13, 0x18, 0x1c, 0x21, 0x26, 0x2a, 0x30, 0x35, 0x39, 0x3e, 0x43, 0x48, 0x4c, 0x50, 0x53, 0x56, 0x59, 0x5b, 0x5d, 0x5e, 0x5f, 0x60, 0x5f, 0x5e, 0x5d, 0x5b, 0x59, 0x56, 0x53, 0x50, 0x4c, 0x48, 0x43, 0x3e, 0x39, 0x35, 0x30, 0x2a, 0x26, 0x21, 0x1c, 0x17, 0x13, 0x0f, 0x0c, 0x09, 0x06, 0x04, 0x02, 0x01, 0x00};
const uint8_t circ40X[60] PROGMEM = {0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x3f, 0x42, 0x45, 0x48, 0x4a, 0x4c, 0x4e, 0x4f, 0x4f, 0x50, 0x4f, 0x4f, 0x4e, 0x4c, 0x4a, 0x48, 0x45, 0x42, 0x3f, 0x3c, 0x38, 0x34, 0x30, 0x2c, 0x28, 0x23, 0x1f, 0x1b, 0x17, 0x14, 0x10, 0x0d, 0x0a, 0x07, 0x05, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x05, 0x07, 0x0a, 0x0d, 0x10, 0x13, 0x17, 0x1b, 0x1f, 0x23};
const uint8_t circ40Y[60] PROGMEM = {0x00, 0x00, 0x00, 0x01, 0x03, 0x05, 0x07, 0x0a, 0x0d, 0x10, 0x14, 0x17, 0x1b, 0x1f, 0x23, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x3f, 0x42, 0x45, 0x48, 0x4a, 0x4c, 0x4e, 0x4f, 0x4f, 0x50, 0x4f, 0x4f, 0x4e, 0x4c, 0x4a, 0x48, 0x45, 0x42, 0x3f, 0x3c, 0x38, 0x34, 0x30, 0x2c, 0x28, 0x23, 0x1f, 0x1b, 0x17, 0x13, 0x10, 0x0d, 0x0a, 0x07, 0x05, 0x03, 0x01, 0x00, 0x00};
const uint8_t circ32X[60] PROGMEM = {0x20, 0x23, 0x26, 0x29, 0x2d, 0x30, 0x32, 0x35, 0x37, 0x39, 0x3b, 0x3d, 0x3e, 0x3f, 0x3f, 0x40, 0x3f, 0x3f, 0x3e, 0x3d, 0x3b, 0x39, 0x37, 0x35, 0x32, 0x30, 0x2d, 0x29, 0x26, 0x23, 0x20, 0x1c, 0x19, 0x16, 0x12, 0x10, 0x0d, 0x0a, 0x08, 0x06, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0d, 0x0f, 0x12, 0x16, 0x19, 0x1c};
const uint8_t circ32Y[60] PROGMEM = {0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0d, 0x10, 0x12, 0x16, 0x19, 0x1c, 0x20, 0x23, 0x26, 0x29, 0x2d, 0x30, 0x32, 0x35, 0x37, 0x39, 0x3b, 0x3d, 0x3e, 0x3f, 0x3f, 0x40, 0x3f, 0x3f, 0x3e, 0x3d, 0x3b, 0x39, 0x37, 0x35, 0x32, 0x30, 0x2d, 0x29, 0x26, 0x23, 0x20, 0x1c, 0x19, 0x16, 0x12, 0x0f, 0x0d, 0x0a, 0x08, 0x06, 0x04, 0x02, 0x01, 0x00, 0x00};
#else
#include "../util/number.h"
#endif

void clock_time_set(struct Time * time) {
    memcpy(&curTime, time, sizeof(struct Time));
}

struct Time * clock_time_get(void) {
    return &curTime;
}

void clock_alarm_set(struct Time * time) {
    memcpy(&curAlarm, time, sizeof(struct Time));
    alarmEnabled = 1;
    char clockbuf[8];//hour : min : sec + \0
    clockbuf[0] = curAlarm.hour / 10 + '0';
    clockbuf[1] = curAlarm.hour % 10 + '0';
    clockbuf[2] = ':';
    clockbuf[3] = curAlarm.minute / 10 + '0';
    clockbuf[4] = curAlarm.minute % 10 + '0';
    clockbuf[5] = ':';
    clockbuf[6] = curAlarm.second / 10 + '0';
    clockbuf[7] = curAlarm.second % 10 + '0';
    screen_color(COLOR_TO656(200, 30, 50));
    screen_text(clockbuf, 8, 160 - 8 * 8, y + CLOCK_HEIGHT + 1 + 8);
    screen_color(COLOR_TO656(255, 255, 255));
}

struct Time * clock_alarm_get(void) {
    if (alarmEnabled)
        return &curAlarm;
    else
        return (void*)0;
}

void clock_draw() {
    if (clockInitialized) {
#if CLOCK_ANALOGUE
        screen_draw_begin(LINE);
        screen_color(bckgrColor);
        screen_line(x + CLOCK_CENTER, y + CLOCK_CENTER, x + pgm_read_byte(&circ48X[prevTime.second]) , pgm_read_byte(&circ48Y[prevTime.second]));
        screen_line(x + CLOCK_CENTER, y + CLOCK_CENTER, x + pgm_read_byte(&circ40X[prevTime.minute]) + 8, pgm_read_byte(&circ40Y[prevTime.minute]) + 8);
        screen_line(x + CLOCK_CENTER, y + CLOCK_CENTER, x + pgm_read_byte(&circ32X[prevTime.hour]) + 16 , pgm_read_byte(&circ32Y[prevTime.hour]) + 16);
        screen_color(secondColor);
        screen_line(x + CLOCK_CENTER, y + CLOCK_CENTER, x + pgm_read_byte(&circ48X[curTime.second]) , pgm_read_byte(&circ48Y[curTime.second]));
        screen_color(minuteColor);
        screen_line(x + CLOCK_CENTER, y + CLOCK_CENTER, x + pgm_read_byte(&circ40X[curTime.minute]) + 8, pgm_read_byte(&circ40Y[curTime.minute]) + 8);
        screen_color(hourColor);
        screen_line(x + CLOCK_CENTER, y + CLOCK_CENTER, x + pgm_read_byte(&circ32X[curTime.hour]) + 16, pgm_read_byte(&circ32Y[curTime.hour]) + 16);
        screen_color(clockColor);
        screen_rect(x + CLOCK_CENTER - CLOCK_WIDTH / 2, CLOCK_CENTER - CLOCK_HEIGHT / 2, CLOCK_WIDTH, CLOCK_HEIGHT);
        screen_color(COLOR_TO656(255, 255, 255));
        screen_rect(x + CLOCK_CENTER - CLOCK_WIDTH / 2 + 1, CLOCK_CENTER - CLOCK_HEIGHT / 2 + 1, CLOCK_WIDTH - 2, CLOCK_HEIGHT - 2);
        screen_draw_end();
#else
        screen_draw_begin(FILLED);
        screen_color(bckgrColor);
        if ((curTime.hour / 10) != (prevTime.hour / 10)) {
            screen_rect(x, y + 10, 24, 60);
            screen_sub_image(&numberImg, x, y + 10, (curTime.hour / 10) * 24, 0, 24, 60);
        }
        if ((curTime.hour % 10) != (prevTime.hour % 10)) {
            screen_rect(x + 24 * 1, y + 10, 24, 60);
            screen_sub_image(&numberImg, x + 24, y + 10, (curTime.hour % 10) * 24, 0, 24, 60);
        }
        if ((curTime.minute / 10) != (prevTime.minute / 10)) {
            screen_rect(x + 24 * 2, y + 10, 24, 60);
            screen_sub_image(&numberImg, x + 48, y + 10, (curTime.minute / 10) * 24, 0, 24, 60);
        }
        if ((curTime.minute % 10) != (prevTime.minute % 10)) {
            screen_rect(x + 24 * 3, y + 10, 24, 60);
            screen_sub_image(&numberImg, x + 72, y + 10, (curTime.minute % 10) * 24, 0, 24, 60);
        }
        screen_draw_end();
#endif
        memcpy(&prevTime, &curTime, sizeof(struct Time));
    } else {
        LOG_WARNING("Trying to draw, but we are not initialized!");
    }
}

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
#ifndef CLOCK_ANALOGUE
    uint8_t digitalDraw = 0;
#endif
    if (event == &EVENT_TIMER_1_HZ) {
        curTime.second++;
        if (curTime.second > 59) {
#ifndef CLOCK_ANALOGUE
            digitalDraw = 1;
#endif
            curTime.second = 0;
            curTime.minute++;
            if (curTime.minute > 59) {
                curTime.minute = 0;
                curTime.hour++;
                if (curTime.hour > 23) curTime.hour = 0;
            }
        }
    } else if (event == &TIME_CHANGE) {
        clock_time_set((struct Time *)data);
    } else {
        LOG_WARNING("Unkown event %s", event->description);
        return;
    }
    clock_draw();
    char clockbuf[8];//hour : min : sec + \0
    clockbuf[0] = curTime.hour / 10 + '0';
    clockbuf[1] = curTime.hour % 10 + '0';
    clockbuf[2] = ':';
    clockbuf[3] = curTime.minute / 10 + '0';
    clockbuf[4] = curTime.minute % 10 + '0';
    clockbuf[5] = ':';
    clockbuf[6] = curTime.second / 10 + '0';
    clockbuf[7] = curTime.second % 10 + '0';
    screen_color(COLOR_TO656(255, 255, 255));
    screen_text(clockbuf, 8, 160 - 8 * 8, y + CLOCK_HEIGHT + 1);
}

void clock_init(uint16_t drawX, uint16_t drawY) {
    curAlarm.hour = 7;
    curAlarm.minute = 30;
    curAlarm.second = 0;
    x = drawX;
    y = drawY;
    module_init(&SCREEN);
    event_addListener(&EVENT_TIMER_1_HZ, callback);
    event_addListener(&TIME_CHANGE, callback);
    clockInitialized = 1;
    clock_alarm_set(&curAlarm);
}
void clock_deinit(void) {
    module_deinit(&SCREEN);
    event_removeListener(&EVENT_TIMER_1_HZ, callback);
    event_removeListener(&TIME_CHANGE, callback);
    clockInitialized = 0;
}