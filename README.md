# 🚨 Arduino Gas Detector

A real-time gas detection system using Arduino Nano, MQ-9 sensor, OLED display, Relay, and Bluetooth (HM-10).

---

## 📋 Features

- Real-time gas level monitoring
- OLED display shows gas value + SAFE / DANGER status
- Relay automatically triggers when gas level exceeds threshold
- Bluetooth (HM-10) sends live data to phone via Serial Bluetooth Terminal app

---

## 🛠️ Components

| Component | Description |
|---|---|
| Arduino Nano V3.0 (CH340, ATmega328P) | Microcontroller |
| MQ-9 Gas Sensor | CO + Flammable Gas detection |
| 0.96" OLED Display (SSD1306, I2C) | Real-time display |
| Relay Module (HW-482, JQC3F-05VDC) | Automatic trigger |
| HM-10 Bluetooth 4.0 Module | Wireless data transmission |
| Breadboard + Dupont Wires | Circuit connections |

---

## 🔌 Wiring

### OLED (I2C)
| OLED Pin | Arduino Nano |
|---|---|
| GND | GND |
| VDD | 3.3V |
| SCK | A5 |
| SDA | A4 |

### MQ-9 Gas Sensor
| Sensor Pin | Arduino Nano |
|---|---|
| VCC | 5V |
| GND | GND |
| AO | A0 |
| DO | A1 (unused) |

### Relay
| Relay Pin | Arduino Nano |
|---|---|
| S | D7 |
| + | 5V |
| - | GND |

### HM-10 Bluetooth
| HM-10 Pin | Arduino Nano |
|---|---|
| VCC | 3.3V |
| GND | GND |
| TXD | D10 |
| RXD | D11 |

---

## 📁 Code

**File:** `gas_detector.ino`

**Libraries required:**
- `Adafruit SSD1306`
- `Adafruit GFX`
- `Wire` (built-in)
- `SoftwareSerial` (built-in)

Install via Arduino IDE: `Tools → Manage Libraries`

---

## 📱 Bluetooth App

1. Download **Serial Bluetooth Terminal** (Android - Google Play)
2. Open app → Connect → Select HM-10
3. Live data streams in format: `[value] - SAFE` or `[value] - DANGER!`

---

## ⚙️ How It Works

1. MQ-9 sensor reads air quality every 1 second
2. Value is displayed on OLED with status (SAFE / DANGER)
3. If value exceeds **120** → Relay activates + DANGER alert sent via Bluetooth
4. Data is transmitted wirelessly to phone in real-time

---

## 📸 Circuit
![Circuit](circuit.jpg)

---

## 📊 Bluetooth Output
![Bluetooth](bluetooth_screenshot.jpg)

---

## 🚀 Getting Started

1. Wire components as shown above
2. Install required libraries in Arduino IDE
3. Upload `gas_detector.ino` to Arduino Nano
4. Wait ~3 minutes for MQ-9 warm-up
5. Connect phone via Serial Bluetooth Terminal
6. Monitor gas levels in real-time!

---

## 📌 Notes

- MQ-9 requires **2-3 minutes warm-up** on first power-on
- Danger threshold is set to `120` — adjust in code based on your baseline
- HM-10 uses **BLE (Bluetooth 4.0)** — use app's built-in scan, not phone settings

---

## 👨‍💻 Author

Made with ❤️ while learning Arduino + IoT
