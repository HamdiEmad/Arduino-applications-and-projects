#define echoPin 9
#define trigPin 10
#include <LiquidCrystal.h>

float distance = 0;

const byte rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    lcd.begin(16, 2);
    lcd.print("The distance is");
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    distance = pulseIn(echoPin, HIGH);
    distance /= 58;
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(6, 1);
    lcd.print("cm");
}
