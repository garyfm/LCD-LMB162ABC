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
 * +------------+------------------+
 * |    LCD     | Nucleo |  STM    |
 * |------------+------------------|
 * |   RS  (4)  |   D0   |   PG9   |
 * |   RW  (5)  |   D1   |   PG14  |
 * |   E   (6)  |   D2   |   PF15  |
 * |   DB0 (7)  |   D3   |   PE13  |
 * |   DB1 (8)  |   D4   |   PF14  |
 * |   DB2 (9)  |   D5   |   PE11  |
 * |   DB3 (10) |   D6   |   PE9   |
 * |   DB4 (11) |   D7   |   PF13  |
 * |   DB5 (12) |   D8   |   PF12  |
 * |   DB6 (13) |   D9   |   PD15  |
 * |   DB7 (14) |   D10  |   PD14  |
 * +------------+--------+---------+
 **/

#include <stdbool.h>

#include "lmb162.h"

/* User GPIO Libaries */
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_tim.h"

#define TIMER_CLK_FREQ (1000000)
#define TIMER_MAX_PERIOD (0xFFFF)

static TIM_HandleTypeDef htim3;

void lmb162_delay_us(uint16_t us) {

    __HAL_TIM_SET_COUNTER(&htim3, 0);
   
    HAL_TIM_Base_Start(&htim3);
    while( __HAL_TIM_GET_COUNTER(&htim3) <= us) {}
    HAL_TIM_Base_Stop(&htim3);
}

void lmb162_bsp_init(void) {
    GPIO_InitTypeDef lcd_gpio_init = {0};

    lcd_gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    lcd_gpio_init.Pull = GPIO_NOPULL;
    lcd_gpio_init.Speed = GPIO_SPEED_FREQ_LOW;

    // PORTD
    __HAL_RCC_GPIOD_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_14 | GPIO_PIN_15;
    HAL_GPIO_Init(GPIOD, &lcd_gpio_init);

    // PORTE
    __HAL_RCC_GPIOE_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13;
    HAL_GPIO_Init(GPIOE, &lcd_gpio_init);

    // PORTF
    __HAL_RCC_GPIOF_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    HAL_GPIO_Init(GPIOF, &lcd_gpio_init);

    // PORTG
    __HAL_RCC_GPIOG_CLK_ENABLE();
    lcd_gpio_init.Pin = GPIO_PIN_9 | GPIO_PIN_14;
    HAL_GPIO_Init(GPIOG, &lcd_gpio_init);

    // Init Timer for delay
    htim3.Instance = TIM3;
    htim3.Init.Prescaler = ((SystemCoreClock / 2) / TIMER_CLK_FREQ) - 1; 
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = TIMER_MAX_PERIOD - 1;
    htim3.Init.ClockDivision = 0;
    htim3.Init.RepetitionCounter = 0;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    __HAL_RCC_TIM3_CLK_ENABLE();
    HAL_TIM_Base_Init(&htim3);
}

void lmb162_write_pin_rs(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
}

void lmb162_write_pin_rw(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
}

void lmb162_write_pin_e(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_15, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_15, GPIO_PIN_SET);
}

void lmb162_write_pin_db0(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
}

void lmb162_write_pin_db1(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_14, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_14, GPIO_PIN_SET);
}

void lmb162_write_pin_db2(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
}

void lmb162_write_pin_db3(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}

void lmb162_write_pin_db4(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_13, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_13, GPIO_PIN_SET);
}

void lmb162_write_pin_db5(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_12, GPIO_PIN_SET);
}

void lmb162_write_pin_db6(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

void lmb162_write_pin_db7(LMB162_PIN_STATE pin_state) {
    if (pin_state == LMB162_PIN_LOW)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    else if (pin_state == LMB162_PIN_HIGH)
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
}