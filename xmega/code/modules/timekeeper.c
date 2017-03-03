/*
 * timekeeper.c
 *
 * Created: 3/3/2017 1:13:49 PM
 *  Author: elmar
 */
#include "timekeeper.h"
#include "../drivers/host/timer.h"
#include "log.h"

LOG_INIT("Timekeeper");
static struct Time time;

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
    if (++time.second >= 60) {
        time.second = 0;
        if (++time.minute >= 60) {
            time.minute = 0;
            switch (time.amPm) {
            case 1:
                if (++time.hour >= 12) {
                    time.hour = 0;
                    time.amPm = 2;
                }
                break;
            case 2:
                if (++time.hour >= 12) {
                    time.hour = 0;
                    time.amPm = 1;
                }
                break;
            case 3:
                if (++time.hour >= 24) {
                    time.hour = 0;
                }
                break;
            }
        }
    }
}

void timekeeper_time_set(uint8_t h, uint8_t m, uint8_t s) {
    time.hour = h;
    time.minute = m;
    time.second = s;
    LOG_SYSTEM("Time set to: %d:%d:%d", h, m, s);
}


void timekeeper_time_get (struct Time * tim) {
    memcpy(tim, &time, sizeof(struct Time));
}

static uint8_t init(void) {
    event_addListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    return 1;
}
static uint8_t deinit(void) {
    event_removeListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    return 1;
}

MODULE_DEFINE(TIME, "Time keeper", init, deinit, &TIMER);