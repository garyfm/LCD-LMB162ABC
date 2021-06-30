/**
 * This file provieds the implementation for initialising, setting and re-setting 
 * the GPIO connected to the LCD screen. 
 * 
 * The user is expected to change the function definitions below to control the 
 * GPIO of there specific board.
 * 
 * The declaration for these functions can be found in lcd/lmb162.h.
 * 
 * The below example is for a STM Nucleo-144 F722ZE with the following PIN connections:
 *
 * +-------+--------+---------+
 * |  LCD  | Nucleo |  STM    |
 * |-------+--------+---------|
 * |   4   |   D0   |   PG9   |
 * |   5   |   D1   |   PG14  |
 * |   6   |   D2   |   PF15  |
 * |   7   |   D3   |   PE13  |
 * |   8   |   D4   |   PF14  |
 * |   9   |   D5   |   PE11  |
 * |   10  |   D6   |   PE9   |
 * |   11  |   D7   |   PF13  |
 * |   12  |   D8   |   PF12  |
 * |   13  |   D9   |   PD15  |
 * |   14  |   D10  |   PD14  |
 * +-------+--------+---------+ 
 **/

#include "lmb162.h"

/* User GPIO Libaries */
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_gpio.h"

void lmb162_gpio_init(void) {
    GPIO_InitTypeDef lcd_gpio_init = {0};

    lcd_gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    lcd_gpio_init.Pull = GPIO_NOPULL;
    lcd_gpio_init.Speed = GPIO_SPEED_FREQ_LOW;

    // PORTD
    __HAL_RCC_GPIOD_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_14 | GPIO_PIN_15;
    HAL_GPIO_Init(GPIOD, &lcd_gpio_init);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);

    // PORTE
    __HAL_RCC_GPIOE_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13;
    HAL_GPIO_Init(GPIOE, &lcd_gpio_init);
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13, GPIO_PIN_RESET);

    // PORTF
    __HAL_RCC_GPIOF_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    HAL_GPIO_Init(GPIOF, &lcd_gpio_init);

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);

    // PORTG
    __HAL_RCC_GPIOG_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_9 | GPIO_PIN_14;
    HAL_GPIO_Init(GPIOG, &lcd_gpio_init);
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9 | GPIO_PIN_14, GPIO_PIN_RESET);
}

void lmb162_write_pin_4(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
}

void lmb162_write_pin_5(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
}

void lmb162_write_pin_6(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_15, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_15, GPIO_PIN_SET);
}

void lmb162_write_pin_7(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
}

void lmb162_write_pin_8(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_14, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_14, GPIO_PIN_SET);
}

void lmb162_write_pin_9(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
}

void lmb162_write_pin_10(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}

void lmb162_write_pin_11(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_13, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_13, GPIO_PIN_SET);
}

void lmb162_write_pin_12(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12, GPIO_PIN_SET);
}

void lmb162_write_pin_13(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}