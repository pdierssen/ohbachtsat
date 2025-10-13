#ifndef OLED_H
#define OLED_H

class Adafruit_SSD1306;

class OLED
{
private:
    OLED();
    Adafruit_SSD1306* display;
public:
    static OLED& instance();

    Adafruit_SSD1306& getDisplay();

};

#endif // OLED_H