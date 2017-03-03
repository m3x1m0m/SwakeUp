/*
 * core.c
 *
 * Created: 3/1/2017 2:59:44 PM
 *  Author: elmar
 */
#include <string.h>
#include "core.h"
#include "../modules/timekeeper.h"
#include "../modules/command.h"
#include "../modules/screen.h"
#include "../modules/log.h"
#include "../drivers/uart/esp8266.h"    //BREACH OF LAYERING

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
    LOG_DEBUG("Sending AT: %s\r\n", (char*)data);
    uart_write((char*)data, len, &ESP_UART_PORT);
    uart_write("\r\n", 2, &ESP_UART_PORT);
}

static void terminalCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    if (data[0] == 's' || data[0] == 'S') {
        if (SCREEN.cnt > 0)
            log_redirectOutput(screenterminal_sink());
        else
            LOG_WARNING("Screen is not initialized");
    } else {
        terminal_default_sink();
    }
}

static void setCommand(uint8_t len __attribute__ ((unused)), char * data __attribute__ ((unused))) {
    uint8_t index = 1;
    switch (data[index - 1]) {
    case 'W':
    case 'w':
        LOG_DEBUG("Setting weather: %d", (data[index] - '0'));
        weather_set((enum Weather)(data[index] - '0'));
        weather_draw();
        //weather
        break;
    case 'T':
    case 't':
        if (command_arguments(&data[index], len - 1) < 3) {
            LOG_WARNING("Not enough arguments for setting time");
        } else {
            uint8_t temp = 1;
            LOG_DEBUG("index: %d", temp);
            uint32_t hour = command_next_int(&temp, data, len);
            LOG_DEBUG("index: %d hour %d", temp, hour);
            uint32_t minute = command_next_int(&temp, data, len);
            LOG_DEBUG("index: %d minute %d", temp, minute);
            uint32_t second = command_next_int(&temp, data, len);
            LOG_DEBUG("index: %d second %d", temp, second);
        }
        //time
        break;
    case 'S':
    case 's':
        LOG_SYSTEM("Not implemented yet");
        //social
        break;
    default:
        LOG_WARNING("Unrecognized set command: %c", (char)data[index]);
        break;
    }
}

void core_time_set(uint8_t h, uint8_t m, uint8_t s) {
    timekeeper_time_set(h, m, s);
}


void core_time_get(struct Time * time) {
    timekeeper_time_get(time);
}

void core_screen(uint8_t on) {
    screenOn = on;
    if (on) {
        if (SCREEN.cnt == 0) {
            module_init(&SCREEN);
        }
    } else {
        if (SCREEN.cnt >= 1) {
            module_deinit(&SCREEN);
        }
    }
}

static uint8_t init(void) {
    command_hook_description('T', &terminalCommand, "Log sink    T<option> options: U(Uart) S(Screen)\0");
    command_hook_description('L', &ledCommand,      "Led control L<option> options: T(toggle) 1(on) 0(off)\0");
    command_hook_description('A', &atCommand,       "Sends AT    A		   no options\0");
    command_hook_description('S', &setCommand,      "Sets an app state S<app> <options>\r\n\t"
                             "W<options> options: 1-6 for different weather\r\n\t"
                             "S<options> options: f(facebook) e(mail)\r\n\t"
                             "T<options> options: hour minute second\0");
    return 1;
}
static uint8_t deinit(void) {
    return 1;
}

MODULE_DEFINE(CORE, "Central core", init, deinit, &TIME, &COMMAND);