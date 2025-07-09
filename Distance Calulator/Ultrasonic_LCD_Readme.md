# 📏 Arduino Ultrasonic Distance Sensor with LCD

## ✅ Objective:

Measure the distance to an object using an **HC-SR04 ultrasonic sensor** and display the result on a **16x2 LCD screen**.

---

## 🧾 Code Explanation:

```cpp
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

    distance = pulseIn(echoPin, HIGH); // Get echo time
    distance /= 58;                    // Convert time to cm

    lcd.setCursor(0, 1);
    lcd.print(distance);              // Show distance
    lcd.setCursor(7, 1);
    lcd.print("cm");
}
```

---

## ⚙️ Components Required:

- Arduino board (Uno, Nano, etc.)
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display (with 6 digital pins)
- Jumper wires
- Breadboard

---

## 🔌 Circuit Connections:

| Arduino Pin | Component        | Description                       |
|-------------|------------------|-----------------------------------|
| D10         | Trig Pin         | Sends ultrasonic pulse            |
| D9          | Echo Pin         | Receives reflected pulse          |
| D7          | LCD RS           | LCD control pin                   |
| D6          | LCD Enable       | LCD control pin                   |
| D5–D2       | LCD D4–D7        | LCD data lines                    |
| GND         | Sensor & LCD     | Common ground                     |
| 5V          | Sensor & LCD     | Power supply                      |

---

## 📐 Behavior:

- The LCD displays a static label: **"The distance is"** on the first row.
- The second row updates in real-time to show the measured distance in **centimeters**.
- The HC-SR04 sends out a sound wave and calculates distance based on the time it takes for the echo to return.

---

## 📦 Usage:

1. Connect all components according to the table above.
2. Upload the code to your Arduino board.
3. Watch the LCD display the distance to the nearest object.

---

## 📘 Concepts Used:

- Ultrasonic distance measurement with `pulseIn()`
- Conversion of echo time to centimeters
- LCD interfacing using the `LiquidCrystal` library
- Real-time display updates with `setCursor()` and `print()`
