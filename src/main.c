#include <stdio.h>

#include "stm32f7xx_hal_msp.h"
#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_tim.h"

#include "lcd.h"
#include "lmb162.h"



int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    
    MX_USART3_UART_Init();

    lmb162_bsp_init();

    printf("\r\nLCD LMB162ABC STM Test\r\n");
    
    while (1) {
        HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_9);
        lmb162_delay_us(64000);
    }
}

