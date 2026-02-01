# smart-room-environment-monitoring
Embedded system for monitoring temperature and light intensity using Arduino, with automatic alerts and serial output simulation in Tinkercad.

System Structure
Smart-Room-Monitoring/
│── smart_room.ino
│── circuit_screenshot.png
│── README.md



Smart Room Environmental Monitoring and Alert System

Project Description
This project is an embedded system designed to monitor environmental conditions in a room. It measures temperature and light intensity and automatically responds to unsafe or uncomfortable conditions. The system is simulated using Tinkercad and implemented with an Arduino Uno.

Problem Statement
Manual monitoring of room temperature and lighting conditions is inefficient and unreliable. There is a need for an automated system that can monitor environmental conditions and respond appropriately to ensure comfort and safety.

Components Used
Arduino Uno
Breadboard
TMP36 Temperature Sensor
LDR (Photoresistor)
2 LEDs (Alert LED & Room Light LED)
Resistors (220Ω, 10kΩ)
Jumper wires

System Functionality
Continuously monitors room temperature and light intensity
Turns ON an alert LED when temperature exceeds a defined threshold
Turns ON room lighting when light levels are low
Displays real-time sensor readings on the Serial Monitor

System Logic
The Arduino reads analog values from the temperature sensor and LDR
Temperature is converted from voltage to degrees Celsius
Light intensity is measured using a voltage divider circuit
Sensor values are compared with predefined thresholds
LEDs are activated based on the comparison results
System status is displayed via serial communication

Threshold Values
Temperature threshold: 30°C
Light threshold: 400 (analog value)

Simulation
The system is simulated in Tinkercad Circuits. Sensor values are adjusted using sliders to demonstrate system behavior in real time.

The system is simulated in Tinkercad Circuits. Sensor values are adjusted using sliders to demonstrate system behavior in real time.
