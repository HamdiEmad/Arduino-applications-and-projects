#define LDR A0
#define LED 11

void setup()
{
    pinMode(LDR, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int lightLevel = analogRead(LDR);
    int pwmValue = map(lightLevel, 0, 1023, 0, 255);
    analogWrite(LED, pwmValue);
}
