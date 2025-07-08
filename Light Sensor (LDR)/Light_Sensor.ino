#define LDR A0
#define LED 11

int lightLevel;
int pwmValue;

void setup()
{
    pinMode(LDR, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    lightLevel = analogRead(LDR);
    pwmValue = map(lightLevel, 0, 1023, 0, 255);
    analogWrite(LED, pwmValue);
}
