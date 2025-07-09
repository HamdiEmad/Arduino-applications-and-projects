# 🎮 Arduino LED Selector Using Buttons

## ✅ Objective:

Control a set of six colored LEDs using three push buttons:
- **Right Button**: Move selection to the previous LED
- **Left Button**: Move selection to the next LED
- **Random Button**: Light up a randomly selected LED

---

## 🧾 Code Explanation:

```cpp
#define GREEN 13
#define YELLOW 12
#define ORANGE 11
#define RED 10
#define WHITE 9
#define BLUE 8
#define btn_right 7
#define btn_random 6
#define btn_left 5

const byte leds[] = {BLUE, WHITE, RED, ORANGE, YELLOW, GREEN};
const byte btns[3] = {btn_right, btn_random, btn_left};

const byte ledCount = sizeof(leds) / sizeof(leds[0]);
byte currentIndex = 3;

void setup()
{
    for (byte i = 0; i < 3 + 1; i++)
    {
        pinMode(btns[i], INPUT_PULLUP);     // Configure buttons as input with pull-up resistors
    }
    for (byte i = 0; i < ledCount; i++)
    {
        pinMode(leds[i], OUTPUT);           // Configure LED pins as output
    }
    digitalWrite(leds[currentIndex], HIGH); // Turn on the initial LED (ORANGE)
}

void loop()
{
    if (!digitalRead(btn_right)) {
        updateIndex(btn_right);
    }
    if (!digitalRead(btn_left)) {
        updateIndex(btn_left);
    }
    if (!digitalRead(btn_random)) {
        updateIndex(btn_random);
    }
}

void updateIndex(byte direction)
{
    delay(50);  // Basic debounce
    while (!digitalRead(direction)); // Wait for button release

    digitalWrite(leds[currentIndex], LOW); // Turn off current LED

    if (direction == btn_right)
        moveRight();
    else if (direction == btn_left)
        moveLeft();
    else if (direction == btn_random)
        currentIndex = random(0, ledCount); // Pick a random LED index

    digitalWrite(leds[currentIndex], HIGH); // Turn on new selected LED
}

void moveRight()
{
    currentIndex = (currentIndex - 1 + ledCount) % ledCount; // Wrap around backward
}

void moveLeft()
{
    currentIndex = (currentIndex + 1) % ledCount; // Wrap around forward
}
```

---

## ⚙️ Components Required:

- Arduino board (Uno, Nano, etc.)
- 6x LEDs (Blue, White, Red, Orange, Yellow, Green)
- 6x 150Ω Resistors (for LEDs)
- 3x Push buttons
- Jumper wires
- Breadboard

---

## 🔌 Circuit Connections:

| Arduino Pin | Component        | Description                          |
|-------------|------------------|--------------------------------------|
| D13         | Green LED        |                                      |
| D12         | Yellow LED       |                                      |
| D11         | Orange LED       | Initial LED                          |
| D10         | Red LED          |                                      |
| D9          | White LED        |                                      |
| D8          | Blue LED         |                                      |
| D7          | Right Button     | Moves LED selection to the left      |
| D6          | Random Button    | Picks a random LED                   |
| D5          | Left Button      | Moves LED selection to the right     |
| GND         | All Buttons/LEDs | Connected via resistors to ground    |

---

## 🕹️ Behavior:

- **Right Button (D7)**: Lights the previous LED (left in array).
- **Left Button (D5)**: Lights the next LED (right in array).
- **Random Button (D6)**: Lights a randomly chosen LED.

---

## 📦 Usage:

1. Wire the components as described.
2. Upload the code to your Arduino board.
3. Use the buttons to navigate through the LEDs.

---

## 📘 Concepts Used:

- Arrays for LED/button management
- Debouncing button inputs
- Index wrapping using modulo arithmetic
- `digitalRead()` and `digitalWrite()` for control
