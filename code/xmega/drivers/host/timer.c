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

/////////////////////////////////////////////////////////////////////////////////
// Global variables
/////////////////////////////////////////////////////////////////////////////////
static volatile divider = 0;

/////////////////////////////////////////////////////////////////////////////////
// Register events
/////////////////////////////////////////////////////////////////////////////////
EVENT_REGISTER(EVENT_TIMER_1_HZ, "1 second pulse");
EVENT_REGISTER(EVENT_TIMER_10_HZ, "10 millisecond pulse");
EVENT_REGISTER(EVENT_TIMER_100_HZ, "10 millisecond pulse");
EVENT_REGISTER(EVENT_TIMER_1000_HZ, "1 millisecond pulse");
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

/////////////////////////////////////////////////////////////////////////////////
// Init TCC0 for 1 kHz tick
/////////////////////////////////////////////////////////////////////////////////
void init_TCC0(void)
{
	#ifdef EXPERIMENTAL
	TCC0.PER = TICK_1KHZ;										
	#else
	TCC0.PER = TICK_100HZ;
	#endif
	TCC0.CTRLA = TC_CLKSEL_DIV64_gc;							// 16 MHz / 64 = 250 kHz
	TCC0.INTCTRLA |= TC_OVFINTLVL_HI_gc;						// Activate interrupt
}

void deinit_TCC0(void)
{
	TCC0.CTRLA = TC_CLKSEL_OFF_gc;
}


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
    init_TCC0();
	LOG_SYSTEM("Timers set up");
    return 1;
}

static uint8_t deinit(void) {
	deinit_TCC0();
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////
// Interrupt service routines
/////////////////////////////////////////////////////////////////////////////////
#ifdef EXPERIMENTAL
ISR(TCC0_OVF_vect)
{
	event_fire(&EVENT_TIMER_1000_HZ, 0);
	divider++;
	if(divider == 10)
	{
		event_fire(&EVENT_TIMER_100_HZ, 0);
		//LED_PORT.OUTTGL = LED_PIN;
		divider = 0; 
	}
}
#else
ISR(TCC0_OVF_vect)
{
	event_fire(&EVENT_TIMER_100_HZ, 0);
	//LED_PORT.OUTTGL = LED_PIN;
	if(divider == 10)
	{
		event_fire(&EVENT_TIMER_10_HZ, 0);
		//LED_PORT.OUTTGL = LED_PIN;
		divider = 0;
	}
}
#endif

ISR(RTC_OVF_vect) {
    event_fire(&EVENT_TIMER_1_HZ, 0);
    runTime++;
}

MODULE_DEFINE(TIMER, "Timer", init, deinit);