#define LED 11
#define BUTTON 10

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
    if (!digitalRead(BUTTON))
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }
}