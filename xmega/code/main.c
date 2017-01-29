/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/sleep.h>
#include "pin_definitions.h"

#include <avr/interrupt.h>
#include <util/delay.h>

#include "util/module.h"
#include "util/event.h"
#include "drivers/host/uart.h"
#include "modules/log.h"
<<<<<<< HEAD

#include "drivers/host/pwm.h"
=======
>>>>>>> logic_board

static void callback(Event * event, uint8_t * data);

LOG_INIT("Main");

static void sleep(void) {
    // sleep_cpu();
}

static void wakeUp(void) {
    //sleep_disable();
    //ADCSRA = adcsra;
}

void switchExternalCrystal_16mHz(void) {
    //16MHz external crystal
    OSC_XOSCCTRL = OSC_FRQRANGE_12TO16_gc | OSC_XOSCSEL_XTAL_16KCLK_gc;
    //Enable external oscillator
    OSC_CTRL |= OSC_XOSCEN_bm;
    //Wait for clock stabilization
    while (!(OSC_STATUS & OSC_XOSCRDY_bm));
    // Selects clock system as external clock
    // through change protection mechanism
    CCP = CCP_IOREG_gc;
    CLK_CTRL = CLK_SCLKSEL_XOSC_gc;
}
static char * name = "elmar";
static char * name1 = "ELMAR";
int main(void) {
    switchExternalCrystal_16mHz();
    LED_PORT.DIR = LED_PIN;
    LED_PORT.OUTTGL = LED_PIN;
    module_init(&UART);
#ifdef EVENT_SUPPORTS_SLEEP
    //event_init(sleep, wakeUp);
    //sleep_enable();
    //set_sleep_mode(SLEEP_MODE_IDLE);
#endif
<<<<<<< HEAD
=======
    //module_init(&LOGGER);
    //module_init(&TIMER);
    //event_addListener(&EVENT_TIMER_1_HZ, callback);
>>>>>>> logic_board
    //module_init(&Screen);
    PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm; //peripheral enable - interrupt levels (ALL)
    sei();
    uart_job(name, 5, 0, &CP_PORT);
    while (1) {
        //uart_writes_blocked("Elmar", 5, &CP_PORT);
        event_process();
    }
}

static void callback(Event * event, uint8_t * data) {
    static uint8_t i = 0;
//     if (event == &EVENT_TIMER_1_HZ) {
//         LOG_DEBUG("Timer event %d", i++);
//         LED_PORT = LED_PORT ^ LED_SOL;
//     }
<<<<<<< HEAD
}
=======
}

>>>>>>> logic_board
