/*
 * SEPS525F.h
 *
 * Created: 2/1/2017 5:24:44 PM
 *  Author: elmar
 */


#ifndef SEPS525F_H_
#define SEPS525F_H_

#include "../../util/module.h"

#define SEPS525F_TO656(r,g,b)((r>>3)<<11)|((g>>2)<<5)|(b>>3)

uint8_t seps525f_start_draw(uint16_t x, uint16_t y, uint16_t w, uint16_t l);
uint8_t seps525f_draw(uint16_t colour);
uint8_t seps525f_stop_draw(void);

void seps525f_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
void seps525f_draw_pixels_monochrone(const uint16_t * image, uint16_t x, uint16_t y, uint16_t l, uint16_t w, uint16_t color, uint16_t backgroundColor);
void seps525f_draw_pixels_coloured(const uint16_t * image, uint16_t x, uint16_t y, uint16_t length, uint16_t width);
void seps525f_draw_pixels_coloured_flash(const uint16_t * image, uint16_t x, uint16_t y, uint16_t length, uint16_t width);
void seps525f_fill(uint16_t x, uint16_t y, uint16_t length, uint16_t width, uint16_t color);
void seps525f_scroll(uint8_t horizontal, uint8_t vertical);

MODULE_EXP(SEPS525F);

#endif /* SEPS525F_H_ */