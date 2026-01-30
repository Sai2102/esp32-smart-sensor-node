#include "uart_driver.h"
#include "driver/uart.h"
#include "string.h"

#define UART_NUM UART_NUM_0

void uart_init(void)
{
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_param_config(UART_NUM, &uart_config);
    uart_driver_install(UART_NUM, 1024, 0, 0, NULL, 0);
}

void uart_send(const char *data)
{
    uart_write_bytes(UART_NUM, data, strlen(data));
}
