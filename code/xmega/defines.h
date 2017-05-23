/*
 * defines.h
 *
 * Created: 3/3/2017 2:08:17 PM
 *  Author: elmar
 */


#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdint.h>


// #define EXTERNAL_CLK

#ifdef EXTERNAL_CLK
#define F_CPU               16000000UL
else
#define F_CPU               32000000UL
#endif


#define TAB "\t\t\t\t"
#define NL  "\r\n"

#define greeting                NL TAB"===================="NL\
                                TAB"Welcome to SwakeUpp!"NL\
                                TAB"Build date:"NL\
                                TAB __DATE__" "__TIME__ NL\
                                TAB"The time is:"NL\
                                TAB"18:08"NL\
                                TAB"===================="NL

// Different levels of formatting, its formatted in order
    enum LOG_DISPLAY {
    TIME_LEVEL_NAME_FILE_LINE, LEVEL_NAME_FILE_LINE, LEVEL_NAME_FILE, LEVEL_NAME, NAME
};

// Prints out all the event that are being fired
// #define EVENT_PRINT

// This is the default log formatting
#define DEFAULT_LOG_FORMAT TIME_LEVEL_NAME_FILE_LINE

// Writes protobuf messages when setting the time
#define PROTO_TEST

// Prints out outgoing protobyf messages in binary
// #define PROTO_PRINT

//Change this to a 1 if you want to use the screen
#define SCREEN_ON               1

// Draws boundary boxes around the apps
#define BOUNDARY_BOX

//Enables sleeping and more power efficiency
#define EVENT_SUPPORTS_SLEEP

// Switch between hardware versions
//#define REV_1
#define REV_2

// Enable watchig timeout
// #define WATCHDOG_ENABLE
#endif /* DEFINES_H_ */