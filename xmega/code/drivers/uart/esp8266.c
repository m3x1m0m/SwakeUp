/*
 * esp8266.c
 *
 * Created: 2/22/2017 12:06:26 AM
 *  Author: elmar
 */

#include "esp8266.h"

#include <stdint.h>
#include "../../util/module.h"
#include "../../pin_definitions.h"
#include "../host/uart.h"
#include "../../modules/command.h"
#include "../../modules/log.h"
#include "../../modules/control.h"//move this out of here
#include "terminal.h"

static uint8_t write_callback(pb_ostream_t *stream, uint8_t *buf, size_t count) {
    return uart_write(buf, count, &ESP_UART_PORT);
}

Stream ESP8266_stream = STREAM_INIT(write_callback, stream_readCallback, NULL);

LOG_INIT("ESP8266");

#define WIFI_SSID   "elmar elmar"
#define WIFI_PASS   "elmarelmar"

//r = request, a = answer
const char _at_r[] = "AT";
const char _at_mode_r[] = "AT+CWMODE=1";
const char _at_connect_r[] = "AT+CWJAP=\""WIFI_SSID"\",\""WIFI_PASS"\"";
const char _at_list_r[] = "AT+CWLAP";

const char _disconnect_a[] = "WIFI DISCONNECT";
const char _connect_a[] = "WIFI CONNECT";
const char _ok_a[] = "OK";
const char _error_a[] = "ERROR";

enum State {
    UNKOWN, IDLE, MODE, SEARCHING, CONNECTING, CONNECTED, SENDING, RECEIVING
};

enum State state = UNKOWN;

static void atCommand(uint8_t len, const char * data) {
    uint8_t i = 0;
    for (; i < len; i++) uart_writes(data[i], &ESP_UART_PORT);
}

static uint8_t contains(const char * data, uint8_t len, const char * containing, uint8_t len2) {
    uint8_t i, b;
    for (i = 0, b = 0; i < len; i++) {
        if (data[i] == containing[b]) {
            b++;
            if (b == len2)
                return 1;
        } else {
            b = 0;
        }
    }
    return 0;
}

static void processState(char * data, uint8_t len) {
    switch (state) {
    case UNKOWN:
        if (contains(data, len, _ok_a, sizeof(_ok_a))) {
            state = MODE;
            atCommand(sizeof(_at_mode_r), _at_mode_r);
        }
        break;
    case MODE:
        if (contains(data, len, _ok_a, sizeof(_ok_a))) {
            state = CONNECTING;
            atCommand(sizeof(_at_connect_r), _at_connect_r);
        }
        break;
    case CONNECTING:
        if (contains(data, len, _ok_a, sizeof(_ok_a))) {
            state = CONNECTED;
        } else {
            LOG_WARNING("Unable to connect");
            state = IDLE;
        }
        break;
    }
}
static void callback(Event * event, uint8_t * data) {
    struct UartDelimiter * delimiter = (struct UartDelimiter*)data;
    if (delimiter->port == &ESP_UART_PORT) {
        if (uart_buffer_in_level(&ESP_UART_PORT) > 0) {
            char readData[delimiter->length + 1], read; // could we have more delimiter->length than inbuffer length?
            LOG_DEBUG("delimiter length: %d buffer level: %d", delimiter->length, uart_buffer_in_level(&ESP_UART_PORT));
            uint8_t len = 0;
            //LOG_DEBUG("Response:");
            while (uart_buffer_in_level(&ESP_UART_PORT) > 0) {
                if (!uart_reads_buffer(&read, &ESP_UART_PORT)) {
                    LOG_WARNING("No more data to read but we are trying");
                    break;
                }
                if ((uint8_t)read >= (uint8_t)' ' || read == '\n' || read == '\r') {
                    readData[len] = read;
                    len++;
                    LOG_DEBUG("Read: %d %c", (uint8_t)read, read);
                }
            }
            processState(readData, len);
        }
        uart_delimiter_handled(delimiter);
    }
}
void esp_reset(void) {
}
uint8_t esp_update_start(void) {
    return 0;
}
uint8_t esp_update_stop(void) {
    return 0;
}
uint16_t esp_update_write(uint8_t * datas, uint16_t len) {
    return 0;
}

static void streamCallback(char data) {
    if (stream_readByte(&ESP8266_stream, data)) {
        messageReceived(&ESP8266_stream);
    }
}
// #define ESP_RST_PORT        PORTA
// #define ESP_RST_PIN         (1<<3)
// #define ESP_PWR_SAVE_N_PORT PORTA
// #define ESP_PWR_SAVE_N_PIN  (1<<2)
// #define ESP_PWR_PORT        PORTA
// #define ESP_PWR_PIN         (1<<1)
// #define ESP_SLEEP_PORT      PORTA
// #define ESP_SLEEP_PIN       (1<<3)
// #define ESP_FP_PORT         PORTA
// #define ESP_FP_PIN          (1<<2)
// #define ESP_UART_PIN_PORT   PORTD
// #define ESP_UART_PORT       USARTD1
// #define ESP_UART_RX         (1<<6)
// #define ESP_UART_TX         (1<<7)
static uint8_t init(void) {
    //uart_add_delimiter('\n', &ESP_UART_PORT);
    //uart_add_delimiter('\r', &ESP_UART_PORT);
    //event_addListener(&EVENT_UART_DELIMITER, callback);
    ESP_ENABLE_PORT.DIRSET = ESP_ENABLE_PIN | ESP_PWR_SAVE_N_PIN | ESP_RST_PIN;
    ESP_ENABLE_PORT.OUTSET = ESP_ENABLE_PIN;
    ESP_SLEEP_PORT.DIRSET = ESP_SLEEP_PIN | ESP_FP_PIN;
    ESP_FP_PORT.OUTSET = ESP_FP_PIN;
    ESP_RST_PORT.OUTCLR = ESP_RST_PIN;
    LOG_SYSTEM("ESP8266 initialized");
    uart_set_callback(streamCallback, &ESP_UART_PORT);
    return 1;
}
static uint8_t deinit(void) {
    //event_removeListener(&EVENT_UART_JOB, callback);
    return 1;
}
MODULE_DEFINE(ESP8266, "ESP module", init, deinit, &UART, &COMMAND);