#include "button.h"
#include <Stream.h>
#include <Adafruit_ILI9341\Adafruit_ILI9341.h>
#include <Adafruit_FT6206_Library\Adafruit_FT6206.h>
#include <Adafruit-GFX-Library\Adafruit_GFX.h>
#include <Wire\Wire.h>
#include <SPI\SPI.h>

button buttons[10];

void setup()
{
    pinMode(13, OUTPUT);

    digitalWrite(13, LOW);

    Serial.begin(9600);
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
    delay(500);
}
