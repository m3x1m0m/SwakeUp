/*
 * screenterminal.c
 *
 * Created: 2/25/2017 8:15:38 PM
 *  Author: elmar
 */
#include <avr/pgmspace.h>
#include "../util/font.h"
#include "../drivers/spi/SEPS525F.h"
#include "log.h"
#include "screenterminal.h"
#include "screen.h"

#define WIDTH 20
#define HEIGHT 16

LOG_INIT("GUI");

static uint16_t textColor = SEPS525F_TO656(8, 98, 19);
static uint16_t backgroundColor = 0x0000;

static uint8_t indexX = 0, indexY = 0;


static void write(void * p __attribute__ ((unused)), char c) {
    screenterminal_writes(c);
}

void (*screenterminal_sink(void))(void *, char ) {
    seps525f_fill(0, 0, 160, 128, backgroundColor);
    return &write;
}

uint8_t half = 0;
uint8_t hasCleared = 0;
void screenterminal_writes(char text) {
    if ((uint8_t)text >= (uint8_t)' ') {
//        uint8_t x = 0, y = 0;
        uint16_t drawX = indexX * 8, drawY = indexY * 8;
        screen_color(textColor);
        screen_text(&text, 1, drawX, drawY);
//         seps525f_start_draw(drawX, drawY, 8, 8);
//         for (; y < 8; y++) {
//             uint8_t row = pgm_read_byte(font_font8x8_basic[(uint8_t) text][y]);
//             for (x = 0; x < 8; x++) {
//                 if (row & (1 << x)) {
//                     seps525f_draw(textColor);
//                     //seps525f_draw_pixel(drawX + x, drawY + y, color);
//                 } else {
//                     seps525f_draw(backgroundColor);
//                 }
//             }
//         }
//         seps525f_stop_draw();
        indexX++;
    }
    if (text == '\r') indexX = 0;
    if (indexX == 20 || text == '\n') {
        indexY++;
        indexX = 0;
        if (hasCleared) {
            if (indexY != 16)
                seps525f_fill(0, indexY * 8, 160, 8, backgroundColor);
        }
        if (indexY == 16) {
            indexY = 0;
            seps525f_fill(0, indexY * 8, 160, 8, backgroundColor);
            hasCleared = 1;
        }
    }
}
void screenterminal_write(char * text, uint8_t len) {
    uint8_t i = 0;
    for (; i < len; i++)screenterminal_writes(text[i]);
}