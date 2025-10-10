#ifndef GYRO_H
#define GYRO_H

#include<Arduino.h>

int readMeasurement();
void storeMeasurements();
void visualizeMeasurements(String heading, int16_t x, int16_t y, int16_t z);
void gyro_setup();
void gyro_accellerometer();
void gyro_gyrometer();


#endif // GYRO_H