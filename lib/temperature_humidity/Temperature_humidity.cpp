#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <OLED.h>
#define DHT11_PIN 4 //Depends on Pin in Nano!!

DHT dht11(DHT11_PIN, DHT11);

float humidity;
float temperatureCelsius;
float temperatureFahrenheit;

unsigned long startTimeDht11;
const int durationDht11 = 5000;
const unsigned long refreshFrequencyDht11 = 1000; // 1/1000ms = 1Hz

void dht11Setup() {
  dht11.begin(); // initialize the sensor
}

void storeMeasurementsDht11() {
  // read humidity
  humidity  = dht11.readHumidity();
  // read temperature as Celsius
  temperatureCelsius = dht11.readTemperature();
  // read temperature as Fahrenheit
  temperatureFahrenheit = dht11.readTemperature(true);
}

void visualizeMeasurementsDht11() {
  OLED::instance().getDisplay().clearDisplay();
  OLED::instance().getDisplay().setCursor(0, 0);
  // check if any reads failed
  if (isnan(humidity) || isnan(temperatureCelsius) || isnan(temperatureFahrenheit)) {
    OLED::instance().getDisplay().println("Failed to read from DHT11 sensor!");
  } else {
    OLED::instance().getDisplay().println("DHT11");
    OLED::instance().getDisplay().print("Humidity: ");
    OLED::instance().getDisplay().print(humidity);
    OLED::instance().getDisplay().println("%");

    OLED::instance().getDisplay().print("Temperature: ");
    OLED::instance().getDisplay().print(temperatureCelsius);
    OLED::instance().getDisplay().println("C");
    OLED::instance().getDisplay().print("Temperature: ");
    OLED::instance().getDisplay().print(temperatureFahrenheit);
    OLED::instance().getDisplay().println("F");
  }
  OLED::instance().getDisplay().display();
}

void temperature_humidity () {
    startTimeDht11 = millis();
    unsigned long currentTime = millis(); //init
    while (currentTime - startTimeDht11 < durationDht11)
    {
        currentTime = millis();
        storeMeasurementsDht11();
        visualizeMeasurementsDht11();
        delay(refreshFrequencyDht11);
    }
  }