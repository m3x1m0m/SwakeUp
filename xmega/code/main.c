/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */ 

 #define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "util/event.h"
#include "drivers/host/uart.h"
#include "drivers/host/spi.h"
#include "drivers/spi/ssd1306.h"
#include "util/module.h"

EVENT_REGISTER(EVENT_COUNT,"counter event");

int main(void) {
	DDRD |= (1<<CS) | (1<<DC) | (1<<2);
	module_init(&SSD1306);	
// 	write_command(SSD1306_COLUMN_ADDR);
// 	write_command(0x00);
// 	write_command(0x7F);
// 	write_command(SSD1306_PAGE_ADDR);
// 	write_command(0x00);
// 	write_command(0x07);
	//write_datas(&screenBuf,SCREEN_WIDTH*SCREEN_HEIGHT);
    /* Replace with your application code */	 
	
	_delay_ms(1000);
	uint16_t i = 0;
    while (1) {
		i++;
		_delay_ms(100);
		if(i==10){
			event_fire(EVENT_COUNT, (uint8_t*) 0);
		}
		event_process();
    }
}

