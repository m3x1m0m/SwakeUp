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
    return 1;
}

static uint8_t deinit(void) {
    //event_removeListener(&EVENT_UART_JOB, callback);
    return 1;
}

MODULE_DEFINE(ESP8266, "ESP module", init, deinit, &UART);