#include "gpio_driver.h"
#include "driver/gpio.h"

#define LED_PIN     2
#define BUTTON_PIN  4

void gpio_init(void)
{
    gpio_config_t io_conf = {};

    // LED OUTPUT
    io_conf.pin_bit_mask = (1ULL << LED_PIN);
    io_conf.mode = GPIO_MODE_OUTPUT;
    gpio_config(&io_conf);

    // BUTTON INPUT
    io_conf.pin_bit_mask = (1ULL << BUTTON_PIN);
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
}

void led_on(void)
{
    gpio_set_level(LED_PIN, 1);
}

void led_off(void)
{
    gpio_set_level(LED_PIN, 0);
}

uint8_t button_read(void)
{
    return gpio_get_level(BUTTON_PIN);
}
