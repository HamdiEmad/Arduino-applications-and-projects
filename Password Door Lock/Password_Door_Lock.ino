#define srvoPin 6
#define LED 5

#include <Servo.h>
#include <Keypad.h>

Servo myservo;

String password = "";
const String correctPassword = "123456";

int pos = 0;
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};
byte rowPins[ROWS] = {10, 9, 8, 7};
byte colPins[COLS] = {11, 12, 13};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    pinMode(LED, OUTPUT);
    myservo.attach(srvoPin);
    Serial.begin(9600);
    Serial.print("Enter the password : ");
}

void loop()
{
    char key = keypad.getKey();
    if (key == '#')
    {
        Serial.println();
        if (password == correctPassword)
        {
            Serial.println("Password is valid");
            digitalWrite(LED, HIGH);
            open_door();
            delay(2000);
            close_door();
        }
        else
            Serial.println("Password is invalid");
        Serial.println();
        Serial.print("Enter the password : ");
        password = "";
        digitalWrite(LED, LOW);
    }
    if (key && key != '#' && password.length() < 6)
    {
        Serial.print(key);
        password += key;
    }
}

void open_door()
{
    for (pos = 0; pos <= 90; pos += 1)
    {
        myservo.write(pos);
        delay(15);
    }
}

void close_door()
{
    for (pos = 90; pos >= 0; pos -= 1)
    {
        myservo.write(pos);
        delay(15);
    }
}