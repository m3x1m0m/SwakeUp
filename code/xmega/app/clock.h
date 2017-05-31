/*
 * clock.h
 *
 * Created: 3/1/2017 12:29:56 AM
 *  Author: elmar
 */


#ifndef CLOCK_H_
#define CLOCK_H_

#define CLOCK_DIGITAL_WIDTH         96
#define CLOCK_DIGITAL_HEIGHT        64
#define CLOCK_SMALL_WIDTH           96
#define CLOCK_SMALL_HEIGHT          32
#define CLOCK_SMALL_LINE_SPACING    3
#define CLOCK_SMALL_FONT_SIZE       8
#define CLOCK_APP_HEIGHT            CLOCK_SMALL_HEIGHT + CLOCK_DIGITAL_HEIGHT
#define CLOCK_APP_WIDTH             CLOCK_DIGITAL_WIDTH


#include <stdint.h>
#include "core.h"

void clock_draw(uint8_t update, uint8_t display);
void clock_init(uint16_t drawX, uint16_t drawY);
void clock_deinit(void);

#endif /* CLOCK_H_ */