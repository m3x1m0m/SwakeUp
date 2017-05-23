/*
 * defines.h
 *
 * Created: 3/3/2017 2:08:17 PM
 *  Author: elmar
 */


#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdint.h>

#define F_CPU               16000000UL

#define TAB "\t\t\t\t"
#define NL  "\r\n"

#define greeting                NL TAB"===================="NL\
                                TAB"Welcome to SwakeUpp!"NL\
                                TAB"Build date:"NL\
                                TAB __DATE__" "__TIME__ NL\
                                TAB"The time is:"NL\
                                TAB"18:08"NL\
                                TAB"===================="NL

// Writes protobuf messages when setting the time
#define PROTO_TEST
// Prints out outgoing protobyf messages in binary
// #define PROTO_PRINT

//Change this to a 1 if you want to use the screen
#define SCREEN_ON               0

//Enables sleeping and more power efficiency
#define EVENT_SUPPORTS_SLEEP

// Switch between hardware versions
#define REV_1
//#define REV_2

// Set print levels for PID
#define PID_PRINT_MODE_LVL4
#endif /* DEFINES_H_ */

// Background: A fast system tick (event with 1 kHz produced by overflow ISR TCC0) does not work yet  with 16 MHz, processing is too slow I guess
// TODO: Test it with 32 MHz
//#define TIMER_EXPERIMENTAL_1MS_TICK			

// ADC reference
#define VREF 2.3
#define VPERCOUNT_GAIN10E6 561.52