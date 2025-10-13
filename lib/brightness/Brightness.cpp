#include <Wire.h>
#include <Arduino.h>
#include <OLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Brightness.h"

#define BH_1750 0x23
#define DATA_REG_RESET 0b00000111
#define POWER_DOWN 0b00000000
#define POWER_ON 0b00000001

unsigned long startTimeBh1750;
const int durationBh1750 = 5000;
const unsigned long refreshFrequencyBh1750 = 500; // 1/500ms = 2Hz

enum BH1750Mode {
  CHM = 0b00010000,     //CHM: Continuously H-Resolution Mode
  CHM_2 = 0b00010001,   //CHM_2: Continuously H-Resolution Mode2
  CLM = 0b00010011,     //CLM: Continuously L-Resolution Mode
  OTH = 0b00100000,     //OTH: One Time H-Resolution Mode
  OTH_2 = 0b00100001,   //OTH_2: One Time H-Resolution Mode2
  OTL = 0b00100011      //OTL: One Time L-Resolution Mode
} mode;

float measuringTimeFactor;

void setupBH1750(){
  Wire.begin();
  mode = CHM;
  measuringTimeFactor = 1;
  setMode();
  setMeasuringTime(); 
  delay(200);
}

void bh1750 () {
    startTimeBh1750 = millis();
    unsigned long currentTime = millis(); //init
    while (currentTime - startTimeBh1750 < durationBh1750)
    {
        currentTime = millis();
        getLux();
        delay(refreshFrequencyBh1750);
    }
  }

void getLux(){
  uint16_t rawLux;
  float lux;
  rawLux = readBH1750();
  if((mode==CHM_2)||(mode==OTH_2)){
    lux = (rawLux/2.4)/measuringTimeFactor;     
  }
  else{
    lux = (rawLux/1.2)/measuringTimeFactor;
  }
  OLED::instance().getDisplay().clearDisplay();
  OLED::instance().getDisplay().setCursor(0, 0);
  OLED::instance().getDisplay().print(F("Light level: "));
  OLED::instance().getDisplay().print(lux);
  OLED::instance().getDisplay().println(F(" Lux"));
  OLED::instance().getDisplay().display();
}
void powerDown(){
  writeBH1750(POWER_DOWN);
}
void powerOn(){
  writeBH1750(POWER_ON);
  setMode();
}
void dataRegReset(){
  writeBH1750(DATA_REG_RESET);
}
void setMode(){
  writeBH1750(mode);
}
void setMeasuringTime(){
  byte mt = round(measuringTimeFactor*69);
  byte highByteMT = ((mt>>5) | 0b01000000);
  byte lowByteMT = (mt & 0b01111111);
  lowByteMT |= 0b01100000;
  writeBH1750(highByteMT);
  writeBH1750(lowByteMT);
}
uint16_t readBH1750(){
  uint8_t MSbyte, LSbyte;
  Wire.requestFrom(BH_1750, 2);
  if(Wire.available()){
    MSbyte=Wire.read();
    LSbyte=Wire.read(); 
  }
  return ((MSbyte<<8) + LSbyte);
}
void writeBH1750(byte val){
  Wire.beginTransmission(BH_1750);
  Wire.write(val);
  Wire.endTransmission();
}