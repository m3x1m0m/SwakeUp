/*
 * status.c
 *
 * Created: 5/13/2017 4:23:01 PM
 *  Author: elmar
 */

#include "status.h"
#include "app.h"
#include "../defines.h"
#include "../modules/screen.h"
#include "../sprites.h"
#include "../drivers/host/timer.h" //TODO remove, just for testing purposes

#define GRID_SIZE       32
#define ICON_X(index)   (GRID_SIZE - SPRITE_ICON_WIDTH)/2 + (GRID_SIZE * index)
#define ICON_Y          (GRID_SIZE - SPRITE_ICON_WIDTH)/2
#define DRAW_ALARM      (1<<0)
#define DRAW_WIFI       (1<<1)
#define DRAW_LIGHT      (1<<2)
#define UPDATE_WIFI     (1<<3)

#define ALARM_INDEX     0
#define WIFI_INDEX      1
#define LIGHT_INDEX     2

static void move(uint16_t x, uint16_t y) {
}

APP_CREATE("Status", move);

uint8_t wifiStrength = 0;
uint8_t drawMask = DRAW_WIFI | DRAW_LIGHT | DRAW_ALARM;
uint8_t prevDrawMask = 0;
uint8_t searching = 1;
uint8_t searchingUp = 1;
static void draw(void) {
    if (APP_ISENABLED) {
        if (drawMask & DRAW_ALARM && ((prevDrawMask & DRAW_ALARM) != (drawMask & DRAW_ALARM))) {
            screen_sub_image(&sprite_icons, xx + ICON_X(ALARM_INDEX), yy + ICON_Y, SPRITE_ICON_WIDTH * SPRITE_ICON_ALARM, 0, SPRITE_ICON_SIZE);
        } else if ((prevDrawMask & DRAW_ALARM) != (drawMask & DRAW_ALARM)) {
            screen_draw_begin(FILLED);
            screen_color(COLOR_TO656(0, 0, 0));
            screen_rect(xx + ICON_X(ALARM_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
            screen_draw_end();
        }
        if (drawMask & UPDATE_WIFI || ((drawMask & DRAW_WIFI) && ((prevDrawMask & DRAW_WIFI) != (drawMask & DRAW_WIFI)))) {
            if (drawMask & UPDATE_WIFI) {
                screen_draw_begin(FILLED);
                screen_color(COLOR_TO656(0, 0, 0));
                screen_rect(xx + ICON_X(WIFI_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
                screen_draw_end();
                drawMask &= ~(UPDATE_WIFI);
            }
            if (wifiStrength == 3) {
                screen_sub_image(&sprite_icons, xx + ICON_X(WIFI_INDEX), yy + ICON_Y, SPRITE_ICON_WIDTH * SPRITE_ICON_WIFI_3, 0, SPRITE_ICON_SIZE);
            } else if (wifiStrength == 2) {
                screen_sub_image(&sprite_icons, xx + ICON_X(WIFI_INDEX), yy + ICON_Y, SPRITE_ICON_WIDTH * SPRITE_ICON_WIFI_2, 0, SPRITE_ICON_SIZE);
            } else if (wifiStrength == 1) {
                screen_sub_image(&sprite_icons, xx + ICON_X(WIFI_INDEX), yy + ICON_Y, SPRITE_ICON_WIDTH * SPRITE_ICON_WIFI_1, 0, SPRITE_ICON_SIZE);
            }
        } else if ((prevDrawMask & DRAW_WIFI) != (drawMask & DRAW_WIFI)) {
            screen_draw_begin(FILLED);
            screen_color(COLOR_TO656(0, 0, 0));
            screen_rect(xx + ICON_X(WIFI_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
            screen_draw_end();
        }
        if (drawMask & DRAW_LIGHT && ((prevDrawMask & DRAW_LIGHT) != (drawMask & DRAW_LIGHT))) {
            screen_sub_image(&sprite_icons, xx + ICON_X(LIGHT_INDEX), yy + ICON_Y, SPRITE_ICON_WIDTH * SPRITE_ICON_LIGHT, 0, SPRITE_ICON_SIZE);
        } else if ((prevDrawMask & DRAW_LIGHT) != (drawMask & DRAW_LIGHT)) {
            screen_draw_begin(FILLED);
            screen_color(COLOR_TO656(0, 0, 0));
            screen_rect(xx + ICON_X(LIGHT_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
            screen_draw_end();
        }
#ifdef BOUNDARY_BOX
        screen_draw_begin(LINE);
        screen_color(COLOR_TO656(30, 240, 30));
        screen_rect(APP_POS, ww - 2, hh);
        screen_rect(xx + ICON_X(LIGHT_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
        screen_rect(xx + ICON_X(WIFI_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
        screen_rect(xx + ICON_X(ALARM_INDEX), yy + ICON_Y, SPRITE_ICON_SIZE);
        screen_draw_end();
#endif
    }
    prevDrawMask = drawMask;
}

void status_wifi(uint8_t strength) {
    if (strength > 0 ) {
        drawMask |= UPDATE_WIFI;
        drawMask |= DRAW_WIFI;
    } else {
        drawMask &= ~(UPDATE_WIFI);
        drawMask &= ~(DRAW_WIFI);
    }
    wifiStrength = strength;
    draw();
}
void status_alarm(uint8_t on) {
    if (on) drawMask |= DRAW_ALARM;
    else drawMask &= ~(DRAW_ALARM);
    draw();
}
void status_light(uint8_t on) {
    if (on) drawMask |= DRAW_LIGHT;
    else drawMask &= ~(DRAW_LIGHT);
    draw();
}
static void callback(Event * event, uint8_t * data) {
    if (searching) {
        if (searchingUp) {
            wifiStrength++;
            if (wifiStrength == 3) searchingUp = 0;
        } else {
            wifiStrength--;
            if (wifiStrength == 0) searchingUp = 1;
        }
        status_wifi(wifiStrength);
    }
}
void status_init(uint16_t x, uint16_t y) {
    APP_SET_POS(x, y);
    APP_SET_BOUNDS(STATUS_WIDTH, STATUS_HEIGHT);
    APP_ENABLE(true);
    draw();
    event_addListener(&EVENT_TIMER_1_HZ, &callback);
}
void status_deinit(void) {
    APP_ENABLE(false);
}