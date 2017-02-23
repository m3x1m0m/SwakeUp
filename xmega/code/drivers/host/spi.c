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

void spiWriteByte(uint8_t byte) {
    SPIC.DATA = byte;
    //while ((SPIC.STATUS & SPI_IF_bm) == 0x00);
}

static uint8_t init(void) {
    //1101 0000
    SPIC.CTRL = SPI_MODE_0_gc | SPI_PRESCALER_DIV16_gc | SPI_ENABLE_bm | SPI_MASTER_bm;    // SPI master, clock idle low, data setup on trailing edge, data sampled on leading edge, double speed mode enabled
    SPIC.INTCTRL = 0x00; // ensure SPI interrupts are disabled
    LOG_SYSTEM("SPI initialized");
    return 1;
}

static uint8_t deinit(void) {
    return 1;
}

MODULE_DEFINE(SPI, "SPI", init, deinit);