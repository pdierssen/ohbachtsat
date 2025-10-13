# Librarys
Adafruit GFX Library by Adafruit
Adafruit SSD1306
Adafruit BusIO by Adafruit

# Bug fixing:
Wenn der Upload fehlschlägt:
- Serial Monitor Terminals / Serial Plotter schließen
- evtl. andere Programme die den USB Port blockieren schließen
- USB Port wechseln
- Wenn "uploading" im Terminal erscheint -> den RESET Button am Board drücken, sodass der Upload passieren kann.

Falls der falsche Port erscheint:
- Geräte Manager öffnen
- Gerät ein und aus stecken und schauen unter: Anschlüsse (COM& [...]) welcher Anschluss erscheint bzw. verschwindet.
- im Terminal mode eingeben und schauen welcher Port besetzt ist.
- der .ini datei anpassen: upload_port=COM3 
    - für linux upload_port = /dev/ttyUSB*

DHT11 Temperatur und Feuchtigkeit:
https://arduinogetstarted.com/tutorials/arduino-dht11

OLED:
https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives

I2C arduino:
https://docs.arduino.cc/learn/communication/wire/

Lichtsensor:
https://github.com/claws/BH1750
