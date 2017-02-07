/*
 * pin_definitions.h
 *
 * Created: 11/12/2016 6:10:09 PM
 *  Author: elmar
 */


#ifndef PIN_DEFINITIONS_H_
#define PIN_DEFINITIONS_H_

#define REV_1

//#define EVENT_SUPPORTS_SLEEP

#define DEBUG_LED_TOG       LED_PORT.OUTTGL = LED_PIN;
#define DEBUG_LED_ON        LED_PORT.OUTCLR = LED_PIN;
#define DEBUG_LED_OFF       LED_PORT.OUTSET = LED_PIN;
#define DEBUG_UART          USARTE0

#define F_CPU           16000000UL

#define LED_PORT            PORTB
#define LED_PIN             (1<<0)

#define BUTTON_PORT         PORTB
#define BUTTON_PIN          (1<<1)

#define ESP_RST_PORT        PORTA
#define ESP_RST_PIN         (1<<3)
#define ESP_PWR_SAVE_N_PORT PORTA
#define ESP_PWR_SAVE_N_PIN  (1<<2)
#define ESP_PWR_PORT        PORTA
#define ESP_PWR_PIN         (1<<1)
#define ESP_SLEEP_PORT      PORTA
#define ESP_SLEEP_PIN       (1<<3)
#define ESP_FP_PORT         PORTA
#define ESP_FP_PIN          (1<<2)
#define ESP_UART_PIN_PORT   PORTD
#define ESP_UART_PORT       USARTD1
#define ESP_UART_RX         (1<<6)
#define ESP_UART_TX         (1<<7)

#define CP_PORT             USARTE0
#define CP_PIN_PORT         PORTE
#define CP_RX_PIN           (1<<2)
#define CP_TX_PIN           (1<<3)

#define SCREEN_PORT         PORTC
#define SCREEN_SCL          (1<<7)
#define SCREEN_SDI          (1<<5)
#define SCREEN_RS           (1<<3)
#define SCREEN_CSB          (1<<2)

#define PWM_PORT            PORTD
#define PWM_1               (1<<0)
#define PWM_2               (1<<1)
#define PWM_3               (1<<4)
#define PWM_4               (1<<5)

#define ADC_PORT            PORTA
#define ADC_1               (1<<4)
#define ADC_2               (1<<5)
#define ADC_3               (1<<6)
#define ADC_4               (1<<7)

#endif /* PIN_DEFINITIONS_H_ */