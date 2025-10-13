#include <Wire.h>
#include <Arduino.h>
#include <OLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Gyro.h"

const int MPU=0x68; 

int16_t AcX,AcY,AcZ,GyX,GyY,GyZ;

unsigned long startTime;
const int duration = 5000;
const unsigned long refreshFrequency = 500; // 1/500ms = 2Hz

int readMeasurement(){
  int result = Wire.read() << 8;
  result |= Wire.read();
  return result;
}

void storeMeasurements(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=readMeasurement();    
  AcY=readMeasurement();
  AcZ=readMeasurement();
  GyX=readMeasurement();  
  GyY=readMeasurement();
  GyZ=readMeasurement();
  Wire.endTransmission(true);
}

void visualizeMeasurements(String heading, int16_t x, int16_t y, int16_t z) {
  OLED::instance().getDisplay().clearDisplay();
  OLED::instance().getDisplay().setCursor(0, 0);
  OLED::instance().getDisplay().println(heading);
  OLED::instance().getDisplay().print("x: ");
  OLED::instance().getDisplay().println(x);
  OLED::instance().getDisplay().print("y: ");
  OLED::instance().getDisplay().println(y);
  OLED::instance().getDisplay().print("z: ");
  OLED::instance().getDisplay().println(z);
  OLED::instance().getDisplay().display();
}

void gyro_setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  
  Wire.write(0);    
  Wire.endTransmission(true);
}

void gyro_accelerometer(){
    startTime = millis();
    unsigned long currentTime = millis(); //init
    while (currentTime - startTime < duration)
    {
        currentTime = millis();
        storeMeasurements();
        visualizeMeasurements("Accelerometer", AcX, AcY, AcZ);
        delay(refreshFrequency);
    }
}

void gyro_gyrometer(){
    startTime = millis();
    unsigned long currentTime = millis(); // init
    while (currentTime - startTime < duration)
    {
        currentTime = millis();
        storeMeasurements();
        visualizeMeasurements("Gyroscope", GyX, GyY, GyZ);
        delay(refreshFrequency);
    }
    
}

