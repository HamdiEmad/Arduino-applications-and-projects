# 💡 Arduino LDR-Based LED Brightness Control

## ✅ Objective:

Automatically adjust the brightness of an LED based on the ambient light level detected by an LDR (Light Dependent Resistor).

---

## 🧾 Code Explanation:

```cpp
#define LDR A0
#define LED 11

void setup()
{
    pinMode(LDR, INPUT_PULLUP);       // Set LDR pin as input with internal pull-up
    pinMode(LED, OUTPUT);             // Set LED pin as output
    Serial.begin(9600);               // Initialize serial communication for debugging
}

void loop()
{
    int lightLevel = analogRead(LDR);                     // Read the light level (0-1023)
    int pwmValue = map(lightLevel, 0, 1023, 0, 255);      // Convert it to PWM range (0-255)
    analogWrite(LED, pwmValue);                           // Adjust LED brightness
}
```

---

## ⚙️ Components Required:

- Arduino board (Uno, Nano, etc.)
- 1x LDR (Light Dependent Resistor)
- 1x LED
- 1x 150Ω Resistor (for LED)
- Jumper wires
- Breadboard

---

## 🔌 Circuit Connections:

| Arduino Pin | Component            | Description                          |
| ----------- | -------------------- | ------------------------------------ |
| A0          | LDR                  | Light dependent resistor (LDR)       |
| D11         | LED Anode (via 150Ω) | Controls LED brightness (PWM output) |
| GND         | LED Cathode & LDR    | Ground reference                     |
| 5V          | LDR Voltage Source   | Supplies power to LDR                |

---

## 🕹️ Behavior:

- Bright light → Higher analog value → Higher PWM → Brighter LED.
- Dim light → Lower analog value → Lower PWM → Dimmer LED.

---

## 📦 Usage:

1. Connect the circuit as described.
2. Upload the code to your Arduino board.
3. Observe the LED brightness change with ambient light levels.

---

## 📘 Concepts Used:

- `analogRead()` to measure light intensity.
- `map()` to scale input to PWM range.
- `analogWrite()` to control LED brightness.
