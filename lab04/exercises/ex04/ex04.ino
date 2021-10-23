#define POTENTIOMETER A0

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    { /* just wait */
    }
}

void loop()
{
    int value = analogRead(POTENTIOMETER);
    Serial.println(value);
}