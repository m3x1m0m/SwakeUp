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
LOG_INIT("ESP8266");

static void atCommand(uint8_t len, uint8_t * data) {
    uint8_t i = 0;
    for (; i < len; i++) uart_writes(data[i], &ESP_UART_PORT);
}

static void callback(Event * event, uint8_t * data) {
    struct UartDelimiter * delimiter = (struct UartDelimiter*)data;
    //LOG_DEBUG("Received callback: %s", event->description);
    //if (delimiter->port == &ESP_UART_PORT) {
    char readData[delimiter->length + 1], read;
    uint8_t len = 0;
    while (uart_reads_buffer(&read, &ESP_UART_PORT)) {
        readData[len] = read;
        len++;
    }
    readData[delimiter->length + 1] = '\0';
    //LOG_DEBUG("AT rcd: %s", readData);
    // }
}

void esp_reset(void) {
}
uint8_t esp_update_start(void) {
}
uint8_t esp_update_stop(void) {
}
uint16_t esp_update_write(uint8_t * datas, uint16_t len) {
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
    uart_add_delimiter('\n', &ESP_UART_PORT);
    uart_add_delimiter('\r', &ESP_UART_PORT);
    event_addListener(&EVENT_UART_DELIMITER, callback);
    ESP_ENABLE_PORT.DIRSET = ESP_ENABLE_PIN | ESP_PWR_SAVE_N_PIN | ESP_RST_PIN;
    ESP_ENABLE_PORT.OUTSET = ESP_ENABLE_PIN;
    ESP_SLEEP_PORT.DIRSET = ESP_SLEEP_PIN | ESP_FP_PIN;
    ESP_FP_PORT.OUTSET = ESP_FP_PIN;
    LOG_SYSTEM("ESP8266 initialized");
    return 1;
}
static uint8_t deinit(void) {
    //event_removeListener(&EVENT_UART_JOB, callback);
    return 1;
}
MODULE_DEFINE(ESP8266, "ESP module", init, deinit, &UART, &COMMAND);