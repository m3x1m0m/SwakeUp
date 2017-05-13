/*
 * clock.h
 *
 * Created: 3/1/2017 12:29:56 AM
 *  Author: elmar
 */


#ifndef CLOCK_H_
#define CLOCK_H_

#define CLOCK_WIDTH         96
#define CLOCK_HEIGHT        96
#define CLOCK_CENTER        48

#define CLOCK_SECOND_LEN    48
#define CLOCK_MINUTE_LEN    40
#define CLOCK_HOUR_LEN      32

#define CLOCK_ANALOGUE      0

#include <stdint.h>
#include "core.h"

void clock_draw(uint8_t update, uint8_t display);
void clock_init(void);
void clock_init_screen(uint16_t drawX, uint16_t drawY, uint8_t on);
void clock_deinit(void);

#endif /* CLOCK_H_ */