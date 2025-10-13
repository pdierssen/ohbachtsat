#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include<Arduino.h>

void setupBH1750();
void getLux();
void powerDown();
void powerOn();
void dataRegReset();
void setMode();
void setMeasuringTime();
uint16_t readBH1750();
void writeBH1750(byte val);
void bh1750();

#endif // BRIGHTNESS_H