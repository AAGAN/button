#include "button.h"
#include <Stream.h>
#include <Adafruit_ILI9341\Adafruit_ILI9341.h>
#include <Adafruit_FT6206_Library\Adafruit_FT6206.h>
#include <Adafruit-GFX-Library\Adafruit_GFX.h>
#include <Wire\Wire.h>
#include <SPI\SPI.h>

button buttons[64];

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

    for (uint16_t i = 0; i < 64; i++)
    {
        String Text = "b" + char(i+1);
        buttons[i].txt(tft ,Text ,ILI9341_DARKGREEN);
    }

    for (uint8_t i; i<64; i++ )
    {
        Serial.print(buttons[i].txt());
    }

    delay(500); 
}
