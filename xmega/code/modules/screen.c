/*
 * screen.c
 *
 * Created: 11/12/2016 6:02:02 PM
 *  Author: elmar
 */ 
 #include "../drivers/spi/ssd1306.h"
 #include "screen.h"

 void screen_text(char * text, uint8_t x, uint8_t y){

 }
 
 void screen_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){

 }
 
 void screen_filled_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){

 }
 
 void screen_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){

 }
 
 void screen_pixel(uint8_t x, uint8_t y){

 }

 static uint8_t init(void){

 }

 static uint8_t deinit(void){

 }

 MODULE_DEFINE(Screen,"Screen",&init,&deinit,SSD1306);