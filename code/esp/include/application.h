/*
 * application.h
 *
 *  Created on: May 8, 2017
 *      Author: elmar
 */

#ifndef INCLUDE_APPLICATION_H_
#define INCLUDE_APPLICATION_H_

#include <Libraries/OneWire/OneWire.h>
#include "userSettings.h"
#include "streams.h"

//OneWire stuff
const uint8_t onewire_pin = 2;
extern OneWire ds;

extern unsigned long counter; // Kind of heartbeat counter

const uint8_t ConfigJsonBufferSize = 200; // Application configuration JsonBuffer size ,increase it if you have large config
const uint16_t ConfigFileBufferSize = 2048; // Application configuration FileBuffer size ,increase it if you have large config

//Webserver
void startWebServer();

#endif /* INCLUDE_APPLICATION_H_ */
