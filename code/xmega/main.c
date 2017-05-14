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

#include "defines.h"

#include "pin_definitions.h"
#include "modules/log.h"
#include "app/core.h"
#include "drivers/host/timer.h"
#include "drivers/host/pwm.h"
#include "drivers/host/adc.h"

LOG_INIT("Main");

static void callback(Event * event, uint8_t * data);

static void sleep(void) {
    sleep_cpu();
}

static void wakeUp(void) {
    sleep_disable();
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
#ifdef WATCHDOG_ENABLE
void setupWatchdog(void) {
    CCP = CCP_IOREG_gc;
    WDT.WINCTRL = WDT_WCEN_bm;
    CCP = CCP_IOREG_gc;
    // 2 seconds
    WDT.CTRL = WDT_PER_2KCLK_gc | WDT_ENABLE_bm | WDT_CEN_bm;
    CCP = 0;
}
#endif

int main(void) {
//   CHARGER_PORT.DIRSET = CHARGER_PIN;  // Deactivate USB charging
//   CHARGER_PORT.OUTCLR = CHARGER_PIN;
    switchExternalCrystal_16mHz();

    LED_PORT.DIR = LED_PIN;
    LED_PORT.OUTTGL = LED_PIN;
#ifdef EVENT_SUPPORTS_SLEEP
    event_init(sleep, wakeUp);
    sleep_enable();
    set_sleep_mode(SLEEP_MODE_IDLE);
#endif
    PMIC.CTRL |= PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm;    //Peripheral enable - interrupt levels (ALL)
    module_init(&LOGGER);                               //Initializing the logger for use
    sei();                                              //Enabling interrupts
    module_init(&CORE);
    core_screen(SCREEN_ON);
    event_addListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed when watchdog control is better
#ifdef WATCHDOG_ENABLE
    setupWatchdog();
#endif
    LOG_SYSTEM("System initialized");
    LOG_SYSTEM(greeting);
    while (1) {
        //This is all that should happen in the main loop
        //The system will go to sleep if no more events are to be processed
        event_process();
    }
}

static void callback(Event * event, uint8_t * data __attribute__ ((unused))) {
    if (event == &EVENT_TIMER_1_HZ) {
        LED_PORT.OUTTGL = LED_PIN;
#ifdef WATCHDOG_ENABLE
        // Resets the watchdog important!
        asm("wdr");
#endif
    }
}
