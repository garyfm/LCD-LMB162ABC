#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>

/**
 * @brief LCD object 
 */
typedef struct {

} LCD;

/**
  * @brief LCD Initialisation
  * @param lcd Object
  * @retval None
  */
void lcd_init(LCD *lcd);

/**
  * @brief LCD Write
  * @param lcd object.
  * @param data Data to be written.
  * @param lenght Length of data.
  * @retval None.
  */
void lcd_write(LCD *lcd, char *data, uint8_t lenght);

#endif /*__LCD_H__ */