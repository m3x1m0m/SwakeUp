/*
 * screen.h
 *
 * Created: 11/12/2016 6:01:50 PM
 *  Author: elmar
 */


#ifndef SCREEN_H_
#define SCREEN_H_

#include "../util/module.h"

#define COLOR_TO656(r,g,b)((r>>3)<<11)|((g>>2)<<5)|(b>>3)
#define COLOR_TO888(r,g,b)((r<<3)<<16)|((g<<2)<<8)|(b<<3)

enum SCREEN_SHAPE_TYPE {
    POINT, FILLED, LINE
};

void screen_draw_begin(enum SCREEN_SHAPE_TYPE type);
void screen_draw_end(void);
void screen_color(uint16_t color);
void screen_text(char * text, uint8_t len, uint16_t x, uint16_t y);
void screen_rect_to(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void screen_rect(uint16_t x1, uint16_t y1, uint16_t width, uint16_t height);
void screen_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void screen_pixel(uint16_t x, uint16_t y);
void screen_circle(uint16_t x, uint16_t y, int radius);


MODULE_EXP(SCREEN);

#endif /* SCREEN_H_ */