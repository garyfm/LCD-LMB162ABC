#include "lmb162.h"
#include "lcd.h"

void lcd_init(LCD *lcd) {
    lmb162_gpio_init();

    lmb162_write_pin_4(LMB162_PIN_LOW);
    lmb162_write_pin_4(LMB162_PIN_HIGH);
    lmb162_write_pin_4(LMB162_PIN_LOW);
}

void lcd_write(LCD *lcd, char *data, uint8_t lenght) {

}