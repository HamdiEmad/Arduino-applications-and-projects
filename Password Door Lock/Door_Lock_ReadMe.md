# 🔐 Arduino Keypad Password Door Lock

## ✅ Objective:

Create a secure door lock system using a 4x3 keypad, servo motor, and Arduino. The user must enter the correct password to open the door. If the password is incorrect, the door remains locked.

---

## 🧾 Code Explanation:

```cpp
#define srvoPin 6                          // Servo motor control pin
#define LED 5                              // LED indicator pin

#include <Servo.h>
#include <Keypad.h>

Servo myservo;
String password = "";
const String correctPassword = "123456";   // Predefined correct password
int pos = 0;                               // Servo position
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

byte rowPins[ROWS] = {10, 9, 8, 7};        // Connect to the row pinouts of the keypad
byte colPins[COLS] = {11, 12, 13};         // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    pinMode(LED, OUTPUT);
    myservo.attach(srvoPin);
    Serial.begin(9600);
    Serial.print("Enter the password : ");
}

void loop() {
    char key = keypad.getKey();
    if (key == '#') {                      // '#' triggers password verification
        Serial.println();
        if (password == correctPassword) {
            Serial.println("Password is valid");
            digitalWrite(LED, HIGH);       // Turn on LED if correct
            open_door();                   // Open the door
            delay(2000);                   // Wait 2 seconds
            close_door();                  // Then close it
        } else {
            Serial.println("Password is invalid");
        }
        Serial.println();
        Serial.print("Enter the password : ");
        password = "";                     // Reset password input
        digitalWrite(LED, LOW);            // Turn off LED
    }
    if (key && key != '#' && password.length() < 6) {
        Serial.print(key);
        password += key;                   // Append key to password string
    }
}

void open_door() {
    for (pos = 0; pos <= 90; pos += 1) {
        myservo.write(pos);                // Gradually rotate servo to open
        delay(15);
    }
}

void close_door() {
    for (pos = 90; pos >= 0; pos -= 1) {
        myservo.write(pos);                // Gradually rotate servo to close
        delay(15);
    }
}
```

---

## ⚙️ Components Required:

- Arduino board (Uno, Nano, etc.)
- 1x 4x3 Keypad
- 1x Servo Motor (e.g., SG90)
- 1x LE
- 1x Resistor (150Ω)
- Jumper wires
- Breadboard

---

## 🔌 Circuit Connections:

| Component      | Arduino Pin | Description               |
| -------------- | ----------- | ------------------------- |
| Servo Motor    | D6          | Control signal pin        |
| LED            | D5          | Visual feedback indicator |
| Keypad Rows    | D10-D7      | Row pins                  |
| Keypad Columns | D11-D13     | Column pins               |
| Servo VCC      | 5V          | Power supply              |
| Servo GND      | GND         | Ground                    |

---

## 🕹️ Behavior:

- User inputs a password via the keypad.
- When '#' is pressed:
  - If the password is correct, the LED lights up and the servo rotates to open the door.
  - After 2 seconds, the servo closes the door.
  - If the password is incorrect, a message is displayed and the LED remains off.

---

## 📦 Usage:

1. Connect the keypad, servo, and LED as shown in the connections table.
2. Upload the code to the Arduino.
3. Open the Serial Monitor at 9600 baud.
4. Enter the password (`123456`) followed by `#` to unlock.

---

## 📘 Concepts Used:

- Keypad interfacing using `Keypad.h` library
- Servo control using `Servo.h` library
- String handling and condition checking in Arduino
- Serial communication for user feedback
