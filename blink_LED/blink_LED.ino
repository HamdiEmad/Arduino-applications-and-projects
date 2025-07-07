#define LED 11
#define DELAY_TIME 1000

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    digitalWrite(LED, HIGH);
    delay(DELAY_TIME);
    digitalWrite(LED, LOW);
    delay(DELAY_TIME);
}