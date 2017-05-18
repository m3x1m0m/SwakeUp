/*
 * pin_rev_1.h
 *
 * Created: 4/12/2017 5:05:10 PM
 *  Author: elmar
 */


#ifndef PIN_REV_1_H_
#define PIN_REV_1_H_

#define LED_PORT            PORTB
#define LED_PIN             (1<<0)
#define LED_PP()            gpio_pp(0, GPIO_PORTB)

#ifndef PP
#define DEBUG_LED_TOG()       LED_PORT.OUTTGL = LED_PIN
#define DEBUG_LED_ON()        LED_PORT.OUTCLR = LED_PIN
#define DEBUG_LED_OFF()       LED_PORT.OUTSET = LED_PIN
#else
static const IO_PP _led =     GPIO_PP(0, GPIO_PORTB);
#define DEBUG_LED_TOG()       gpio_toggle(_led)
#define DEBUG_LED_ON()        gpio_clr(_led)
#define DEBUG_LED_OFF()       gpio_set(_led)
#endif

#define DEBUG_UART            USARTE0

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
#define ESP_SLEEP_PORT      PORTA
#define ESP_SLEEP_PIN       (1<<3)
#define ESP_FP_PORT         PORTA
#define ESP_FP_PIN          (1<<2)
#define ESP_UART_PIN_PORT   PORTD
#define ESP_UART_PORT       USARTD1
#define ESP_UART_RX         (1<<6)
#define ESP_UART_RX_PP()    gpio_pp(6, GPIO_PORTD)
#define ESP_UART_TX         (1<<7)
#define ESP_UART_TX_PP()    gpio_pp(7, GPIO_PORTD)

#define CP_PORT             USARTE0
#define CP_PIN_PORT         PORTE
#define CP_RX_PIN           (1<<2)
#define CP_RX_PP()          GPIO_PP(2, GPIO_PORTE)
#define CP_TX_PIN           (1<<3)
#define CP_TX_PP()          GPIO_PP(3, GPIO_PORTE)

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
#define PWM_RED (1 << 0)
#define PWM_BLUE (1 << 1)
#define PWM_GREEN (1 << 4)
#define PWM_OLED (1 << 5)

#define ADC_PORT PORTA
#define ADC_RED_PIN_NU 7
#define ADC_BLUE_PIN_NU 6
#define ADC_GREEN_PIN_NU 5
#define ADC_OLED_PIN_NU 4



#endif /* PIN_REV_1_H_ */