/*
 * SEPS525F.c
 *
 * Created: 2/1/2017 5:24:56 PM
 *  Author: elmar
 */

#include "SEPS525F.h"
#include "../host/spi.h"
#include "../../pin_definitions.h"
#include "../../modules/log.h"

LOG_INIT("SEPS525F");

#include <util/delay.h>
#include <avr/pgmspace.h>

#define DATA_START 0x22

static void SEPS525F_reg(int idx, int value) {
    SEPS525F_PORT.OUTCLR = SEPS525F_CSB | SEPS525F_RS;
    spi_write_blocked(idx);
    SEPS525F_PORT.OUTSET = SEPS525F_RS;
    SEPS525F_PORT.OUTCLR = SEPS525F_CSB;
    spi_write_blocked(value);
    SEPS525F_PORT.OUTSET = SEPS525F_CSB;
}

static inline void seps525_datastart(void) {
    SEPS525F_PORT.OUTCLR = SEPS525F_CSB | SEPS525F_RS;
    spi_write_blocked(DATA_START);
    SEPS525F_PORT.OUTSET = SEPS525F_RS;
}

static inline void seps525_data(int value) {
    spi_write_blocked((value >> 8) & 0xFF);
    spi_write_blocked(value & 0xFF);
}

static inline void seps525_dataend(void) {
    SEPS525F_PORT.OUTSET = SEPS525F_CSB;
}

static void SEPS525F_set_region(int x, int y, int xs, int ys) {
    // draw region
    SEPS525F_reg(0x17, x);
    SEPS525F_reg(0x18, x + xs - 1);
    SEPS525F_reg(0x19, y);
    SEPS525F_reg(0x1a, y + ys - 1);
    // start position
    SEPS525F_reg(0x20, x);
    SEPS525F_reg(0x21, y);
}

#define SPIMO   7
#define SPIMI   6
#define SPISC   5
#define SPISS   4

//https://github.com/avian2/SEPS525-OLED-Library/blob/master/SEPS525_OLED.cpp
static void onlineDriver(void) {
//digitalWrite(pinReset, LOW);
    //_delay_ms(2);
//digitalWrite(pinReset, HIGH);
    _delay_ms(1);
// display off, analog reset
    SEPS525F_reg(0x04, 0x01);
    _delay_ms(1);
// normal mode
    SEPS525F_reg(0x04, 0x00);
    //_delay_ms(1);
// display off
    SEPS525F_reg(0x06, 0x00);
// turn on internal oscillator using external resistor
    SEPS525F_reg(0x02, 0x01);
// 90 hz frame rate, divider 0
    SEPS525F_reg(0x03, 0x30);
// duty cycle 127
    SEPS525F_reg(0x28, 0x7f);
// start on line 0
    SEPS525F_reg(0x29, 0x00);
// rgb_if
    SEPS525F_reg(0x14, 0x31);
// memory write mode
    SEPS525F_reg(0x16, 0x66);
// driving current r g b (uA)
    SEPS525F_reg(0x10, 0x45);
    SEPS525F_reg(0x11, 0x34);
    SEPS525F_reg(0x12, 0x40);
// precharge time r g b
    SEPS525F_reg(0x08, 0x04);
    SEPS525F_reg(0x09, 0x05);
    SEPS525F_reg(0x0a, 0x05);
// precharge current r g b (uA)
    SEPS525F_reg(0x0b, 0x9d);
    SEPS525F_reg(0x0c, 0x8c);
    SEPS525F_reg(0x0d, 0x57);
    SEPS525F_reg(0x80, 0x00);
// mode set
    SEPS525F_reg(0x13, 0x00);
    SEPS525F_set_region(0, 0, 160, 128);
    seps525_datastart();
    uint16_t n;
    for (n = 0; n < 160 * 128; n++) {
        seps525_data(0b1111111111111111);   // Initial colour
    }
    seps525_dataend();
//digitalWrite(pinVddEnable, LOW);
    // _delay_ms(100);
    SEPS525F_reg(0x06, 0x01);
}
void seps525f_fill(uint16_t x, uint16_t y, uint16_t length, uint16_t width, uint16_t color) {
    SEPS525F_set_region(x, y, length, width);
    seps525_datastart();
    uint16_t n;
    for (n = 0; n < length * width; n++) {
        seps525_data(color);
    }
    seps525_dataend();
}

void seps525f_scroll(uint8_t horizontal, uint8_t vertical) {
    //how to?
}

static uint8_t isDrawing = 0;

uint8_t seps525f_start_draw(uint16_t x, uint16_t y, uint16_t w, uint16_t l) {
    if (isDrawing) {
        LOG_WARNING("We are already drawing");
        return 0;
    }
    SEPS525F_set_region(x, y, w, l);
    seps525_datastart();
    isDrawing = 1;
    return 1;
}

uint8_t seps525f_draw(uint16_t colour) {
    if (!isDrawing) {
        LOG_WARNING("We aren't drawing");
        return 0;
    }
    seps525_data(colour);
    return 1;
}
uint8_t seps525f_stop_draw(void) {
    if (!isDrawing) {
        LOG_WARNING("We aren't drawing");
        return 0;
    }
    seps525_dataend();
    isDrawing = 0;
    return 1;
}

void seps525f_draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
    SEPS525F_set_region(x, y, 1, 1);
    seps525_datastart();
    seps525_data(color);
    seps525_dataend();
}

void seps525f_draw_pixels_monochrone(const uint16_t * image, uint16_t x, uint16_t y, uint16_t l, uint16_t w, uint16_t color, uint16_t backgroundColor) {
    SEPS525F_set_region(x, y, w, l);
    seps525_datastart();
    uint16_t x1 = 0, y1 = 0;
    for (y1 = 0; y1 < l; y1++) {
        uint16_t row = image[y1 * sizeof(uint16_t) + x1];
        for (x1 = 0; x1 < w; x1++) {
            if (row & (1 << x)) {
                seps525_data(color);
            } else {
                seps525_data(backgroundColor);
            }
        }
    }
    seps525_dataend();
}

void seps525f_draw_pixels_coloured(const uint16_t * image, uint16_t x, uint16_t y, uint16_t length, uint16_t width) {
    SEPS525F_set_region(x, y, length, width);
    seps525_datastart();
    uint16_t n;
    for (n = 0; n < length * width ; n++) {
        seps525_data(image[n]);   // Initial colour
    }
    seps525_dataend();
}

void seps525f_draw_pixels_coloured_flash(const uint16_t * image, uint16_t x, uint16_t y, uint16_t length, uint16_t width) {
    SEPS525F_set_region(x, y, length, width);
    seps525_datastart();
    uint16_t n;
    for (n = 0; n < length * width ; n++) {
        seps525_data(pgm_read_word(&image[n]));   // Initial colour
    }
    seps525_dataend();
}

#define BLUE_BM     0b0000000000011111
#define GREEN_BM    0b0000011111100000
#define RED_BM      0b1111100000000000

static uint8_t init(void) {
    SEPS525F_PORT.DIRSET = SEPS525F_CSB | SEPS525F_RS;
    SEPS525F_PORT.OUTSET = SEPS525F_CSB;
    SEPS525F_PORT.OUTCLR = SEPS525F_RS;
    LOG_SYSTEM("Setting up SEPS525F driver");
    onlineDriver();
    LOG_SYSTEM("SEPS525F initialized");
    return 1;
}
static uint8_t deinit(void) {
    return 1;
}
MODULE_DEFINE(SEPS525F, "SEPS525F", init, deinit, &SPI);