/*
 * defines.h
 *
 * Created: 3/3/2017 2:08:17 PM
 *  Author: elmar
 */


#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdint.h>

#define TAB "\t\t\t\t"
#define NL  "\r\n"

#define greeting                NL TAB"===================="NL\
                                TAB"Welcome to SwakeUpp!"NL\
                                TAB"Build date:"NL\
                                TAB __DATE__" "__TIME__ NL\
                                TAB"The time is:"NL\
                                TAB"18:08"NL\
                                TAB"===================="NL

//Change this to a 1 if you want to use the screen
#define SCREEN_ON               0
//Enables sleeping and more power efficiency
#define EVENT_SUPPORTS_SLEEP

#endif /* DEFINES_H_ */