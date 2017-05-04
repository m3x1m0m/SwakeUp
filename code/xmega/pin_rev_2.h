/*
 * pin_rev_2.h
 *
 * Created: 4/12/2017 5:05:56 PM
 *  Author: elmar
 */


#ifndef PIN_REV_2_H_
#define PIN_REV_2_H_


#define LED_PORT            PORTB
#define LED_PIN             (1<<0)
#define LED_PP()            gpio_pp(0, GPIO_PORTB)

#ifndef PP
#define DEBUG_LED_TOG()       LED_PORT.OUTTGL = LED_PIN
#define DEBUG_LED_ON()        LED_PORT.OUTCLR = LED_PIN
#define DEBUG_LED_OFF()       LED_PORT.OUTSET = LED_PIN
#else
#define DEBUG_LED_TOG()       LED_PORT.OUTTGL = LED_PIN
#define DEBUG_LED_ON()        LED_PORT.OUTCLR = LED_PIN
#define DEBUG_LED_OFF()       LED_PORT.OUTSET = LED_PIN
#endif

#define DEBUG_UART            USARTD1

#define BUTTON_PORT         PORTB
#define BUTTON_PIN          (1<<1)
#define BUTTON_PP()         gpio_pp(1, GPIO_PORTB)

#define ESP_GPIO_PORT       PORTA
#define ESP_RST_PORT        PORTA
#define ESP_RST_PIN         (1<<3)
#define ESP_PWR_SAVE_N_PORT PORTA
#define ESP_PWR_SAVE_N_PIN  (1<<2)
#define ESP_ENABLE_PORT     PORTA
#define ESP_ENABLE_PIN      (1<<1)
#define ESP_SLEEP_PORT      PORTB
#define ESP_SLEEP_PIN       (1<<3)
#define ESP_FP_PORT         PORTB
#define ESP_FP_PIN          (1<<2)
#define ESP_UART_PIN_PORT   PORTC
#define ESP_UART_PORT       USARTC0
#define ESP_UART_RX         (1<<2)
#define ESP_UART_RX_PP()    gpio_pp(2, GPIO_PORTD)
#define ESP_UART_TX         (1<<3)
#define ESP_UART_TX_PP()    gpio_pp(3, GPIO_PORTD)

#define CP_PORT             USARTD1
#define CP_PIN_PORT         PORTD
#define CP_RX_PIN           (1<<6)
#define CP_RX_PP()          GPIO_PP(6, GPIO_PORTE)
#define CP_TX_PIN           (1<<7)
#define CP_TX_PP()          GPIO_PP(7, GPIO_PORTE)

#define SPIC_PORT           PORTC
#define SPIC_SCK            (1<<7)
#define SPIC_MISO           (1<<6)
#define SPIC_MOSI           (1<<5)
#define SPI_SS              (1<<4)


#define SEPS525F_PORT       PORTC
#define SEPS525F_SCL        (1<<7)
#define SEPS525F_SCL_PP()   gpio_pp(9, GPIO_PORTC)
#define SEPS525F_SDI        (1<<5)
#define SEPS525F_SDI_PP()   gpio_pp(6, GPIO_PORTC)
#define SEPS525F_NOT        (1<<4)   //NOTE THIS SHOULD NOT BE USED
#define SEPS525F_NOT_PP()   gpio_pp(5, GPIO_PORTC)
#define SEPS525F_RS         (1<<3)
#define SEPS525F_RS_PP()    gpio_pp(4, GPIO_PORTC)
#define SEPS525F_CSB        (1<<2)
#define SEPS525F_CSB_PP()   gpio_pp(3, GPIO_PORTC)

#define PWM_PORT            PORTD
#define PWM_1               (1<<0)
#define PWM_2               (1<<1)
#define PWM_3               (1<<2)
#define PWM_4               (1<<3)

#define ADC_PORT            PORTA
#define ADC_1               (1<<4)
#define ADC_2               (1<<5)
#define ADC_3               (1<<6)
#define ADC_4               (1<<7)




#endif /* PIN_REV_2_H_ */
