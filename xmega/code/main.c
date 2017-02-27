/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "pin_definitions.h"
#include "drivers/host/timer.h"
#include "drivers/host/uart.h"
#include "drivers/uart/terminal.h"
#include "modules/log.h"
#include "modules/command.h"
#include "drivers/spi/SEPS525F.h"
#include "drivers/uart/esp8266.h"
#include "modules/screenterminal.h"
#include "modules/screen.h"

LOG_INIT("Main");

static void callback(Event * event, uint8_t * data);
#define TAB "\t\t\t\t"
#define NL  "\r\n"

static const char greeting[] = NL TAB"===================="NL
                               TAB"Welcome to SwakeUpp!"NL
                               TAB"Build date:"NL
                               TAB __DATE__" "__TIME__ NL
                               TAB"The time is:"NL
                               TAB"18:08"NL
                               TAB"===================="NL;


static void ledCommand(uint8_t len __attribute__ ((unused)), uint8_t * data __attribute__ ((unused))) {
    switch (data[0]) {
    case '1':
        LOG_DEBUG("Turning led on");
        DEBUG_LED_ON();
        break;
    case '0':
        LOG_DEBUG("Turning led off");
        DEBUG_LED_OFF();
        break;
    case 't':
    case 'T':
        LOG_DEBUG("Toggling led");
        DEBUG_LED_TOG();
        break;
    }
}

static void atCommand(uint8_t len __attribute__ ((unused)), uint8_t * data __attribute__ ((unused))) {
    LOG_DEBUG("Writing AT\\n\\r");
    uart_write("AT\r\n", 4, &ESP_UART_PORT);
}


static void sleep(void) {
    //sleep_enable();
    sleep_cpu();
}

static void wakeUp(void) {
    sleep_disable();
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

int main(void) {
    switchExternalCrystal_16mHz();
    LED_PORT.DIR = LED_PIN;
    LED_PORT.OUTTGL = LED_PIN;
#ifdef EVENT_SUPPORTS_SLEEP
    event_init(sleep, wakeUp);
    sleep_enable();
    set_sleep_mode(SLEEP_MODE_IDLE);
#endif
    //module_init(&Screen);
    PMIC.CTRL |= PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm;    //Peripheral enable - interrupt levels (ALL)
    module_init(&LOGGER);                               //Initializing the logger for use
    sei();                                              //Enabling interrupts
    module_init(&COMMAND);
    module_init(&TIMER);                                //Timer
    event_addListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    command_hook_description('L', &ledCommand, "L<option> options: T(toggle) 1(on) 0(off)\0");
    command_hook_description('A', &atCommand, "Sends AT command to ESP, no options\0");
    //module_init(&SEPS525F);
    module_init(&ESP8266);
    LOG_SYSTEM("System initialized");
    //log_redirectOutput(screenterminal_sink());
    LOG_SYSTEM(greeting);
    //module_init(&SCREEN);
    //event_addListener(&EVENT_UART_JOB, callback);
    while (1) {
        //This is all that should happen in the main loop
        //The system will go to sleep if no more events are to be processed
        event_process();
    }
}

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
    //static uint8_t i = 0;
    if (event == &EVENT_TIMER_1_HZ) {
        LED_PORT.OUTTGL = LED_PIN;
        //LOG_DEBUG("Time passed: %d", timer_runTime());
    }
}