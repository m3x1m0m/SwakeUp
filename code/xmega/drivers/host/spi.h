/*
 * spi.h
 *
 * Created: 2/1/2017 5:24:26 PM
 *  Author: elmar
 */


#ifndef SPI_H_
#define SPI_H_

#include "../../util/module.h"

uint8_t spi_write_blocked(uint8_t byte);
uint8_t spi_writes_blocked(uint8_t * bytes, uint8_t len);

MODULE_EXP(SPI);

#endif /* SPI_H_ */