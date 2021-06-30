#ifndef __LMB162_H__
#define __LMB162_H__


typedef enum {
    LMB162_PIN_LOW,
    LMB162_PIN_HIGH
} LMB162_PIN_STATE;

typedef enum {    
    LMB162_INST_CLEAR,
    LMB162_INST_HOME,
    LMB162_INST_ENTRY_MODE_SET,
    LMB162_INST_DISPLAY_ON_OFF,
    LMB162_INST_SHIFT,
    LMB162_INST_FUNCTION_SET,
    LMB162_INST_CGRAM_ADDR_SET,
    LMB162_INST_DDRAM_ADDR_SET,
    LMB162_INST_READ_BUSY_FLAG,
    LMB162_INST_WRITE_DATA,
    LMB162_INST_READ_DATA,
    LMB162_INST_END,
} LMB162_INSTRUCTIONS;

typedef struct {
    LMB162_INSTRUCTIONS inst;
    uint8_t data_bus;
} LMB162_CMD;

/**
  * @brief LMB162 GPIO Initlisation 
  * 
  * User defined initlisation function for the gpio connected to the LCD. 
  * This function should be implemented in user_gpio.c file.
  * 
  * @param void.
  * @retval None.
  */
void lmb162_gpio_init(void) __attribute__((weak));

/**
  * @brief LMB162 GPIO write LCD Pin X  
  * 
  * User defined function for writing to the mcu gpio conencted to pin X of the LCD.
  * These functions should be implemented in user_gpio.c file.
  * 
  * @param LMB162_PIN_STATE Detemines if the pin should be set high or low
  * @retval None.
  */
void lmb162_write_pin_rs(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_rw(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_e(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db0(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db1(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db2(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db3(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db4(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db5(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db6(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db7(LMB162_PIN_STATE pin_state) __attribute__((weak));

#endif /* __LMB162_H__ */