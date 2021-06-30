#ifndef __LMB162_H__
#define __LMB162_H__


typedef enum {
    LMB162_PIN_LOW,
    LMB162_PIN_HIGH
} LMB162_PIN_STATE;

/**
  * @brief LMB162 GPIO Initlisation 
  * 
  * User defined initlisation function for the gpio connected to the LCD. 
  * 
  * @param void.
  * @retval None.
  */
void lmb162_gpio_init(void) __attribute__((weak));

/**
  * @brief LMB162 GPIO write LCD Pin X  
  * 
  * User defined function for setting the gpio conencted to pin X of the LCD.
  * This should be defined in user_gpio.c file.
  * 
  * @param LMB162_PIN_STATE Detemines if the pin should be set high or low
  * @retval None.
  */
void lmb162_write_pin_4(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_5(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_6(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_7(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_8(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_9(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_10(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_11(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_12(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_13(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_14(LMB162_PIN_STATE pin_state) __attribute__((weak));

#endif /* __LMB162_H__ */