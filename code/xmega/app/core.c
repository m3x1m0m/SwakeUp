/*
 * core.c
 *
 * Created: 3/1/2017 2:59:44 PM
 *  Author: elmar
 */
#include <string.h>
#include "core.h"
#include "../modules/screenterminal.h"
#include "../modules/timekeeper.h"
#include "../modules/command.h"
#include "../modules/screen.h"
#include "../modules/log.h"
#include "../modules/control.h"
#include "../drivers/host/uart.h"    //BREACH OF LAYERING
#include "../modules/control.h"
#include "../drivers/host/pwm.h"
#include "../drivers/host/adc.h"
#include "../pin_definitions.h"
#include "mail.h"
#include "console.h"
#include "weather.h"
#include "clock.h"

LOG_INIT("Core");

EVENT_REGISTER(TIME_SOCIAL_MEDIACHANGE, "Social Media");

static uint8_t screenOn;

static void ledCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    switch (data[0]) {
    case '1':
        LOG_DEBUG("Turning led on");
        DEBUG_LED_ON();
        break;
    case '0':
        LOG_DEBUG("Turning led off");
        DEBUG_LED_OFF();
        break;
    case 't':
    case 'T':
        LOG_DEBUG("Toggling led");
        DEBUG_LED_TOG();
        break;
    }
}

static void getCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    if (data[0] == 'W' || data[0] == 'w') {
        LOG_SYSTEM("Weather: %d", weather_get());
    } else if (data[0] == 'T' || data[0] == 't') {
        TimeKeeper timeKeeper = timekeeper_get();
        LOG_SYSTEM("Time: %d:%d:%d", timeKeeper.time.hour, timeKeeper.time.minute, timeKeeper.time.second);
    } else if (data[0] == 'A' || data[0] == 'a') {
        if (len < 2) {
            LOG_SYSTEM("Please define an application. Implemented:\r\n \t GA[S] get stream information");
        } else {
            switch (data[1]) {
            case 'S':
            case 's': {
                Stream * stream = ctrlGetStream(CTRL_STREAM_ESP);
                struct UartBuffer * inputBuf = getInBuffer(&ESP_UART_PORT);
                struct UartBuffer * outputBuf = getOutBuffer(&ESP_UART_PORT);
                LOG_SYSTEM("ESP Input UART information\r\n\tHead %d \r\n\tTail %d \r\n\tSize %d", inputBuf->head, inputBuf->tail , inputBuf->size);
                LOG_SYSTEM("ESP Output UART information\r\n\tHead %d \r\n\tTail %d \r\n\tSize %d", outputBuf->head, outputBuf->tail , outputBuf->size);
                LOG_SYSTEM("ESP STREAM information\r\n\tStatus %d", stream->state);
                LOG_SYSTEM("ESP Input Stream information\r\n\tToRead %d \r\n\tReadPos %d \r\n\tWritePos %d \r\n\tErrmsg: %s \r\n\tBytes left: %d \r\n\tState: %d",
                           stream->inputStream.toRead, stream->inputStream.readBufferPos, stream->inputStream.writeBufferPos,
                           stream->inputStream.stream.errmsg, stream->inputStream.stream.bytes_left, stream->inputStream.stream.state);
                LOG_SYSTEM("ESP Output Stream information \r\n\tErrmsg: %s \r\n\tBytes written: %d \r\n\tMax size: %d \r\n\tState: %d",
                           stream->outputStream.stream.errmsg, stream->outputStream.stream.bytes_written, stream->outputStream.stream.max_size, stream->outputStream.stream.state);
            }
            break;
            }
        }
    } else if (data[0] == 'L' || data[0] == 'l') {
        LOG_SYSTEM("Current log display %d", log_display);
        LOG_SYSTEM("Global log level %d", 0);
    }
}

static void setCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    uint8_t index = 1;
    switch (data[index - 1]) {
    case 'W':
    case 'w':
        LOG_DEBUG("Setting weather: %d", (data[index] - '0'));
        Weather weather = weather_get();
        weather.weatherType = (WeatherType)(data[index] - '0');
        weather_set(weather);
        weather_draw();
        //weather
        break;
    case 'T':
    case 't':
        if (command_arguments(&data[index], len - 1) < 3) {
            LOG_WARNING("Not enough arguments for setting time, ['S']['T'][h][m][s]");
        } else {
            uint32_t hour = command_next_int(&index, data, len);
            uint32_t minute = command_next_int(&index, data, len);
            uint32_t second = command_next_int(&index, data, len);
#ifdef PROTO_TEST
            Stream * stream = ctrlGetStream(CTRL_STREAM_ESP);
            MsgFrame * frame = stream->msgPointer;
            frame->typ = MsgType_MSG_TYPE_DATE_TIME;
            frame->which_pl = MsgFrame_dateAndTime_tag;
            frame->pl.dateAndTime.hour = (hour & 0xFF);
            frame->pl.dateAndTime.minute = (minute & 0xFF);
            frame->pl.dateAndTime.second = (second & 0xFF);
            writeMessage(stream, frame);
#else
            timekeeper_time_set(hour & 0xFF, minute & 0xFF, second & 0xFF);
#endif
        }
        //time
        break;
    case 'S':
    case 's':
        //social
        break;
    case 'L':
    case 'l':
        if (command_arguments(&data[index], len - 1) < 2) {
            LOG_WARNING("Not enough arguments for setting logger, ['S']['L'][Display][Level]");
        } else {
            uint32_t display = command_next_int(&index, data, len);
            uint32_t level = command_next_int(&index, data, len);
            log_display = (enum LOG_DISPLAY) display;
            LOG_SYSTEM("Current log display %d", log_display);
            LOG_SYSTEM("Global log level %d", level);
        }
        break;
    default:
        LOG_WARNING("Unrecognized set command: % c", (char)data[index]);
        break;
    }
}

void core_screen(uint8_t on) {
    screenOn = on;
    if (on) {
        if (SCREEN.cnt == 0) {
            module_init(&SCREEN);
#if DRAW_CLOCK == 1
            clock_init_screen(APP_CLOCK_X, APP_CLOCK_Y, 1);
#endif
#if DRAW_WEATHER == 1
            weather_init(APP_WEATHER_X, APP_WEATHER_Y);
            weather_draw();
#endif
#if DRAW_STATUS == 1
            status_init(APP_STATUS_X, APP_STATUS_Y);
#endif
#if DRAW_MAIL == 1
            mail_init(APP_MAIL_X, APP_MAIL_Y);
#endif
            console_init();
        }
    } else {
        if (SCREEN.cnt >= 1) {
            module_deinit(&SCREEN);
        }
#if DRAW_CLOCK == 1
        clock_init_screen(APP_CLOCK_X, APP_CLOCK_X, 0);
#endif
    }
}
static uint8_t init(void) {
    clock_init();
    command_hook_description('L', &ledCommand,      "Led control L<option> options: T(Toggle) 1(on) 0(off)\0");
    command_hook_description('S', &setCommand,      "Sets an app state S<app> <options>\r\n\t"
                             "W<options> options: 1 - 6 for different weather\r\n\t"
                             "S<options> options : f(Facebook) e(Mail)\r\n\t"
                             "L<options> options : display(1-5) level(1-5)\r\n\t"
                             "T<options> options : hour minute second\0");
    command_hook_description('G', &getCommand,      "Gets state of an app A<App>\r\n\t"
                             "W Get weather            no options \r\n\t"
                             "T Get time               no options \0");
    return 1;
}
static uint8_t deinit(void) {
    clock_deinit();
    if (screenOn) module_deinit(&SCREEN);
    return 1;
}
MODULE_DEFINE(CORE, "Central core", init, deinit, &TIME, &COMMAND, &CONTROL);
