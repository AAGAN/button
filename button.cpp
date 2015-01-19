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

bool button::ispressed(int xx, int yy)
{
    if (x<xx && (x + width)>xx)
    {
        if (y<yy && (y + height)>yy){ return true; }
    }
    return false;
}

void button::txt(String letters)
{
    //add the code for erasing the previous text by drawing a black rectangle
    text = letters;
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