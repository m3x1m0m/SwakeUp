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

#include <util/delay.h>

LOG_INIT("SEPS525F");

#define DATA_START 0x22

static void SEPS525F_reg(int idx, int value) {
    SEPS525F_PORT.OUTCLR = SEPS525F_CSB | SEPS525F_RS;
    _delay_ms(1);
    spiWriteByte(idx);
    SEPS525F_PORT.OUTSET = SEPS525F_RS;
    SEPS525F_PORT.OUTCLR = SEPS525F_CSB;
    spiWriteByte(value);
    _delay_ms(1);
    SEPS525F_PORT.OUTSET = SEPS525F_CSB;
}

static inline void seps525_datastart(void) {
    SEPS525F_PORT.OUTCLR = SEPS525F_CSB | SEPS525F_RS;
    spiWriteByte(DATA_START);
    SEPS525F_PORT.OUTSET = SEPS525F_RS;
}

static inline void seps525_data(int value) {
    spiWriteByte((value >> 8) & 0xFF);
    spiWriteByte(value & 0xFF);
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


static void onlineDriver(void) {
//digitalWrite(pinReset, LOW);
    _delay_ms(2);
//digitalWrite(pinReset, HIGH);
    _delay_ms(1);
// display off, analog reset
    SEPS525F_reg(0x04, 0x01);
    _delay_ms(1);
// normal mode
    SEPS525F_reg(0x04, 0x00);
    _delay_ms(1);
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
    SEPS525F_reg(0x12, 0x33);
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
    int n;
    for (n = 0; n < 160 * 128; n++) {
        seps525_data(0xffaf);
    }
    seps525_dataend();
//digitalWrite(pinVddEnable, LOW);
    _delay_ms(100);
    SEPS525F_reg(0x06, 0x01);
}

static void datasheetDriver(void) {
    SEPS525F_reg(0x02, 0x01); //internal clock
    SEPS525F_reg(0x04, 0x00); //power save normal
    SEPS525F_reg(0x03, 0x30); //OSC 90 Hz
    SEPS525F_reg(0x80, 0x00); //Reference volt
    SEPS525F_reg(0x08, 0x01); //Pre-charge R
    SEPS525F_reg(0x09, 0x01); //Pre-charge G
    SEPS525F_reg(0x0A, 0x01); //Pre-charge B
    SEPS525F_reg(0x0B, 0x0A); //Pre-charge current R
    SEPS525F_reg(0x0C, 0x0A); //Pre-charge current G
    SEPS525F_reg(0x0D, 0x0A); //Pre-charge current B
    SEPS525F_reg(0x10, 0x52); //current R
    SEPS525F_reg(0x11, 0x38); //current G
    SEPS525F_reg(0x12, 0x3A); //current B
    SEPS525F_reg(0x13, 0x00); //RGB Column 0->159
    SEPS525F_reg(0x14, 0x01); //Ext interface: MPU
    SEPS525F_reg(0x16, 0x76); //Write mode TODO
    SEPS525F_reg(0x17, 0x00); //Column start
    SEPS525F_reg(0x18, 0x9F); //Column end
    SEPS525F_reg(0x19, 0x00); //Row start
    SEPS525F_reg(0x1A, 0x7F); //Row end
    SEPS525F_reg(0x20, 0x00); //X
    SEPS525F_reg(0x21, 0x00); //Y
    SEPS525F_reg(0x28, 0x7F); //Duty - 128
    SEPS525F_reg(0x29, 0x00); //Start line
    SEPS525F_reg(0x2E, 0x00); // Read start point X
    SEPS525F_reg(0x2F, 0x00); // Read start point Y
    SEPS525F_reg(0x33, 0x00); // Screen saver start X
    SEPS525F_reg(0x34, 0x9F); // Screen saver end X
    SEPS525F_reg(0x35, 0x00); // Screen saver start Y
    SEPS525F_reg(0x36, 0x7F); // Screen saver end Y
    SEPS525F_reg(0x06, 0x01); // Screen on
}



void drawPixel(int16_t x, int16_t y, uint16_t color) {
    SEPS525F_set_region(x, y, 1, 1);
    seps525_datastart();
    seps525_data(color);
    seps525_dataend();
}

static uint8_t init(void) {
    SEPS525F_PORT.DIRSET = SEPS525F_SDI | SEPS525F_CSB | SEPS525F_RS | SEPS525F_SCL | SEPS525F_NOT;
    SEPS525F_PORT.OUTSET = SEPS525F_CSB | SEPS525F_NOT;
    SEPS525F_PORT.OUTCLR = SEPS525F_RS;
    LOG_SYSTEM("Launching driver");
    datasheetDriver();
    LOG_SYSTEM("SEPS525F initialized");
    return 1;
}

static uint8_t deinit(void) {
    return 1;
}

MODULE_DEFINE(SEPS525F, "SEPS525F", init, deinit, &SPI);