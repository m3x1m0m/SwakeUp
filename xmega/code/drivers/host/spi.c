/*
 * spi.c
 *
 * Created: 11/7/2016 10:59:54 AM
 *  Author: elmar
 */

#include <avr/io.h>
#include "spi.h"
#include "../../util/job.h"
#include "../../pin_definitions.h"

// #include <avr/interrupt.h>

JOB_BUFFER_INIT(SpiBuffer, SPI_MAX_JOBS);

#define SPI_SPCR_ENABLE (1<<SPE)
#define SPI_SPCR_MASTER (1<<MSTR)
#define SPI_SPCR_FCK_16 (1<<SPR0)

EVENT_REGISTER(SPI_JOB_FINISHED, "Reading or writing");


//static CircularBuffer outBuffer;
//static CircularBuffer inBuffer;
//static volatile uint8_t transmitting = 0;


uint8_t spi_init(void) {
    /* Initialize the output buffer */
    // circularBuffer_init(&outBuffer);
    /* Set MOSI, SCK as Output */
    // TODO SPI_PORT |= SPI_DDRB_MOSI | SPI_DDRB_SCK | SPI_DDRB_SS;
    /* Enable SPI, Master, set clock rate fck/16 */
    // TODO SPCR = SPI_SPCR_ENABLE | SPI_SPCR_MASTER | SPI_SPCR_FCK_16;
    return 1;
}

uint8_t spi_deinit(void) {
    return 1;
}
/*
int8_t spi_write(uint8_t data){
if(!transmitting){
   SPDR = data;
   transmitting = 1;
   return 1;
}else {
   return circularBuffer_writeByte(data);
}
}

uint8_t spi_writes(uint8_t * datas, uint8_t len){
return circularBuffer_write(&outBuffer,datas,len);
}*/
uint8_t spi_writes(uint8_t * datas, uint8_t len) {
    if (job_add(&SpiBuffer, datas, len, 0) == 0) {
        //we are full
        return 0;
    }
    //Todo enable interrupts
    return 1;
}

void spi_write_blocking(uint8_t data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}


// SPI Transmission/reception complete ISR
/*
ISR(SPI_STC_vect) {

}
*/

MODULE_DEFINE(SPI, "SPI", spi_init, spi_deinit);