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
#include "../drivers/uart/esp8266.h"    //BREACH OF LAYERING
#include "../drivers/uart/terminal.h"   //BREACH OF LAYERING
#include "../modules/control.h"

#include "../pin_definitions.h"

#include "weather.h"
#include "clock.h"

LOG_INIT("Core");

EVENT_REGISTER(TIME_CHANGE, "Change of net time");
EVENT_REGISTER(WEATHER_CHANGE, "Change of weather");
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

static void atCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    LOG_DEBUG("Sending AT(%d):", len, data);
    uint8_t i;
    terminal_putc('\t');
    for (i = 0; i < len; i++) {
        terminal_putc(data[i]);
    }
    terminal_putc('\r');
    terminal_putc('\n');
    uart_write((char*)data, len, &ESP_UART_PORT);
    uart_write("\r\n", 2, &ESP_UART_PORT);
}

static void terminalCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    if (data[0] == 's' || data[0] == 'S') {
        if (SCREEN.cnt > 0) {
            log_redirectOutput(screenterminal_sink());
            clock_deinit();
        } else
            LOG_WARNING("Screen is not initialized");
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
        terminal_default_sink();
    }
}

static void getCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    if (data[0] == 'W' || data[0] == 'w') {
        LOG_SYSTEM("Weather: %d", weather_get());
    } else if (data[0] == 'T' || data[0] == 't') {
        struct TimeKeeper time;
        core_time_get(&time);
        LOG_SYSTEM("Time: %d:%d:%d", time.hour, time.minute, time.second);
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
            LOG_WARNING("Not enough arguments for setting time");
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
            core_time_set(hour & 0xFF, minute & 0xFF, second & 0xFF);
#endif
        }
        //time
        break;
    case 'S':
    case 's':
        //social
        break;
    default:
        LOG_WARNING("Unrecognized set command: % c", (char)data[index]);
        break;
    }
}
void core_time_set(uint8_t h, uint8_t m, uint8_t s) {
    timekeeper_time_set(h, m, s);
    struct TimeKeeper tim;
    timekeeper_time_get(&tim);
    clock_time_set(&tim);
}
void core_time_get(struct TimeKeeper * time) {
    timekeeper_time_get(time);
    clock_time_set(time);
}
void core_screen(uint8_t on) {
    screenOn = on;
    if (on) {
        if (SCREEN.cnt == 0) {
            module_init(&SCREEN);
            clock_init(64, 0);
            weather_init(0, 96);
            weather_draw();
        }
    } else {
        if (SCREEN.cnt >= 1) {
            module_deinit(&SCREEN);
        }
    }
}
static uint8_t init(void) {
    command_hook_description('T', &terminalCommand, "Log sink    T<option> options: U(Uart) S(Screen)\0");
    command_hook_description('L', &ledCommand,      "Led control L<option> options: T(Toggle) 1(on) 0(off)\0");
    command_hook_description('A', &atCommand,       "Sends AT    A         no options\0");
    command_hook_description('S', &setCommand,      "Sets an app state S<app> <options>\r\n\t"
                             "W<options> options: 1 - 6 for different weather\r\n\t"
                             "S<options> options : f(Facebook) e(Mail)\r\n\t"
                             "T<options> options : hour minute second\0");
    command_hook_description('G', &getCommand,      "Gets state of an app A<App>\r\n\t"
                             "W Get weather            no options \r\n\t"
                             "T Get time               no options \0");
    return 1;
}
static uint8_t deinit(void) {
    if (screenOn) module_deinit(&SCREEN);
    return 1;
}
MODULE_DEFINE(CORE, "Central core", init, deinit, &TIME, &COMMAND, &CONTROL, &ESP8266);
