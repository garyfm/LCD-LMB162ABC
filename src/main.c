#include <stdio.h>

#include "retarget.h"
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
    RetargetInit(&huart3);


    //LCD lcd;

    //lcd_init(&lcd);

    while (1)
    {
        printf("Hello, World!\r\n");


        GPIO_InitTypeDef lcd_gpio_init = {0};

        lcd_gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
        lcd_gpio_init.Pull = GPIO_NOPULL;
        lcd_gpio_init.Speed = GPIO_SPEED_FREQ_LOW;

        // PORTD
        __HAL_RCC_GPIOD_CLK_ENABLE();
        lcd_gpio_init.Pin = GPIO_PIN_14 | GPIO_PIN_15;
        HAL_GPIO_Init(GPIOD, &lcd_gpio_init);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);

        // PORTE
        __HAL_RCC_GPIOE_CLK_ENABLE();
        lcd_gpio_init.Pin = GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13;
        HAL_GPIO_Init(GPIOE, &lcd_gpio_init);
        
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13, GPIO_PIN_SET);

        // PORTF
        __HAL_RCC_GPIOF_CLK_ENABLE();
        lcd_gpio_init.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        HAL_GPIO_Init(GPIOF, &lcd_gpio_init);

        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);

        // PORTG
        __HAL_RCC_GPIOG_CLK_ENABLE();
        lcd_gpio_init.Pin = GPIO_PIN_9 | GPIO_PIN_14;
        HAL_GPIO_Init(GPIOG, &lcd_gpio_init);
        
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9 | GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9 | GPIO_PIN_14, GPIO_PIN_SET);
 
    }
}

