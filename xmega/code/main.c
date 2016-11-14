/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */
<<<<<<< HEAD

#define F_CPU 16000000UL

=======
>>>>>>> 6d2f0f26b4681ce73fd67bab23541d0e9b96cab4
#include <avr/io.h>
#include "pin_definitions.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#include "util/module.h"
#include "util/event.h"

#include "drivers/host/uart.h"  //Breach of layering 
#include "drivers/host/timer.h" //Breach of layering 

#include "modules/screen.h"


#include "drivers/host/pwm.h"

static void callback(Event * event, uint8_t * data);

const static char hallo[] = "Hallo\n\r";
const static char elmar[] = "Elmar\n\r";
const static char ramle[] = "ramlE\n\r";

int main(void) {
    LED_PORT        = 0xFF;
    SSD1306_PORT    |=  SSD1306_CS  | SSD1306_DC | (1 << 2);
    LED_DDRD        |= LED_ERROR | LED_SOL;
    module_init(&UART);
    //module_init(&TIMER);
    module_init(&PWM);
    //module_init(&Screen);
    sei();
    //uart_job(strin, sizeof(strin), 0);
    //event_addListener(&EVENT_UART_JOB, callback);
    event_addListener(&EVENT_TIMER_1_HZ, callback);
    while (1) {
        //uart_write_blocked(strin, sizeof(strin));
        event_process();
    }
}

uint8_t el = 0;

static void callback(Event * event, uint8_t * data) {
    if (event == &EVENT_UART_JOB) {
        if (el) {
            //  uart_job(hallo, sizeof(hallo), 0);
            el = 0;
        }
        //toggle led
    } else if (event == &EVENT_TIMER_1_HZ) {
        LED_PORT = LED_PORT ^ LED_SOL;
        uart_job(elmar, sizeof(elmar), 0);
        uart_job(ramle, sizeof(ramle), 0);
        uart_job(hallo, sizeof(hallo), 0);
    }
}
