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
#include <util/delay.h>
#include "terminal.h"

LOG_INIT("ESP8266");

static uint8_t write_callback(pb_ostream_t * stream __attribute__ ((unused)), const pb_byte_t *buf, size_t count) { //TODO maybe we can use the stream properly for bytes_written
    return uart_write((char*) buf, (size_t) count, &ESP_UART_PORT);
}

Stream ESP8266_stream = STREAM_INIT(write_callback, stream_readCallback);

void esp_reset(void) {
}
uint8_t esp_update_start(void) {
    return 0;
}
uint8_t esp_update_stop(void) {
    return 0;
}
uint16_t esp_update_write(uint8_t * datas, uint16_t len) {
    (void)datas;
    (void)len;
    //TODO implement
    return 0;
}

static void streamCallback(char data) {
    //struct UartBuffer * inBuf = getInBuffer(&ESP_UART_PORT);
    uart_reads_buffer(&data, &ESP_UART_PORT);   //TODO this is strange, maybe create event and handle later?
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