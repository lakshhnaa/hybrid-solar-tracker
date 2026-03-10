# Hybrid Tracking and Energy-Aware Solar Tracker System

An embedded system that maximizes net solar energy generation by combining hybrid sun tracking and energy-aware decision algorithms.

## Features

## Key Features

• Hybrid Sun Tracking  
Combines real-time LDR sensor feedback with algorithm-based positioning to improve tracking accuracy.

• Energy-Aware Tracking Logic  
The panel moves only when the expected solar power gain is greater than the energy consumed by the motor.

• Real-Time Power Estimation  
The system estimates solar output using voltage and current sensing to calculate instantaneous power.

• Movement Threshold Control  
A threshold is implemented to prevent unnecessary motor oscillations due to minor light variations.

• Low-Power Embedded Design  
Implemented on ESP32 for efficient sensor processing and motor control.

• Modular Embedded Architecture  
Sensor reading, power estimation, and motor control are separated logically for easier expansion.

• Expandable for Smart Energy Systems  
The system can be extended with IoT monitoring, AI-based prediction, or weather-adaptive tracking.

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
