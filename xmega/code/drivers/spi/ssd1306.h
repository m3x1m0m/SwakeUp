/*
 * SSD1306.h
 *
 * Created: 11/8/2016 1:54:59 AM
 *  Author: elmar
 */


#ifndef SSD1306_H_
#define SSD1306_H_

#include <stdint.h>
#include "../../util/module.h"

#define CS 1
#define DC 0

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_BUFFERSIZE (SSD1306_WIDTH*SSD1306_HEIGHT)/8




#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2


#define SSD1306_POWER_ON        0xAF
#define SSD1306_CONTRAST        0x81
#define SSD1306_CLOCK_DIVIDE    0xD5
#define SSD1306_MULTIPLEX       0xA8
#define SSD1306_POWER_OFF       0xAF
#define SSD1306_ENTIRE_ON       0xA4
#define SSD1306_NORMAL          0xA6
#define SSD1306_PRECHARGE       0xD9

#define SSD1306_PAGE_ADDR       0x22
#define SSD1306_COLUMN_ADDR     0x21

uint8_t ssd1306_init(void);
void ssd1306_setRegion(uint8_t x1, uint8_t y1, uint8_t * buf, uint16_t len);
void ssd1306_turnOn(void);
void ssd1306_turnOff(void);
void ssd1306_contrast(uint8_t contrast);
void ssd1306_pixel(int16_t x, int16_t y, uint16_t color);

MODULE_EXP(SSD1306);

#endif /* SSD1306_H_ */