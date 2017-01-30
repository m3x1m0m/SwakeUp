/*
 * timer.c
 *
 * Created: 11/14/2016 1:11:06 AM
 *  Author: elmar
 */


#include <avr/interrupt.h>
#include "timer.h"
#include "../../modules/log.h"
#include "../../pin_definitions.h"
#include "uart.h"
EVENT_REGISTER(EVENT_TIMER_1_HZ, "1 second pulse");
LOG_INIT("Timer");




// ISR(RTC_OVF_vect) {
//     while (!((CP_PORT).STATUS & USART_DREIF_bm));
//     (CP_PORT).DATA = 'o';
//     //uart_write_blocked('O', CP_PORT);
//     //LED_PORT.OUTTGL = LED_PIN;
// }
//
// ISR(RTC_COMP_vect) {
//     while (!((CP_PORT).STATUS & USART_DREIF_bm));
//     (CP_PORT).DATA = 'c';
//     //uart_write_blocked('C', CP_PORT);
//     //LED_PORT.OUTTGL = LED_PIN;
// }

static uint8_t init(void) {
    OSC.CTRL |= OSC_RC32KEN_bm;
    while ( ( OSC.STATUS & OSC_RC32KRDY_bm ) == 0);
    CLK.RTCCTRL = CLK_RTCSRC_RCOSC_gc | CLK_RTCEN_bm;
    while ( RTC.STATUS & RTC_SYNCBUSY_bm  );
    RTC.PER = 1023;
    RTC.CNT = 0;
    RTC.COMP = 0;
    RTC.CTRL = ( RTC.CTRL & ~RTC_PRESCALER_gm ) | RTC_PRESCALER_DIV1_gc;
    RTC.INTCTRL = ( RTC.INTCTRL & ~( RTC_COMPINTLVL_gm | RTC_OVFINTLVL_gm ) ) | RTC_OVFINTLVL_LO_gc | RTC_COMPINTLVL_OFF_gc;
    return 1;
}

static uint8_t deinit(void) {
    return 1;
}

ISR(RTC_OVF_vect) {
    // LED_PORT.OUTTGL = LED_PIN;
    //uart_write_blocked('O', CP_PORT);
    event_fire(&EVENT_TIMER_1_HZ, 0);
}

MODULE_DEFINE(TIMER, "Timer", init, deinit);