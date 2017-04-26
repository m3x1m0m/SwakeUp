/*
 * pin_definitions.h
 *
 * Created: 11/12/2016 6:10:09 PM
 *  Author: elmar
 */


#ifndef PIN_DEFINITIONS_H_
#define PIN_DEFINITIONS_H_

#include "defines.h"
#include <avr/io.h>

#include "drivers/host/gpio.h"  //TODO find a nicer place for this

#ifdef GPIO_H_
#define PP
#endif

#define PROTO_TEST

#ifdef REV_1
#include "pin_rev_1.h"
#else
#include "pin_rev_2.h"
#endif

#endif /* PIN_DEFINITIONS_H_ */