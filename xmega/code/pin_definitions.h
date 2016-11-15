/*
 * pin_definitions.h
 *
 * Created: 11/12/2016 6:10:09 PM
 *  Author: elmar
 */


#ifndef PIN_DEFINITIONS_H_
#define PIN_DEFINITIONS_H_

#define F_CPU           8000000UL
#include <avr/io.h>

#define LED_DDRD        DDRD
#define LED_PORT        PORTD
#define LED_SOL         (1<<6)
#define LED_ERROR       (1<<7)

#define SSD1306_PORT    DDRD
#define SSD1306_CS     (1<<1)
#define SSD1306_DC     (1<<0)

#define SPI_PORT        DDRB
#define SPI_DDRB_MOSI  (1<<5)
#define SPI_DDRB_SCK   (1<<3)
#define SPI_DDRB_SS    (1<<2)

#endif /* PIN_DEFINITIONS_H_ */