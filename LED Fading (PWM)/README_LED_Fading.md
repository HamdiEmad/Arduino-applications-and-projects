# Arduino LED Fade Effect

This project demonstrates how to smoothly fade an LED's brightness up and down using Pulse Width Modulation (PWM) with an Arduino board.

## Description

The code uses the `analogWrite()` function to control the brightness of an LED connected to a PWM-capable digital pin on the Arduino. It gradually increases the brightness from 0 to 255 and then decreases it back to 0 in a continuous loop, creating a "breathing" or fading effect.

## Hardware Required

- 1 × Arduino board (e.g., Uno, Mega, Nano)
- 1 × LED
- 1 × 150Ω resistor (to limit current to the LED)
- Breadboard and jumper wires

## Circuit Diagram

```
Arduino Pin 11 ---[150Ω resistor]---|>|--- GND
                                 (LED)
```

- Connect the anode (longer leg) of the LED to Arduino digital pin 11 through a 150Ω resistor.
- Connect the cathode (shorter leg) of the LED to GND.

## Code

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

## How It Works

- `analogWrite(LED, i)` sends a PWM signal with duty cycle from 0 (off) to 255 (fully on).
- The `for` loops smoothly transition brightness up and down.
- `delay(5)` controls the speed of the fade effect.
