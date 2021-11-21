#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

LiquidCrystal_I2C lcd(0x27, 16, 2);

OneWire oneWire(A1);
DallasTemperature tempSensors(&oneWire);

float minTemperature = 32767;
float maxTemperature = -32768;

void initLed(){
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    turnOffLed();
}

void turnOffLed(){
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
}

void initLCD(){
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void printLCD(float tempIn, float tempOut){
    char buffer[40];

    sprintf(buffer, "Temp IN%8s", String(tempIn, 4).c_str());
    lcd.setCursor(0, 0);
    lcd.print(buffer);

    sprintf(buffer, "Temp OUT%8s", String(tempOut, 4).c_str());
    lcd.setCursor(0, 1);
    lcd.print(buffer);
}

void ledBasedOnTemperature(float minimal, float maximal, float current){
    if(current <= minimal * 1.25){
        pinMode(LED_BLUE, OUTPUT);
    }else if(current >= maximal * 0.75){
        pinMode(LED_RED, OUTPUT);
    }else {
        pinMode(LED_GREEN, OUTPUT);
    }
}

void setup(){
    tempSensors.begin();  
    initLCD();
    initLed();
}

void loop(){
    tempSensors.requestTemperatures();
    float tempIn = tempSensors.getTempCByIndex(1);
    float tempOut = tempSensors.getTempCByIndex(0);

    printLCD(tempIn, tempOut);

    ledBasedOnTemperature(minTemperature, maxTemperature, tempOut);

    minTemperature = min(minTemperature, tempOut);
    maxTemperature = max(maxTemperature, tempOut);
}