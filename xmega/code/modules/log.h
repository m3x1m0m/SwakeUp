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

#include "../util/module.h"

const static char _info[] =     "Inf";
const static char _debug[] =    "Deb";
const static char _system[] =   "Sys";
const static char _warning[] =  "War";
const static char _error[] =    "Err";

#define LOG_INFO(MSG, ...)          LOG_INTERNAL(_info, MSG, ##__VA_ARGS__)
#define LOG_DEBUG(MSG, ...)         LOG_INTERNAL(_debug, MSG, ##__VA_ARGS__)
#define LOG_SYSTEM(MSG, ...)        LOG_INTERNAL(_system, MSG, ##__VA_ARGS__)
#define LOG_WARNING(MSG, ...)       LOG_INTERNAL(_warning, MSG, ##__VA_ARGS__)
#define LOG_ERROR(MSG, ...)         LOG_INTERNAL_ERR(_error, MSG, ##__VA_ARGS__)

#define LOG_INTERNAL(LEVEL, MSG, ...)\
        log_message("[%s][%s]%s:%d ",LEVEL,log_name,__FILE__,__LINE__); \
        log_message(MSG, ##__VA_ARGS__);\
        log_message("\r\n")

#define LOG_INTERNAL_ERR(LEVEL, MSG, ...)\
        log_message("[%s][%s]%s:%d ",LEVEL,log_name,__FILE__,__LINE__); \
        log_message(MSG, ##__VA_ARGS__);\
        log_message("\r\n");\
        log_error()

void log_message(const char * format, ...);
void log_error(void);

#define LOG_INIT(NAME) \
    static char log_name[] __attribute__((unused)) = NAME;

MODULE_EXP(LOGGER);

#endif /* LOG_H_ */