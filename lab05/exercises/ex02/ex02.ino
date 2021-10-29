#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define RED_BUTTON 2
#define GREEN_BUTTON 4

#define LED_RED 6
#define LED_BLUE 3

#define ENCODER1 A2
#define ENCODER2 A3

#define DEBOUNCE_PERIOD 10UL

String MENU[4] = {"Option 1", "Option 2", "Option 3", "Option 4"};
int MENU_LENGTH;
int menuIndex;

void initEncoder(){
    pinMode(ENCODER1, INPUT_PULLUP);
    pinMode(ENCODER2, INPUT_PULLUP);
}

void initButtons(){
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

void initLed(){
    
}

void initLcd(){
    lcd.init();
    lcd.begin(16, 2);
    lcd.backlight();
}

void initMenu(){
    menuIndex = 0;
    MENU_LENGTH = sizeof(MENU) / sizeof(MENU[0]);
}

void printMenu(String top, String bottom){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(top);
    lcd.setCursor(0, 1);
    lcd.print(bottom);
}

void scrollMenu(int by){
    if(by < 0){
        if(menuIndex + by < 0){
            menuIndex = 0;
        }else {
            menuIndex = menuIndex + by;
        }
    }

    if(by > 0){
        if(menuIndex + by > MENU_LENGTH - 1){
            menuIndex = MENU_LENGTH - 1;
        }else {
            menuIndex = menuIndex + by;
        }
    }
}

bool isGreenButtonPressed()
{
    static int debounced_button_state = HIGH;
    static int previous_reading = HIGH;
    static unsigned long last_change_time = 0UL;
    bool isPressed = false;

    int current_reading = digitalRead(GREEN_BUTTON);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD)
    {
        if (current_reading != debounced_button_state)
        {
            if (debounced_button_state == HIGH && current_reading == LOW)
            {
                isPressed = true;
            }
            debounced_button_state = current_reading;
        }
    }

    previous_reading = current_reading;

    return isPressed;
}

bool isRedButtonPressed()
{
    static int debounced_button_state = HIGH;
    static int previous_reading = HIGH;
    static unsigned long last_change_time = 0UL;
    bool isPressed = false;

    int current_reading = digitalRead(RED_BUTTON);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD)
    {
        if (current_reading != debounced_button_state)
        {
            if (debounced_button_state == HIGH && current_reading == LOW)
            {
                isPressed = true;
            }
            debounced_button_state = current_reading;
        }
    }

    previous_reading = current_reading;

    return isPressed;
}

void setup()
{
   initEncoder();
   initButtons();
   initLcd();
   initLed();
   initMenu();
}

void loop(){
    bool redPressed = isRedButtonPressed();
    bool greenPressed = isGreenButtonPressed();

    if(greenPressed){
        scrollMenu(1);
    }

    if(redPressed){
        scrollMenu(-1);
    }

    if(greenPressed || redPressed){
        if(MENU_LENGTH == 1 || menuIndex == MENU_LENGTH - 1) {
            printMenu(MENU[menuIndex], "");
        }else if(MENU_LENGTH >= 2){
            printMenu(MENU[menuIndex], MENU[menuIndex + 1]);
        }
    }
}
