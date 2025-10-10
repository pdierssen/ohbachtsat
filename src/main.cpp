#include <Arduino.h>

#include "Blink.h"
#include "OLED.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Gyro.h"

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  blink_setup();
  gyro_setup();
  OLED::instance();
}

void loop() {
  blink_loop();
  
  OLED::instance().getDisplay().println("Hallo");
  OLED::instance().getDisplay().display();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}