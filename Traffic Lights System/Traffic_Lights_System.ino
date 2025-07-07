#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11
#define RED_TIME 15000
#define YELLOW_TIME 5000
#define GREEN_TIME 10000

byte leds[3] = {RED_LED, YELLOW_LED, GREEN_LED};
int timing[3] = {RED_TIME, YELLOW_TIME, GREEN_TIME};

void setup()
{
    for (byte i = 11; i < 14; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    for (byte i = 0; i < 3; i++)
    {
        digitalWrite(leds[i], HIGH);
        delay(timing[i]);
        digitalWrite(leds[i], LOW);
    }
}
