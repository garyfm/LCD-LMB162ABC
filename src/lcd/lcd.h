#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>

typedef struct {

} LCD;

void lcd_init(LCD *lcd);
void lcd_write(LCD *lcd, char *data, uint8_t lenght);

#endif /*__LCD_H__ */