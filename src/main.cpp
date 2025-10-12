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
  //Startup: Logo pof some sort, Constants: duration
  //Gyrometer x, y, z Constants: resfresh rate, duration
  //Accelreometer x, y, z Constants: resfresh rate, duration
  //Lightsensor value Constants: resfresh rate, duration
  //Humidity sensor value Constants: resfresh rate, duration
  //Temperature x, y, z Constants: resfresh rate, duration

  blink_loop();
  
  OLED::instance().getDisplay().println("Hallo");
  OLED::instance().getDisplay().display();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}