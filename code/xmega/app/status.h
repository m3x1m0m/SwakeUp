/*
 * status.h
 *
 * Created: 5/13/2017 4:22:50 PM
 *  Author: elmar
 */


#ifndef STATUS_H_
#define STATUS_H_

#include <stdint.h>

#define STATUS_WIDTH    96
#define STATUS_HEIGHT   32

void status_init(uint16_t x, uint16_t y);
void status_deinit(void);
void status_wifi(uint8_t strength);
void status_alarm(uint8_t on);
void status_light(uint8_t on);



#endif /* STATUS_H_ */