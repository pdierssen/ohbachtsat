#include <Arduino.h>

#include "Blink.h"
#include "OLED.h"

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  blink_setup();
  oled_setup();
}

void loop() {
  //Startup: Logo pof some sort, Constants: duration
  //Gyrometer x, y, z Constants: resfresh rate, duration
  //Accelreometer x, y, z Constants: resfresh rate, duration
  //Lightsensor value Constants: resfresh rate, duration
  //Humidity sensor value Constants: resfresh rate, duration
  //Temperature x, y, z Constants: resfresh rate, duration

  blink_loop();
  oled_clear();
  oled_print("Hallo");
  // cursor is not reset
  oled_show();
  delay(1000);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}