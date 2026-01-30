#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensor.h"
#include "wifi.h"

void app_main(void)
{
    wifi_init();

    while (1)
    {
        float temp = read_temperature();
        printf("Temperature: %.2f\n", temp);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
