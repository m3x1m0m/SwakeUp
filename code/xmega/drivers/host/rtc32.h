/*
 * rtc32.h
 *
 * Created: 4/12/2017 7:44:49 PM
 *  Author: elmar
 */


#ifndef RTC32_H_
#define RTC32_H_

#define RTC32_SYNCBUSY_bm   0x01
#define RTC32_SYNCCNT_bm   0x0F

/* RTC interrupt vectors */
#define RTC32_OVF_vect_num  11
#define RTC32_OVF_vect      _VECTOR(10)  /* Overflow Interrupt */
#define RTC32_COMP_vect_num  11
#define RTC32_COMP_vect      _VECTOR(11)  /* Compare Interrupt */


/**
 * \internal
 * Workaround for missing CNT, PER and COMP in WinAVR header files
 * \todo Remove when header files are fixed if WinAVR release
 */
typedef struct RTC32_struct2 {
    register8_t CTRL;
    register8_t SYNCCTRL;
    register8_t INTCTRL;
    register8_t INTFLAGS;
    _DWORDREGISTER(CNT);
    _DWORDREGISTER(PER);
    _DWORDREGISTER(COMP);
} RTC32_t2;

#define RTC32 (*(RTC32_t2 *)0x0420)

#endif /* RTC32_H_ */