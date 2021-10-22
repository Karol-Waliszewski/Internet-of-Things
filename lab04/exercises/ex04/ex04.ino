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
    String value = String(analogRead(POTENTIOMETER));
    Serial.println(value);
}