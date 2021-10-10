#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int CURRENT_COLOR;

void initRGB()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, LOW);

    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);
}

void initButtons()
{
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

void turnLedOff()
{
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
}

void turnLedOn()
{
    if(CURRENT_COLOR == LED_GREEN){
         digitalWrite(LED_GREEN, HIGH);
    }
  
    if(CURRENT_COLOR == LED_RED){
         digitalWrite(LED_RED, HIGH);
    }

    if(CURRENT_COLOR == LED_BLUE){
         digitalWrite(LED_BLUE, HIGH);
    }
}

void changeLedColor()
{
    if(CURRENT_COLOR == LED_GREEN){
        CURRENT_COLOR = LED_RED;
    }
  
    if(CURRENT_COLOR == LED_RED){
        CURRENT_COLOR = LED_BLUE;
    }

    if(CURRENT_COLOR == LED_BLUE){
        CURRENT_COLOR = LED_GREEN;
    }
}

void setup()
{
    initRGB();
    initButtons();

    CURRENT_COLOR = LED_BLUE;
}

void loop()
{
    if (digitalRead(GREEN_BUTTON) == LOW)
        changeLedColor();

    if (digitalRead(RED_BUTTON) == LOW)
        turnLedOff();
    else 
        turnLedOn();

    delay(100);

}
