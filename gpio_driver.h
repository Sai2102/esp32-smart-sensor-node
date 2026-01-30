#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>

void gpio_init(void);
void led_on(void);
void led_off(void);
uint8_t button_read(void);

#endif
