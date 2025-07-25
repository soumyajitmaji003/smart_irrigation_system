# smart_irrigation_system
🌱 Smart Irrigation System with LCD Display

This project is an automated irrigation controller using an Arduino, a soil moisture sensor, and an I2C LCD. It turns a motor (or water pump) on or off based on soil moisture readings and provides real-time status updates on a 16x2 LCD screen.

📷 Features ✅ Reads real-time soil moisture using analog sensor ✅ Controls a motor or water pump based on moisture level ✅ Displays system and moisture status on a 16x2 I2C LCD ✅ Optimized LCD updates to avoid flicker ✅ Debug output via Serial Monitor ✅ Simple, reliable logic for automation 🔧 Hardware Required Component Quantity Arduino UNO / Nano / Mega 1 Soil Moisture Sensor 1 16x2 I2C LCD Display 1 Relay Module (for motor) 1 Water Pump or Motor 1 Jumper Wires several Breadboard optional Power Supply (5V) 1 🖥️ How It Works The moisture sensor reads soil conditions via analog pin A0. If the soil is too dry, the pump (connected via relay on pin 2) turns ON. The LCD shows: Motor state: ON / OFF Moisture level: HIGH / MID / LOW Serial Monitor logs the raw sensor value for debugging. 🧪 Moisture Level Logic Sensor Value Moisture Level Action < 300 High Pump OFF 300 - 950 Mid Pump OFF

950 Low (Dry) Pump ON 📂 File Structure . ├── SmartIrrigation.ino # Main Arduino sketch └── README.md # Project documentation ▶️ Getting Started Clone this repository or download the .ino file. Open in Arduino IDE. Install required libraries: LiquidCrystal_I2C (by Frank de Brabander or equivalent) Upload the sketch to your Arduino. Open Serial Monitor (9600 baud) to see sensor values.

[Soil Moisture Sensor] |
|-- A0 (Arduino analog input)

[16x2 I2C LCD] SDA -- A4 (Arduino SDA) SCL -- A5 (Arduino SCL) VCC -- 5V GND -- GND

[Relay Module] IN -- D2 (Arduino digital output) VCC -- 5V GND -- GND

[Water Pump] Connected to relay output terminals (NO & COM)

[Power Supply] 5V -- Arduino 5V, Relay VCC, LCD VCC GND -- Common ground for all components
