/*
 * console.c
 *
 * Created: 5/13/2017 1:02:02 PM
 *  Author: elmar
 */
#include "../modules/screenterminal.h"
#include "../modules/command.h"
#include "../modules/screen.h"
#include "../modules/log.h"
#include "clock.h"
#include "console.h"
#include "weather.h"



LOG_INIT("CONSOLE")

static void logSink(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    if (data[0] == 's' || data[0] == 'S') {
        if (SCREEN.cnt > 0) {
            log_redirectOutput(screenterminal_sink());
            clock_deinit();
            log_set_display(LEVEL_NAME);
        } else {
            LOG_WARNING("Screen is not initialized!");
        }
    } else {
        if (SCREEN.cnt > 0) {
            screen_color(COLOR_TO656(0, 0, 0));
            screen_draw_begin(FILLED);
            screen_rect(0, 0, 160, 128);
            screen_draw_end();
            clock_init(64, 0);
            weather_init(0, 96);
            weather_draw();
        }
        log_set_display(DEFAULT_LOG_FORMAT);
        log_defaultOutput();
    }
}

void console_init(void) {
    command_hook_description('T', &logSink, "Log sink    T<option> options: U(Uart) S(Screen)\0");
}

void console_deinit(void) {
    command_remove('T', &logSink);
}