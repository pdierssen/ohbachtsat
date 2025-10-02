#ifndef OLED_H
#define OLED_H

#include <Arduino.h>

void oled_setup();
void oled_clear();
void oled_set_cursor(int x, int y);
void oled_print(String toprint);
void oled_show();

#endif // OLED_H