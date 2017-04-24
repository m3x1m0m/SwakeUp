/*
 * esp8266.h
 *
 * Created: 2/21/2017 11:44:53 PM
 *  Author: elmar
 */


#ifndef ESP8266_H_
#define ESP8266_H_

#include <stdint.h>
#include "../../util/module.h"
#include "../../util/stream.h"

extern Stream ESP8266_stream;

void esp_reset(void);

uint8_t esp_update_start(void);
uint8_t esp_update_stop(void);
uint16_t esp_update_write(uint8_t * datas, uint16_t len);

MODULE_EXP(ESP8266);


#endif /* ESP8266_H_ */