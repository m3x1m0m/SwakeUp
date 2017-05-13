/*
 * mail.h
 *
 * Created: 5/13/2017 4:22:30 PM
 *  Author: elmar
 */


#ifndef MAIL_H_
#define MAIL_H_

#include <stdint.h>

#define MAIL_WIDTH    64
#define MAIL_HEIGHT   96

void mail_add(const char * sender, const char * subject);
void mail_init(uint16_t x, uint16_t y);
void mail_deinit(void);



#endif /* MAIL_H_ */