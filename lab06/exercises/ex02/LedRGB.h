#ifndef LEDRGB_H_
#define LEDRGB_H_

#include "Arduino.h"

class LedRGB
{
public:
    void init(byte red, byte green, byte blue);
    void setColor(string color);

private:
    byte red_;
    byte green_;
    byte blue_;
};

#endif