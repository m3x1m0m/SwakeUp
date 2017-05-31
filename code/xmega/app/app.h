/*
 * app.h
 *
 * Created: 5/13/2017 5:14:56 PM
 *  Author: elmar
 */


#ifndef APP_H_
#define APP_H_

#include <stdint.h>
#include "../modules/log.h"

#define true 1
#define false 0

typedef struct {
    const char * name;
    uint16_t x, y;
    uint8_t width, height;
    uint8_t enabled;
    void (*move)(uint16_t, uint16_t);
} APP;

#define APP_SET_POS(drawX, drawY)       _app.x = drawX; _app.y = drawY
#define APP_POS                         _app.x, _app.y

#define APP_ISENABLED                   _app.enabled
#define APP_ENABLE(enable)              if(_app.enabled == enable) return; _app.enabled = enable; if(APP_ISENABLED){ LOG_SYSTEM("Initialized"); }else{  LOG_SYSTEM("Deinitialized");}

#define APP_SET_BOUNDS(_width, _height)   _app.width = _width; _app.height = _height
#define APP_SIZE                        _app.width, _app.height
#define APP_BOUNDS                      APP_POS, _app.width, _app.height

#define APP_CREATE(_name, _move) \
    static APP _app = { \
        .name = _name, \
        .move = _move\
    }; LOG_INIT("App|"_name)

#define xx _app.x
#define yy _app.y
#define ww _app.width
#define hh _app.height

#endif /* APP_H_ */