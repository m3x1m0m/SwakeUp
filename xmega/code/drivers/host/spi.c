/*
 * spi.c
 *
 * Created: 2/1/2017 5:25:38 PM
 *  Author: elmar
 */
#include "spi.h"
#include <avr/io.h>
#include "../../pin_definitions.h"
#include "../../modules/log.h"

LOG_INIT("SPI");

static inline void SPI_SET_SS() {
    SPIC_PORT.OUTSET = SPI_SS;
}

static inline void SPI_RESET_SS() {
    SPIC_PORT.OUTCLR = SPI_SS;
}

uint8_t spiWriteByte(uint8_t byte) {
    SPI_RESET_SS();
    SPIC.DATA = byte;  //send it
    while (!(SPIC.STATUS & SPI_IF_bm)); //wait for the transfer to end
    SPI_SET_SS();
    return SPIC.DATA;
}

static uint8_t init(void) {
    //1101 0000
    SPIC_PORT.DIRSET = SPIC_SCK | SPIC_MOSI | SPI_SS;
    SPIC_PORT.PIN4CTRL = PORT_OPC_WIREDANDPULL_gc; // wired AND & pull-up
    SPIC_PORT.DIRCLR = SPIC_MISO;
    SPIC_PORT.PIN6CTRL = PORT_OPC_PULLDOWN_gc;
    SPI_SET_SS();
    //out C5: DATA ABC (MOSI) d10
    //in C6: not active input (MISO)
    //out C7: DATA zegar (SCK) d21
    SPIC.CTRL |= (SPI_ENABLE_bm | ~SPI_DORD_bm | SPI_MASTER_bm | SPI_MODE_0_gc | SPI_PRESCALER_DIV4_gc);
    //SPIC.INTCTRL |= SPI_INTLVL_LO_gc;  //set interrupts
    SPIC.STATUS;    //both these are to take IF down
    SPIC.DATA;  //when I don't use interrupts
    LOG_SYSTEM("SPI initialized");
    return 1;
}

static uint8_t deinit(void) {
    return 1;
}

MODULE_DEFINE(SPI, "SPI", init, deinit);