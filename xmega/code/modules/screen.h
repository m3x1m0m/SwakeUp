/*
 * screen.h
 *
 * Created: 11/12/2016 6:01:50 PM
 *  Author: elmar
 */ 


#ifndef SCREEN_H_
#define SCREEN_H_

#include "../util/module.h"

#define SCREEN_WIDTH	128
#define SCREEN_HEIGHT	 64
#define SCREEN_BUFFER	(SCREEN_WIDTH*SCREEN_HEIGHT) / 8

void screen_text(char * text, uint8_t x, uint8_t y);
void screen_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void screen_filled_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void screen_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void screen_pixel(uint8_t x, uint8_t y);
void screen_refresh(void);

MODULE_EXP(Screen);

#endif /* SCREEN_H_ */