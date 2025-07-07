
# 💡 Arduino Blink LED (with Macros)

## ✅ Objective:
Make an LED blink ON and OFF repeatedly using predefined macros for LED pin and delay time.

---

## 🧾 Code Explanation:
```cpp
#define LED 11
#define DELAY_TIME 1000

void setup()
{
    pinMode(LED, OUTPUT); // Set pin 11 as output
}

void loop()
{
    digitalWrite(LED, HIGH);  // Turn LED ON
    delay(DELAY_TIME);        // Wait for 1 second
    digitalWrite(LED, LOW);   // Turn LED OFF
    delay(DELAY_TIME);        // Wait for 1 second
}
```

---

## 🔌 Circuit Connections:

### Components Needed:
- 1x LED
- 1x Resistor (220Ω – 330Ω)
- Jumper wires and breadboard

### Wiring:
| Component | Arduino Pin | Notes |
|----------|-------------|-------|
| LED Anode (long leg) | Pin 11 via resistor | Connect through a 220Ω resistor |
| LED Cathode (short leg) | GND | Connect to Arduino GND |

> 🔁 LED blinks ON for 1 second and OFF for 1 second in a continuous loop.

---

## 🧠 How It Works:
- `digitalWrite(LED, HIGH)` turns the LED on.
- `delay(DELAY_TIME)` pauses the program (here, 1000ms or 1 second).
- `digitalWrite(LED, LOW)` turns the LED off.
- `delay(DELAY_TIME)` again pauses for 1 second before the loop repeats.

---

## ✅ Summary:
- Demonstrates use of `#define` macros for cleaner code.
- Easy way to learn digital output and `delay()` function.
- Great for Arduino beginners.

