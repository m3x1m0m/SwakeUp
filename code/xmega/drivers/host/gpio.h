/*
 * gpio.h
 *
 * Created: 3/5/2017 8:40:01 PM
 *  Author: elmar
 */


#ifndef GPIO_H_
#define GPIO_H_
#include <avr/io.h>
#define GPIO_PIN_bm     0x0F
#define GPIO_PORT_bm    0xF0

#define GPIO_PIN_pos    0
#define GPIO_PORT_pos   4

typedef uint8_t IO_PP;

#define GPIO_OUTPUT 0
#define GPIO_INPUT 1

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4

extern PORT_t * gpio_ports[];

#define GPIO_PP(pin, port) ((port << GPIO_PORT_pos ) & GPIO_PORT_bm ) | ((pin << GPIO_PIN_pos) & GPIO_PIN_bm)

inline uint8_t gpio_pp(uint8_t pin, uint8_t port) {
    return ((port << GPIO_PORT_pos ) & GPIO_PORT_bm ) | ((pin << GPIO_PIN_pos) & GPIO_PIN_bm);
}

inline uint8_t gpio_pin(IO_PP pp) {
    return pp & GPIO_PIN_bm;
}

inline uint8_t gpio_port(IO_PP pp) {
    return (pp & GPIO_PORT_bm) >> 4;
}

inline void gpio_toggle(IO_PP pp) {
    gpio_ports[gpio_port(pp)]->OUTTGL = 1 << gpio_pin(pp);
}

inline void gpio_set(IO_PP pp) {
    gpio_ports[gpio_port(pp)]->OUTSET = 1 << gpio_pin(pp);
}

inline void gpio_clr(IO_PP pp) {
    gpio_ports[gpio_port(pp)]->OUTCLR = 1 << gpio_pin(pp);
}


inline void gpio_dir(IO_PP pp, uint8_t input) {
    if (input) {
        gpio_ports[gpio_port(pp)]->DIRSET = 1 << gpio_pin(pp);
    } else {
        gpio_ports[gpio_port(pp)]->DIRCLR = 1 << gpio_pin(pp);
    }
}

#endif /* GPIO_H_ */