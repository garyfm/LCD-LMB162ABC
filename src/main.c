#include <stdio.h>

#include "stm32f7xx_hal_msp.h"
#include "stm32f7xx_hal_gpio.h"

#include "lcd.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    
    UART_HandleTypeDef huart3;
    MX_USART3_UART_Init(&huart3);

    LCD lcd;

    lcd_init(&lcd);

    while (1) {}
}

