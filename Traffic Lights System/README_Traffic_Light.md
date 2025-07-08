# 🚦 Arduino Traffic Light Simulation

## ✅ Objective:

Simulate a basic 3-phase traffic light system using RED, YELLOW, and GREEN LEDs with appropriate timing.

---

## 🧾 Code Explanation:

```cpp
#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11
#define RED_TIME 15000
#define YELLOW_TIME 5000
#define GREEN_TIME 10000

byte leds[3] = {RED_LED, YELLOW_LED, GREEN_LED};
int timing[3] = {RED_TIME, YELLOW_TIME, GREEN_TIME};

void setup()
{
    for (byte i = 11; i < 14; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    for (byte i = 0; i < 3; i++)
    {
        digitalWrite(leds[i], HIGH);
        delay(timing[i]);
        digitalWrite(leds[i], LOW);
    }
}
```

---

## 🔌 Circuit Connections:

### Components Needed:

- 1x RED LED
- 1x YELLOW LED
- 1x GREEN LED
- 3x Resistors (100Ω – 330Ω)
- Breadboard and jumper wires

### Wiring:

| LED Color  | Arduino Pin | Notes                         |
| ---------- | ----------- | ----------------------------- |
| Red LED    | 13          | Connect through 150Ω resistor |
| Yellow LED | 12          | Connect through 150Ω resistor |
| Green LED  | 11          | Connect through 150Ω resistor |

**All LED cathodes go to GND.**

---

## ⏱️ Timing Overview:

| Phase  | Duration   |
| ------ | ---------- |
| Red    | 15 seconds |
| Yellow | 5 seconds  |
| Green  | 10 seconds |

> The loop cycles through the 3 lights in order: Red → Yellow → Green.

---

## 🧠 How It Works:

- The `leds[]` and `timing[]` arrays store the pins and their durations.
- The loop iterates through each LED, turns it ON for its time, then OFF.
- Creates a simple and scalable traffic light pattern.

---

## ✅ Summary:

- Demonstrates use of arrays for clean code.
- Models real-world traffic light timing.
- Great practice for Arduino control logic, timing, and clean code structure.
 
