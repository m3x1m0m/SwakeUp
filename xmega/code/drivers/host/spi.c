/*
 * spi.c
 *
 * Created: 2/1/2017 5:25:38 PM
 *  Author: elmar
 */
#include "spi.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../pin_definitions.h"
#include "../../modules/log.h"

LOG_INIT("SPI");
EVENT_REGISTER(SPI_FINISHED, "Completed SPI job");

#define BUFFER_SIZE 128
static uint8_t writeBuffer[BUFFER_SIZE];
static uint8_t head = 0, tail = 0, size = 0;
static uint8_t interruptEnabled = 0;

static uint8_t _lock = 0;

#define lock() while (_lock); _lock = 1
#define unlock() _lock = 0

static inline uint8_t softlock(void) {
    if (_lock) return 0;
    _lock = 1;
    return 1;
}

static inline void SPI_SET_SS() {
    SPIC_PORT.OUTSET = SPI_SS;
}

static inline void SPI_RESET_SS() {
    SPIC_PORT.OUTCLR = SPI_SS;
}

ISR(SPIC_INT_vect) {
    //LOG_DEBUG("Writing byte!");
    //if (SPIC.STATUS & SPI_IF_bm) {
    if (softlock()) {
        if (size > 0) {
            SPIC.DATA = writeBuffer[tail];
            tail++;
            if (tail == BUFFER_SIZE) tail = 0;
        } else {
            event_fire(&SPI_FINISHED, (uint8_t*)head);
            interruptEnabled = 0;
            SPIC.INTCTRL &= ~SPI_INTLVL_MED_gc;
        }
        unlock();
    }
    // }
}

uint8_t spi_write(uint8_t byte) {
    if (size + 1 == BUFFER_SIZE) return 0;
    writeBuffer[head] = byte;
    head++;
    if (head == BUFFER_SIZE) head = 0;
    if (!interruptEnabled) {
        SPIC.INTCTRL |= SPI_INTLVL_MED_gc;
        interruptEnabled = 1;
    }
    size++;
    return 1;
}

uint8_t spi_writes(uint8_t * bytes, uint8_t len) {
    uint8_t i;
    lock();
    for (i = 0; i < len; i++) {
        if (size + 1 == BUFFER_SIZE) {
            return i;
            unlock();
        }
        writeBuffer[head] = bytes[i];
        head++;
        if (head == BUFFER_SIZE) head = 0;
        if (!interruptEnabled) {
            SPIC.INTCTRL |= SPI_INTLVL_MED_gc;
            interruptEnabled = 1;
        }
        size++;
    }
    unlock();
    return i;
}
uint8_t spi_write_blocked(uint8_t byte) {
    SPIC.DATA = byte;  //send it
    while (!(SPIC.STATUS & SPI_IF_bm)); //wait for the transfer to end
    return 1;
}
uint8_t spi_writes_blocked(uint8_t * bytes, uint8_t len) {
    uint8_t i;
    for (i = 0; i < len; i++) {
        SPIC.DATA = bytes[i];  //send it
        while (!(SPIC.STATUS & SPI_IF_bm)); //wait for the transfer to end
    }
    return 1;
}

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
    LOG_DEBUG("Finished %d ,%d", head, tail);
}

static uint8_t init(void) {
    //1101 0000
    lock();
    SPIC_PORT.DIRSET = SPIC_SCK | SPIC_MOSI | SPI_SS;
    SPIC_PORT.PIN4CTRL = PORT_OPC_WIREDANDPULL_gc; // wired AND & pull-up
    SPIC_PORT.DIRCLR = SPIC_MISO;
    SPIC_PORT.PIN6CTRL = PORT_OPC_PULLDOWN_gc;
    SPI_SET_SS();
    //out C5: DATA ABC (MOSI) d10
    //in C6: not active input (MISO)
    //out C7: DATA zegar (SCK) d21
    SPIC.CTRL |= (SPI_CLK2X_bp | SPI_ENABLE_bm | ~SPI_DORD_bm | SPI_MASTER_bm | SPI_MODE_0_gc | SPI_PRESCALER_DIV4_gc);
    //SPIC.INTCTRL |= SPI_INTLVL_LO_gc;  //set interrupts
    SPIC.STATUS;    //both these are to take IF down
    SPIC.DATA;  //when I don't use interrupts
    LOG_SYSTEM("SPI initialized");
    unlock();
    event_addListener(&SPI_FINISHED, &callback);
    return 1;
}
static uint8_t deinit(void) {
    return 1;
}
MODULE_DEFINE(SPI, "SPI", init, deinit);