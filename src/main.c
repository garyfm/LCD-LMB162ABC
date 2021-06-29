#include <stdio.h>

#include "retarget.h"
#include "stm32f7xx_hal_msp.h"

#include "lcd.h"

static UART_HandleTypeDef huart3;

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART3_UART_Init(&huart3);
    RetargetInit(&huart3);

    LCD lcd;

    lcd_init(&lcd);

    while (1)
    {
        printf("Hello, World!\r\n");
    }
}

