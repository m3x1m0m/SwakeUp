/*
 * spi.h
 *
 * Created: 11/7/2016 10:59:37 AM
 *  Author: elmar
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

#include "../../util/module.h"

// #include "circularbuffer.h"

// typedef void (*spi_read_cb)(CircularBuffer * outBuffer);

uint8_t spi_init(void);
uint8_t spi_deinit(void);

// size_t spi_write(uint8_t data);
void spi_write_blocking(uint8_t data);
// size_t spi_writes(uint8_t * datas, size_t len);
/*
void spi_read(uint8_t amount);
void spi_read_blocking(uint8_t * buf, uint8_t len);
void spi_read_callback(uint8_t amount, spi_read_cb cb);


CircularBuffer * getOutBuffer(void);
CircularBuffer * getInBuffer(void);

*/

MODULE_EXP(SPI);

#endif /* SPI_H_ */