#include<LiquidCrystal.h>
#define POTENTIOMETER A0
LiquidCrystal lcd(12, 11, 7, 10, 9, 8);

// #include <LiquidCrystal_I2C.h>
// LiquidCrystal_I2C lcd(0x27, 16, 2);
int MAX_VALUE = 1023;
int prevValue;

void setup()
{
	prevValue = -1;
    lcd.begin(16, 2);
}

void loop()
{
    int value = analogRead(POTENTIOMETER);
 	if(value != prevValue){
  	  lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(value);
      lcd.setCursor(0, 1);
      lcd.print((float)(5.0 * value/MAX_VALUE), 2);
      lcd.setCursor(4, 1);
      lcd.print('V');
    }
  	prevValue = value;
}