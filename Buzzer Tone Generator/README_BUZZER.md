# 🔔 Arduino Buzzer Beep

## ✅ Objective:

Generate a beeping sound using a buzzer connected to an Arduino by toggling it ON and OFF at fixed intervals.

---

## 🧾 Code Explanation:

```cpp
#define BUZ 11
#define DELAY_TIME 1000

void setup()
{
    pinMode(BUZ, OUTPUT);      // Set buzzer pin as OUTPUT
}

void loop()
{
    digitalWrite(BUZ, HIGH);   // Turn ON the buzzer
    delay(DELAY_TIME);         // Wait for 1 second
    digitalWrite(BUZ, LOW);    // Turn OFF the buzzer
    delay(DELAY_TIME);         // Wait for 1 second
}
```

---

## ⚙️ Components Required:

- Arduino board (Uno, Nano, etc.)
- 1x Buzzer (active or passive)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Circuit Connections:

| Arduino Pin | Component     | Description             |
|-------------|---------------|-------------------------|
| D11         | Buzzer +      | Buzzer signal input     |
| GND         | Buzzer -      | Ground                  |

---

## 🕹️ Behavior:

- The buzzer beeps ON for 1 second.
- Then turns OFF for 1 second.
- This cycle repeats continuously.

---

## 📦 Usage:

1. Connect the buzzer to pin 11 and GND.
2. Upload the code to your Arduino board.
3. Listen for periodic beeping.

---

## 📘 Concepts Used:

- `pinMode()` to set pin direction
- `digitalWrite()` to control output state
- `delay()` for timing the beeps
