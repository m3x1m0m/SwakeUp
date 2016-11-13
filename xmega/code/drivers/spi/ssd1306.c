/*
 * SSD1306.c
 *
 * Created: 11/8/2016 1:55:14 AM
 *  Author: elmar
 */ 

 #include "ssd1306.h"
#include <avr/io.h>

#include "../host/spi.h"
#include "../../pin_definitions.h"

 static void write_data(uint8_t data){
	 SSD1306_PORT &= ~SSD1306_CS;
	 SSD1306_PORT |= SSD1306_DC;
	 spi_write_blocking(data);
	 SSD1306_PORT |= SSD1306_CS;
 }
 static void ssd1306_command(uint8_t config){
	 SSD1306_PORT |= SSD1306_CS;
	 SSD1306_PORT &= ~SSD1306_CS & ~SSD1306_DC;
	 spi_write_blocking(config);
	 SSD1306_PORT |= SSD1306_CS | SSD1306_DC;
 }

 static void write_command(uint8_t config){
	 SSD1306_PORT |= SSD1306_CS;
	 SSD1306_PORT &= ~SSD1306_CS & ~SSD1306_DC;
	 spi_write_blocking(config);
	 SSD1306_PORT |= SSD1306_CS | SSD1306_DC;

 }
 
 static void write_datas(uint8_t * datas, uint16_t len){
	 SSD1306_PORT |= SSD1306_CS;
	 SSD1306_PORT |= SSD1306_DC;
	 SSD1306_PORT &= ~SSD1306_CS;
	 for (uint16_t i=0; i<len; i++) {
		 spi_write_blocking(datas[i]);
	 }
	 SSD1306_PORT |= SSD1306_CS;
 }

 void ssd1306_setRegion(uint8_t x1, uint8_t y1, uint8_t * buf, uint16_t len){
 // 	write_command(SSD1306_COLUMN_ADDR);
 // 	write_command(0x00);
 // 	write_command(0x7F);
 // 	write_command(SSD1306_PAGE_ADDR);
 // 	write_command(0x00);
 // 	write_command(0x07);
	 SSD1306_PORT |= SSD1306_CS;
	 SSD1306_PORT |= SSD1306_DC;
	 SSD1306_PORT &= ~SSD1306_CS;
	 for (uint16_t i=0; i<len; i++) {
		 spi_write_blocking(buf[i]);
	 }
	 SSD1306_PORT |= SSD1306_CS;
 }


 uint8_t ssd1306_init(void){
	SSD1306_PORT |= SSD1306_CS | SSD1306_DC;
	 ssd1306_turnOff();
 
	 write_command(SSD1306_CLOCK_DIVIDE);
	 write_command(0x80);
 
	 write_command(SSD1306_MULTIPLEX);
	 write_command(0x3F);

	 write_command(0xD3);				//SSD1306_SETDISPLAYOFFSET
	 write_command(0x00);

	 write_command(0x40);				//SSD1306_SETSTARTLINE
 
	 write_command(0x8D);				//SSD1306_CHARGEPUMP
	 write_command(0x14);

	 write_command(0x20);               // SSD1306_MEMORYMODE
	 write_command(0x00);               // 0x0 act like ks0108

	 write_command(0xA1);				//SSD1306_SEGREMAP | 0x01

	 write_command(0xC8);				//SSD1306_COMSCANDEC
	 write_command(0xDA);				//SSD1306_SETCOMPINS
	 write_command(0x12);

	 ssd1306_contrast(0xCF);

	 write_command(SSD1306_PRECHARGE);
	 write_command(0xF1);

	 ssd1306_command(0xDB);            // SSD1306_SETVCOMDETECT
	 ssd1306_command(0x40);

	ssd1306_turnOn();


	 //write_datas(&buffer,(uint16_t)SSD1306_BUFFERSIZE);

	 return 1;
 }

 void ssd1306_turnOn(void){
 	 write_command(SSD1306_ENTIRE_ON);
 	 write_command(SSD1306_NORMAL);
 	 write_command(SSD1306_POWER_ON);
 }
 
 void ssd1306_turnOff(void){
	write_command(SSD1306_POWER_OFF);
 }

 void ssd1306_contrast(uint8_t contrast){
	write_command(SSD1306_CONTRAST);
	write_command(contrast);
 }

 MODULE_DEFINE(SSD1306,"SSD1306",ssd1306_init,0, &SPI);