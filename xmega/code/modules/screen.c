/*
 * screen.c
 *
 * Created: 11/12/2016 6:02:02 PM
 *  Author: elmar
 */
#include <avr/pgmspace.h>
#include "../drivers/uart/terminal.h"
#include "../drivers/spi/SEPS525F.h"
#include "../drivers/host/timer.h"
#include "../util/font.h"
#include "screen.h"
#include "image.h"
#include "log.h"

LOG_INIT("Screen");

static uint16_t curColor = 0xAAAA;
static enum SCREEN_SHAPE_TYPE curType = FILLED;

void screen_draw_begin(enum SCREEN_SHAPE_TYPE type) {
    curType = type;
}

void screen_draw_end(void) {}

void screen_color(uint16_t color) {
    curColor = color;
}

void screen_text(char * text, uint8_t len, uint16_t x, uint16_t y) {
    uint8_t y0, x0, i;
    for (i = 0; i < len; i++) {
        seps525f_start_draw(x + i * 8, y, 8, 8);
        char letter = text[i];
        for (y0 = 0; y0 < 8; y0++) {
            uint8_t row = pgm_read_byte(&font_font8x8_basic[(uint8_t) letter][y0]);
            for (x0 = 0; x0 < 8; x0++) {
                if (row & (1 << x0)) {
                    seps525f_draw(curColor);
                    //seps525f_draw_pixel(drawX + x, drawY + y, color);
                } else {
                    seps525f_draw(0x0000);
                }
            }
        }
        seps525f_stop_draw();
    }
}
void screen_rect_to(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    if (curType == LINE) {
        seps525f_fill(x1, y1, x2 - x1, 1, curColor);
        seps525f_fill(x1, y2, x2 - x1, 1, curColor);
        seps525f_fill(x1, y2, 1, y2 - y1, curColor);
        seps525f_fill(x2, y2, 1, y2 - y1, curColor);
    } else {
        seps525f_fill(x1, y1, x2 - x1, y2 - y1, curColor);
    }
}

void screen_rect(uint16_t x1, uint16_t y1, uint16_t width, uint16_t height) {
    if (curType == FILLED) {
        seps525f_fill(x1, y1, width, height, curColor);
    } else {
        seps525f_fill(x1, y1, width, 1, curColor);
        seps525f_fill(x1, y1 + height, width, 1, curColor);
        seps525f_fill(x1, y1, 1, height, curColor);
        seps525f_fill(x1 + width, y1, 1, height, curColor);
    }
}


void screen_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    int dx =  abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2; /* error value e_xy */
    for (;;) { /* loop */
        screen_pixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;    /* e_xy+e_x > 0 */
            x1 += sx;
        }
        if (e2 <= dx) {
            err += dx;    /* e_xy+e_y < 0 */
            y1 += sy;
        }
    }
}
void screen_pixel(uint16_t x, uint16_t y) {
    seps525f_draw_pixel(x, y, curColor);
}

static void screen_circle_empty(uint16_t x, uint16_t y, int radius) {
    int x1, y1;
    int l;
    int r2, y2;
    int y2_new;
    int ty;
    /* cos pi/4 = 185363 / 2^18 (approx) */
    l = (radius * 185363) >> 18;
    /* At x=0, y=radius */
    y1 = radius;
    r2 = y2 = y1 * y1;
    ty = (2 * y1) - 1;
    uint16_t value = curColor;
    y2_new = r2 + 3;
    for (x1 = 0; x1 <= l; x1++) {
        y2_new -= (2 * x1) - 3;
        if ((y2 - y2_new) >= ty) {
            y2 -= ty;
            y1 -= 1;
            ty -= 2;
        }
        seps525f_draw_pixel (x + x1, y + y1, value);
        seps525f_draw_pixel (x + x1, y + -y1, value);
        seps525f_draw_pixel (x + -x1, y +  y1, value);
        seps525f_draw_pixel (x + -x1, y +  -y1, value);
        seps525f_draw_pixel (x + y1, y + x1, value);
        seps525f_draw_pixel (x + y1, y + -x1, value);
        seps525f_draw_pixel (x + -y1, y +  x1, value);
        seps525f_draw_pixel (x + -y1, y +  -x1, value);
    }
}

static void screen_circle_filled(int x1, int y1, int radius) {
    int x, y;
    for (y = -radius; y <= radius; y++)
        for (x = -radius; x <= radius; x++)
            if (x * x + y * y <= radius * radius)
                seps525f_draw_pixel (x + x1, y + y1, curColor);
}

void screen_circle(uint16_t x, uint16_t y, int radius) {
    if (curType == FILLED) screen_circle_filled(x, y, radius);
    else screen_circle_empty(x, y, radius);
}

void screen_image(Image * image, uint16_t x, uint16_t y) {
    if (image->isFlash) {
        seps525f_draw_pixels_coloured_flash(image->image, x, y, IMAGE_WIDTH(image), IMAGE_HEIGHT(image));
    } else {
        seps525f_draw_pixels_coloured(image->image, x, y, IMAGE_WIDTH(image), IMAGE_HEIGHT(image));
    }
}

void screen_sub_image(Image * image, uint16_t x, uint16_t y, uint16_t imgX, uint16_t imgY, uint16_t imgWidth, uint16_t imgHeight) {
    seps525f_start_draw(x, y, imgWidth, imgHeight);
    uint16_t cX, cY;
    if (image->isFlash) {
        for (cY = imgY; cY < (imgY + imgHeight); cY++) {
            for (cX = imgX; cX < (imgX + imgWidth); cX++) {
                seps525f_draw(pgm_read_word(&image->image[cY * IMAGE_WIDTH(image) + cX]));
            }
        }
    } else {
        for (cY = imgY; cY < (imgY + imgHeight); cY++) {
            for (cX = imgX; cX < (imgX + imgWidth); cX++) {
                seps525f_draw(image->image[cY * IMAGE_WIDTH(image) + cX]);
            }
        }
    }
    seps525f_stop_draw();
}

void screen_sub_image_col(Image * image, uint16_t x, uint16_t y, uint16_t imgX, uint16_t imgY, uint16_t imgWidth, uint16_t imgHeight, uint16_t color) {
    seps525f_start_draw(x, y, imgWidth, imgHeight);
    uint16_t cX, cY;
    if (image->isFlash) {
        for (cY = imgY; cY < (imgY + imgHeight); cY++) {
            for (cX = imgX; cX < (imgX + imgWidth); cX++) {
                uint16_t saturatedColor = pgm_read_word(&image->image[cY * IMAGE_WIDTH(image) + cX]);
                if (saturatedColor != COLOR_TO656(0, 0, 0)) {
                    saturatedColor -= color;
                }
                seps525f_draw(saturatedColor);
            }
        }
    } else {
        for (cY = imgY; cY < (imgY + imgHeight); cY++) {
            for (cX = imgX; cX < (imgX + imgWidth); cX++) {
                uint16_t saturatedColor = &image->image[cY * IMAGE_WIDTH(image) + cX];
                if (saturatedColor != COLOR_TO656(0, 0, 0)) {
                    saturatedColor -= color;
                }
                seps525f_draw(saturatedColor);
            }
        }
    }
    seps525f_stop_draw();
}

static uint8_t init(void) {
    if (log_current_sink() == screenterminal_sink()) {
        terminal_default_sink();
    }
    //seps525f_fill(0, 0, 160, 128, 0x000);
    LOG_SYSTEM("Screen initialized");
    return 1;
}
static uint8_t deinit(void) {
    return 1;
}
MODULE_DEFINE(SCREEN, "Screen", init, deinit, &SEPS525F);