# Hybrid Tracking and Energy-Aware Solar Tracker System

An embedded system that maximizes net solar energy generation by combining hybrid sun tracking and energy-aware decision algorithms.

## Features

• Hybrid sun tracking (sensor + time based)
• Energy-aware movement decision
• Real-time solar power monitoring
• Motor optimization to reduce power loss
• Embedded microcontroller implementation

## System Overview

Traditional solar trackers continuously move, consuming unnecessary energy.  
This system introduces a decision mechanism that moves the solar panel only when the expected energy gain exceeds motor energy consumption.

## Hardware Components

- Arduino / ESP32
- LDR sensors
- Servo motor
- Solar panel
- Voltage sensing circuit
- Current sensor (ACS712)

## Software

Language:
- Embedded C (Arduino)

Tools:
- Arduino IDE
- Python (optional analysis)
- KiCad (optional PCB)

## System Architecture

Input Layer
- Light Sensors
- Voltage Sensor
- Current Sensor

Processing Layer
- Hybrid tracking algorithm
- Energy-aware decision logic

Output Layer
- Servo motor positioning

## Energy-Aware Logic

The panel moves only when:

Power Gain > Motor Energy Consumption

Power is calculated as:

P = V × I

## Applications

- Off-grid solar systems
- IoT energy nodes
- Smart agriculture
- Remote sensing stations

## Future Work

- AI-based predictive tracking
- Weather adaptive system
- IoT dashboard monitoring

## Author

Lakshnaa Jayakumar  
Electronics & Computer Science Engineering
