/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */ 

 #define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "util/module.h"
#include "util/event.h"
#include "drivers/host/uart.h"	//Breach of layering 
#include "modules/screen.h"
#include "pin_definitions.h"

EVENT_REGISTER(EVENT_COUNT,"counter event");

int main(void) {
	SSD1306_PORT |=  SSD1306_CS  | SSD1306_DC | (1<<2);
	uart_init(B9600);
	module_init(&Screen);
		
// 	write_command(SSD1306_COLUMN_ADDR);
// 	write_command(0x00);
// 	write_command(0x7F);
// 	write_command(SSD1306_PAGE_ADDR);
// 	write_command(0x00);
// 	write_command(0x07);
	//write_datas(&screenBuf,SCREEN_WIDTH*SCREEN_HEIGHT);
    /* Replace with your application code */	 
	
	_delay_ms(1000);
	char strin[6] = "Hallo\n";
	uint16_t i = 0;
    while (1) {
		i++;
		_delay_ms(1000);
		if(i==10){
			//event_fire(EVENT_COUNT, (uint8_t*) 0);
		}
		uart_write_blocked(&strin,6); 
		//event_process();
    }
}

