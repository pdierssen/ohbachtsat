#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int i;

void oled_setup() {
    Serial.begin(9600);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C is the common I2C address
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Infinite loop if display init fails
    }

    display.clearDisplay();
    display.setTextSize(1);       // 1 = small, 2 = medium, etc.
    display.setTextColor(SSD1306_WHITE);
}

void oled_clear() {
    display.clearDisplay();  
}

void oled_set_cursor(int x, int y) {
    display.setCursor(x, y);
}

void oled_print(String toprint) {
    display.print(toprint);
}

void oled_show() {
    display.display();
}