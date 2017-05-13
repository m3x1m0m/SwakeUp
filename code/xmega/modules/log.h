/*
 * log.h
 *
 * Created: 11/14/2016 1:07:28 PM
 *  Author: elmar
 */


#ifndef LOG_H_
#define LOG_H_

#include <stdint.h>
#include <stdarg.h>
#include <avr/pgmspace.h>
#include "../util/module.h"
#include "../drivers/host/timer.h"
#include "../defines.h"

static const char _debug[] =    "Deb";
static const char _info[] =     "Inf";
static const char _system[] =   "Sys";
static const char _warning[] =  "War";
static const char _error[] =    "Err";

enum LOG_LEVEL {
    DEBUG_LEVEL, INFO_LEVEL, SYSTEM_LEVEL, WARNING_LEVEL, ERROR_LEVEL
};


#define LOG_DEBUG(MSG, ...)         LOG_INTERNAL(DEBUG_LEVEL, _debug, MSG, ##__VA_ARGS__)
#define LOG_INFO(MSG, ...)          LOG_INTERNAL(INFO_LEVEL, _info, MSG, ##__VA_ARGS__)
#define LOG_SYSTEM(MSG, ...)        LOG_INTERNAL(SYSTEM_LEVEL, _system, MSG, ##__VA_ARGS__)
#define LOG_WARNING(MSG, ...)       LOG_INTERNAL(WARNING_LEVEL, _warning, MSG, ##__VA_ARGS__)
#define LOG_ERROR(MSG, ...)         LOG_INTERNAL_ERR(_error, MSG, ##__VA_ARGS__)

extern enum LOG_DISPLAY log_display;


#define LOG_INTERNAL(LEVEL, LEVEL_STR, MSG, ...) \
        if(cur_level <= LEVEL){ \
            switch(log_display){ \
                case TIME_LEVEL_NAME_FILE_LINE: log_message("[%04d][%s][%s]%s:%d ",timer_runTime(),LEVEL_STR,log_name,__FILE__,__LINE__); break;   \
                case LEVEL_NAME_FILE_LINE: log_message("[%s][%s]%s:%d ",LEVEL_STR,log_name,__FILE__,__LINE__); break;   \
                case LEVEL_NAME_FILE: log_message("[%s][%s]%s ",LEVEL_STR,log_name,__FILE__); break;   \
                case LEVEL_NAME: log_message("[%s][%s] ",LEVEL_STR,log_name); break;                   \
                case NAME: log_message("[%s] ",log_name); break;                 \
            }\
            log_message_p(PSTR(MSG), ##__VA_ARGS__);                                                        \
            log_message("\r\n");    \
        }

#define LOG_INTERNAL_ERR(LEVEL, MSG, ...)\
      log_message("[%04d][%s][%s]%s:%d ",timer_runTime(),LEVEL,log_name,__FILE__,__LINE__); \
      log_message_p(PSTR(MSG), ##__VA_ARGS__);\
      log_message("\r\n");\
      log_error()


void log_message(const char * format, ...);   //TODO make this const
void log_message_p(const char * format, ...);
void log_error(void);
void log_set_display(enum LOG_DISPLAY disp);
void log_redirectOutput(void (*sink) (void*, char));
void log_defaultOutput(void);
void (*log_current_sink(void))(void *, char );

#define LOG_INIT(NAME) \
    static char log_name[] __attribute__((unused)) = NAME; \
    static enum LOG_LEVEL cur_level __attribute__((unused)) = DEBUG_LEVEL;

#define LOG_LEVEL_SET(level) cur_level = level;

MODULE_EXP(LOGGER);

#endif /* LOG_H_ */