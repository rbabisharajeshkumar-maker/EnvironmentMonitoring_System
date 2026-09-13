# Environment Monitoring System
An Arduino-based system that monitors temperature, humidity, and ambient light, displaying live readings and triggering alerts when thresholds are crossed.

## Components Used
- Arduino (Uno/Nano)
- DHT11 Temperature & Humidity Sensor
- LDR (Light Dependent Resistor)
- 16x2 LCD with I2C module
- LED
- Buzzer

## How It Works
- The DHT11 sensor reads ambient temperature and humidity.
- An LDR measures ambient light level on an analog pin.
- All readings (temperature, humidity, light level) are displayed live on a 16x2 I2C LCD.
- If light level or temperature crosses a set threshold, an LED and buzzer are triggered as an alert.

## Protocols/Concepts Used
- I2C communication (LCD via LiquidCrystal_I2C library)
- Digital sensor reading (DHT11 via DHT library)
- Analog sensor reading (LDR)
- Threshold-based automation

## Code
See `ENVIRONMENT_MONITORING_SYSTEM.ino` for the full sketch.
