#define BUZ 11
#define DELAY_TIME 1000
void setup()
{
    pinMode(BUZ, OUTPUT);
}

void loop()
{
    digitalWrite(BUZ, HIGH);
    delay(DELAY_TIME);
    digitalWrite(BUZ, LOW);
    delay(DELAY_TIME);
}
