#define TMP A0

int volt;
float temp;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    volt = analogRead(TMP);
    temp = (5.0 / 1023) * volt * 100 - 50;
    Serial.print("Temperature is : ");
    Serial.print(temp);
    Serial.println(" C");
}
