#include <Wire.h>
#include <Arduino.h>

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

void visualizeMeasurements(char* heading, int16_t x, int16_t y, int16_t z) {

}

void gyro_setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  
  Wire.write(0);    
  Wire.endTransmission(true);
}

void gyro_accellerometer(){
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

