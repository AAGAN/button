#include "button.h"

button::button()
{
    states = false;
    x = 240;
    y = 320;
    width = 80;
    height = 20;
    color = 5;
}

button::button(int bx,int by,int bwidth,int bheight, int bcolor, String btext, bool bstate)
{
    x = bx;
    y = by;
    width = bwidth;
    height = bheight;
    color = bcolor;
    states = bstate;
    //add the code for drawing a rectangle and erasing the previous text
    text = btext;
}

button::~button()
{
}

bool button::ispressed(int xx, int yy)
{
    if (x<xx && (x + width)>xx)
    {
        if (y<yy && (y + height)>yy){ return true; }
    }
    return false;
}

void button::txt(Adafruit_ILI9341 &tft, String letters, uint16_t bcolor)
{
    //add the code for erasing the previous text by drawing a black rectangle
    text = letters;
    tft.fillRect(x+1, y+1, width-2, height-2, 0x0000);
    tft.setTextSize(1);
    tft.setTextColor(bcolor);
    tft.setCursor(x + 2, y + 2);
    tft.print(text);
}

bool button::state()
{
    return states;
}

void button::state(bool newState)
{
    states = newState;
}

void button::pressed()
{
    states = !states;
}