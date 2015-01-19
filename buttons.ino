#include "button.h"
#include <Stream.h>
#include <Adafruit_ILI9341\Adafruit_ILI9341.h>
#include <Adafruit_FT6206_Library\Adafruit_FT6206.h>
#include <Adafruit-GFX-Library\Adafruit_GFX.h>
#include <Wire\Wire.h>
#include <SPI\SPI.h>

button buttons[10];

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup()
{
    pinMode(13, OUTPUT);

    digitalWrite(13, LOW);

    Serial.begin(9600);
    tft.begin();
}

void loop()
{
  /* add main program code here */

    buttons[0].pressed();
    if (buttons[0].state())
    { 
        digitalWrite(13, HIGH); 
    }
    else
    {
        digitalWrite(13, LOW);
    }
    Serial.println(buttons[0].state());

    buttons[0].txt( tft , "newText");

    delay(500);
}
