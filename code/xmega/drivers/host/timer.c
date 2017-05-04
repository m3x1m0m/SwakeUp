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

#undef REV_2
#define REV_1

#ifndef REV_1
#include "rtc32.h"
#undef RTC32
#undef RTC
#undef RTC_OVF_vect
#define RTC_OVF_vect RTC32_OVF_vect
/**
 * \internal
 * Workaround for missing CNT, PER and COMP in WinAVR header files
 * \todo Remove when header files are fixed if WinAVR release
 */
#define RTC (*(RTC32_t2 *)0x0420)
#endif
EVENT_REGISTER(EVENT_TIMER_1_HZ, "1 second pulse");
EVENT_REGISTER(EVENT_ALARM, "ms alarm");

LOG_INIT("Timer");

//static uint16_t alarms[6];
static uint16_t runTime = 0;
// static uint16_t msCounter = 0; // TODO implement?

uint16_t timer_runTime(void) {
    return runTime;
}
int8_t   timer_timeOutEvent(uint16_t duration) {
    (void)duration; //TODO
    LOG_ERROR("Not implemented");
    return -1;
}

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
#ifdef REV_1
    OSC.CTRL |= OSC_RC32KEN_bm;
    while ( ( OSC.STATUS & OSC_RC32KRDY_bm ) == 0);
    CLK.RTCCTRL = CLK_RTCSRC_RCOSC_gc | CLK_RTCEN_bm;
    while ( RTC.STATUS & RTC_SYNCBUSY_bm  );
#else
    OSC.CTRL |= OSC_XOSCEN_bm;
    while ( ( OSC.STATUS & OSC_XOSCRDY_bm ) == 0);
    CLK.RTCCTRL = CLK_RTCSRC_RCOSC_gc | CLK_RTCSRC_TOSC_gc;
    while ( RTC.SYNCCTRL & RTC32_SYNCBUSY_bm  );
#endif
    RTC.PER = 1023;
    RTC.CNT = 0;
    RTC.COMP = 0;
    RTC.CTRL = ( RTC.CTRL & ~RTC_PRESCALER_gm ) | RTC_PRESCALER_DIV1_gc;
    RTC.INTCTRL = ( RTC.INTCTRL & ~( RTC_COMPINTLVL_gm | RTC_OVFINTLVL_gm ) ) | RTC_OVFINTLVL_LO_gc | RTC_COMPINTLVL_OFF_gc;
    LOG_SYSTEM("Timer set up");
    return 1;
}

static uint8_t deinit(void) {
    return 1;
}

ISR(RTC_OVF_vect) {
    event_fire(&EVENT_TIMER_1_HZ, 0);
    runTime++;
}

MODULE_DEFINE(TIMER, "Timer", init, deinit);