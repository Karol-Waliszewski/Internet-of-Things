#include "LedRGB.h"

void LedRGB::init(byte red, byte green, byte blue){
    red_ = red;
    pinMode(red, OUTPUT);
    digitalWrite(red, LOW);

    green_ = green;
    pinMode(green, OUTPUT);
    digitalWrite(green, LOW);

    blue_ = blue;
    pinMode(blue, OUTPUT);
    digitalWrite(blue, LOW);
}

void LedRGB::setColor(string color){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);

    if (color == "RED"){
        digitalWrite(red, HIGH);
    }else if (color == "GREEN"){
        digitalWrite(green, HIGH);
    }else if (color == "BLUE"){
        digitalWrite(blue, HIGH);
    }else if (color == "YELLOW"){
        digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
    }else if (color == "CYAN"){
         digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
    }else if (color == "MAGENTA"){
        digitalWrite(red, HIGH);
        digitalWrite(blue, HIGH);
    }else if (color == "WHITE"){
        digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
    }
}
