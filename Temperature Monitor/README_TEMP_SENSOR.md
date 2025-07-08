# 🌡️ Arduino Temperature Sensor (Analog)

## ✅ Objective:

Read and display the ambient temperature using an analog temperature sensor (e.g., TMP36) connected to the Arduino.

---

## 🧾 Code Explanation:

```cpp
#define TMP A0

int volt;
float temp;

void setup()
{
    Serial.begin(9600);                        // Initialize serial communication
}

void loop()
{
    volt = analogRead(TMP);                    // Read analog value from sensor
    temp = (5.0 / 1023) * volt * 100 - 50;     // Convert to temperature in Celsius
    Serial.print("Temperature is : ");
    Serial.print(temp);
    Serial.println(" C");
}
```

---

## ⚙️ Components Required:

- Arduino board (Uno, Nano, etc.)
- 1x TMP36 Temperature Sensor
- Jumper wires
- Breadboard

---

## 🔌 Circuit Connections:

| Arduino Pin | TMP36 Pin       | Description                      |
|-------------|------------------|----------------------------------|
| A0          | Vout (middle pin)| Analog voltage output from TMP36 |
| GND         | GND              | Sensor ground                    |
| 5V          | Vs               | Power supply                     |

> ℹ️ The TMP36 outputs 750mV at 25°C. Each 10mV represents 1°C.

---

## 🕹️ Behavior:

- Continuously reads analog voltage from the TMP36.
- Converts voltage to temperature using the formula.
- Prints the temperature to the Serial Monitor.

---

## 📦 Usage:

1. Connect TMP36 sensor to the Arduino as shown.
2. Upload the code.
3. Open the Serial Monitor at 9600 baud to see temperature readings.

---

## 📘 Concepts Used:

- `analogRead()` to read sensor data.
- Voltage-to-temperature conversion using TMP36 formula.
- `Serial.print()` to output data to Serial Monitor.
