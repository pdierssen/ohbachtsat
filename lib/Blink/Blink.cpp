#include <Arduino.h>

void blink_setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void blink_loop() {
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
    delay(1000);                     // Wait for 1 second
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
    delay(1000);   
}