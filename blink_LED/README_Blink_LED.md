
# 🔆 Arduino Blink LED Application

## ✅ Objective:
To make an LED blink ON and OFF repeatedly using Arduino.

---

## 🧠 Key Concepts:
- Digital output control using Arduino.
- Understanding `delay()` function and `digitalWrite()` function.
- Basics of LED and resistor usage to protect the circuit.

---

## 🧾 Code (Basic Blink Example):
```cpp
void setup() {
  pinMode(13, OUTPUT); // Set digital pin 13 as output
}

void loop() {
  digitalWrite(13, HIGH); // Turn LED ON
  delay(1000);            // Wait for 1 second
  digitalWrite(13, LOW);  // Turn LED OFF
  delay(1000);            // Wait for 1 second
}
```
> 📝 This example uses the **built-in LED** on pin 13 of most Arduino boards.

---

## 🔌 Circuit Connection (External LED):
To use an external LED (instead of built-in):

### Components Needed:
- 1x LED (any color)
- 1x Resistor (220Ω – 330Ω)
- Breadboard and jumper wires

### Wiring:
| Component | Connection |
|----------|------------|
| LED Anode (long leg) | Digital pin (e.g., pin 8) via resistor |
| Resistor | Between pin 8 and LED Anode |
| LED Cathode (short leg) | GND on Arduino |

**Diagram (Text):**
```
Pin 8 ----->|----/\/\/\---- GND
           LED     220Ω
```

> 🔁 You can modify the code to use pin 8:
```cpp
const int ledPin = 8;
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

---

## 📏 Resistor Value (Why 220Ω to 330Ω?)
- LEDs typically operate at ~2V forward voltage and 10–20mA current.
- Using Ohm's law:
  ```
  R = (5V - 2V) / 0.02A = 150Ω
  ```
- Choose a **220Ω** or **330Ω** resistor to safely limit the current and protect the LED.

---

## ✅ Summary:
- Use `digitalWrite()` to control output voltage to an LED.
- Always use a **current-limiting resistor**.
- You can blink both the **built-in LED (pin 13)** or **external LED (e.g., pin 8)**.
