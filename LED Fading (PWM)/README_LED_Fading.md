# 🌟 Arduino LED Fade Effect

## ✅ Objective:

Create a smooth fade-in and fade-out effect on an LED using Pulse Width Modulation (PWM).

---

## 🧾 Code Explanation:

```cpp
#define LED 11

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 255; i++)
    {
        analogWrite(LED, i);
        delay(5);
    }
    for (int i = 255; i > 0; i--)
    {
        analogWrite(LED, i);
        delay(5);
    }
}
```

---

## 🔌 Circuit Connections:

### Components Needed:

- 1x LED
- 1x Resistor (150Ω)
- Breadboard and jumper wires

### Wiring:

| Component | Arduino Pin | Notes                         |
| --------- | ----------- | ----------------------------- |
| LED       | 11          | Connect through 150Ω resistor |

**LED cathode (short leg) goes to GND.**

---

## 🌈 Brightness Transition:

| Direction | Range   | Speed    |
| --------- | ------- | -------- |
| Fade In   | 0 → 255 | 5ms/step |
| Fade Out  | 255 → 0 | 5ms/step |

> The LED fades up and down in an infinite loop.

---

## 🧠 How It Works:

- `analogWrite()` sets the PWM signal on the LED pin.
- Brightness increases from 0 to 255, then decreases.
- `delay(5)` sets the speed of the transition.
- Smooth visual fading effect is achieved.

---

## ✅ Summary:

- Demonstrates use of PWM for analog output simulation.
- Simple loop structure for clean fading effect.
- Great beginner project to learn LED control with Arduino.
