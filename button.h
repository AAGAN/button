// button.h
#include <Stream.h>
#include <Adafruit_ILI9341\Adafruit_ILI9341.h>
#include <Adafruit_FT6206_Library\Adafruit_FT6206.h>
#include <Adafruit-GFX-Library\Adafruit_GFX.h>
#include <Wire\Wire.h>
#include <SPI\SPI.h>


#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class button
{
 protected:
     bool states;
     int x;
     int y;
     int width;
     int height;
     int color;
     String text;

 public:
	button();
    button(int,int,int,int,int,String,bool);
    void pressed();
    bool state();
    void state(bool);
    void txt(String);
    bool ispressed(int, int);

};

//extern ButtonClass Button;

#endif

