# 🔘 Arduino Button-Controlled LED

## ✅ Objective:

Control an LED using a push-button. When the button is pressed, the LED turns ON. When the button is released, the LED turns OFF.

---

## 🧾 Code Explanation:

```cpp
#define LED 11
#define BUTTON 10

void setup()
{
    pinMode(LED, OUTPUT);             // Set pin 11 as output (LED)
    pinMode(BUTTON, INPUT_PULLUP);    // Set pin 10 as input with internal pull-up resistor
}

void loop()
{
    if (!digitalRead(BUTTON))         // If button is pressed (LOW)
    {
        digitalWrite(LED, HIGH);      // Turn ON LED
    }
    else
    {
        digitalWrite(LED, LOW);       // Turn OFF LED
    }
}
```

---

## 🔌 Circuit Connections:

### Components Needed:

- 1x LED
- 1x Resistor (100Ω – 330Ω) for LED
- 1x Push-button
- 1x 10kΩ resistor (optional, if not using INPUT_PULLUP)
- Jumper wires and breadboard

### Wiring:

| Component               | Arduino Pin         | Notes                           |
| ----------------------- | ------------------- | ------------------------------- |
| LED Anode (long leg)    | Pin 11 via resistor | Digital output                  |
| LED Cathode (short leg) | GND                 | Ground                          |
| One side of button      | Pin 10              | Digital input                   |
| Other side of button    | GND                 | When pressed, input becomes LOW |

> ✅ `INPUT_PULLUP` enables internal pull-up resistor, so the button input is HIGH when unpressed and LOW when pressed.

---

## 🧠 How It Works:

- `INPUT_PULLUP` mode keeps the input HIGH by default.
- When the button is pressed, the input reads LOW.
- The LED turns on when button is pressed.

---

## ✅ Summary:

- Demonstrates use of `digitalRead()` and `digitalWrite()`.
- Uses `INPUT_PULLUP` to avoid needing an external pull-up resistor.
- Great for understanding digital inputs and outputs.
