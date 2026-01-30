#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "uart_driver.h"
#include "gpio_driver.h"
#include "driver/uart.h"
#include "string.h"

#define BUF_SIZE 100

void app_main(void)
{
    char data[BUF_SIZE];

    gpio_init();
    uart_init();

    uart_send("ESP32 GPIO + UART Project Ready\n");

    while (1)
    {
        int len = uart_read_bytes(UART_NUM_0, (uint8_t*)data, BUF_SIZE, 100 / portTICK_PERIOD_MS);

        if (len > 0)
        {
            data[len] = 0;

            if (strstr(data, "LED_ON"))
            {
                led_on();
                uart_send("LED ON\n");
            }
            else if (strstr(data, "LED_OFF"))
            {
                led_off();
                uart_send("LED OFF\n");
            }
            else if (strstr(data, "BTN"))
            {
                if (button_read())
                    uart_send("BUTTON RELEASED\n");
                else
                    uart_send("BUTTON PRESSED\n");
            }
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
