# GPS-Pet-Tracker-Firmware

🔩 Hardware Assumptions
Microcontroller: ESP32 (e.g., ESP32-WROOM-32)

Integrated Components:
| Component     | Purpose                    | Suggested Model               |
| ------------- | -------------------------- | ----------------------------- |
| GPS           | Location tracking          | u-blox NEO-6M or u-blox M8N   |
| Accelerometer | Motion detection           | MPU6050 or LIS3DH             |
| Temp Sensor   | Environmental monitoring   | DS18B20 or onboard in MPU6050 |
| Microphone    | Sound sensing              | Analog MEMS mic + ADC         |
| Speaker       | Owner recall (beeps/tones) | 8Ω mini speaker + DAC/PWM     |
| RGB LED       | Status indicator           | WS2812B or discrete RGB LED   |
| Battery       | Power source               | \~1000–1500 mAh LiPo          |
| Charger IC    | Battery charging           | TP4056 or similar             |


🧠 Firmware Features Overview
✅ Core Capabilities
Location update every X minutes (GPS + Wi-Fi/BLE fallback)
Sleep mode between updates for battery saving
BLE advertisement with tracker ID & recent data
Motion-triggered wake and data refresh
OTA firmware updates
Microphone-based bark/noise detection
Speaker tone recall or feedback sound
RGB LED for status/alerts

🧱 Architecture Summary
Main Components

main/
├── main.cpp                # Main loop
├── gps_module.cpp/h        # GPS handling
├── sensors.cpp/h           # Accelerometer + temperature
├── ble_module.cpp/h        # BLE Advertising
├── wifi_scan.cpp/h         # Passive Wi-Fi scanning
├── led.cpp/h               # RGB LED control
├── power.cpp/h             # Sleep/wake logic
├── ota.cpp/h               # OTA handling
├── audio.cpp/h             # Mic and speaker
├── config.h                # Configurable constants

## 🚀 Power Optimization

- Uses ESP32 deep sleep between updates
- Motion wake via accelerometer (optional)
- Minimal LED usage and BLE advertising
- GPS/Wi-Fi turned off when idle

## 🔄 BLE Data Packet Format

Example BLE payload (encoded as manufacturer data):
Device: PetTracker
Lat: 14.5995
Lon: 120.9842
Temp: 28.5°C
Motion: 1
Sound: 145
Battery: 85%


## 📡 OTA Update

Supports OTA updates via Wi-Fi using ArduinoOTA.

## 🧪 Testing & Simulation

Use Serial Monitor for simulated output from:
- GPS position
- Wi-Fi scan result
- Accelerometer movement
- Temperature and mic readings

## 🔧 Setup (PlatformIO)

```ini
[env:esp32]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
lib_deps =
  adafruit/Adafruit MPU6050
  adafruit/Adafruit NeoPixel
  mikalhart/TinyGPSPlus
  esp32/ArduinoOTA

📜 License
MIT License – free for personal/commercial use with attribution.
"""
