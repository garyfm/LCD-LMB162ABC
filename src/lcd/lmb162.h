#ifndef __LMB162_H__
#define __LMB162_H__

#include <stdint.h>

// Display Settings
#define LMB162_DISPLAY_ON (1 << 2)
#define LMB162_DISPLAY_OFF (0 << 2)
#define LMB162_CURSOR_ON (1 << 1)
#define LMB162_CURSOR_OFF (0 << 1)
#define LMB162_BLINKING_ON (1 << 0)
#define LMB162_BLINKING_OFF (0 << 0)

// Function Settings
#define LMB162_8_BIT (1 << 4)
#define LMB162_4_BIT (0 << 4)
#define LMB162_2_LINE (1 << 3)
#define LMB162_1_LINE (0 << 3)
#define LMB162_5x11_DOTS (1 << 2)
#define LMB162_5x8_DOTS (0 << 2)

typedef enum {
    LMB162_PIN_LOW,
    LMB162_PIN_HIGH
} LMB162_PIN_STATE;

#define LMB162_RS_DISPLAY_DATA (LMB162_PIN_HIGH)
#define LMB162_RS_INSTRUCTION_DATA (LMB162_PIN_LOW)

#define LMB162_RW_READ (LMB162_PIN_HIGH)
#define LMB162_RW_WRITE (LMB162_PIN_LOW)

#define LMB162_EN_DATA_ENABLE (LMB162_PIN_HIGH)
#define LMB162_EN_DATA_DISABLE (LMB162_PIN_LOW)

typedef enum {
    LMB162_DB0,
    LMB162_DB1,
    LMB162_DB2,
    LMB162_DB3,
    LMB162_DB4,
    LMB162_DB5,
    LMB162_DB6,
    LMB162_DB7,
} LMB162_DB_POS;

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
void lmb162_bsp_init(void) __attribute__((weak));

/**
  * @brief LMB162 GPIO write LCD Pin X  
  * 
  * User defined function for writing to the mcu gpio conencted to pin X of the LCD.
  * These functions should be implemented in user_gpio.c file.
  * 
  * @param pin_state Detemines if the pin should be set high or low
  * @retval None.
  */
void lmb162_write_pin_rs(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_rw(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_en(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db0(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db1(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db2(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db3(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db4(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db5(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db6(LMB162_PIN_STATE pin_state) __attribute__((weak));
void lmb162_write_pin_db7(LMB162_PIN_STATE pin_state) __attribute__((weak));

/**
  * @brief LMB162 Delay Microseconds
  * 
  * User defined function for delaying some amount of time. 
  * This is used to meet the timing requirments of the LMB162.
  
  * The speficic delay implementation will differ depending on MCU/Board.
  * These functions should be implemented in user_gpio.c file.
  * 
  * @param delay Amount of time to delay for.
  * @retval None.
  */
void lmb162_delay_us(uint16_t delay) __attribute__((weak));

void lmb162_init(void);
void lmb162_command_display(uint8_t setting);
void lmb162_command_function_set(uint8_t setting);

#endif /* __LMB162_H__ */