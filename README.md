# ☀️⚡ Hybrid Energy-Aware Solar Tracker (ESP32)

Built using **ESP32 + sensor fusion + embedded control logic** to maximize **net solar power generation**.

---

# 🚀 Project Vision

Traditional solar trackers rotate continuously, which often **wastes energy on motor movement**.

This project introduces an **Energy-Aware Solar Tracking System** that evaluates:

Energy Gain from Repositioning  
vs  
Energy Consumed by Motor Movement  

The panel moves **only when the energy gain is higher than the motor cost**.

⚡ Higher net energy output  
⚡ Reduced mechanical wear  
⚡ Intelligent renewable energy control  

---

# 🧠 Core Concepts

### 🔭 Hybrid Sun Tracking
Two **LDR sensors** are placed on opposite sides of the solar panel to detect light intensity differences.  
The ESP32 compares these readings to determine the **direction of maximum sunlight**.

---


---

### 🧩 Embedded System Architecture
All decision-making is handled by the **ESP32 microcontroller**, which performs:

• Sensor acquisition  
• Light difference calculation  
• Power estimation  
• Energy-aware decision logic  
• Servo motor actuation  

---
---

# 💻 Tech Stack

The Hybrid Energy-Aware Solar Tracker is implemented using a lightweight **embedded firmware architecture** designed for real-time sensor processing and motor control.

### ⚙️ Programming Language
- **Embedded C / C++** (Arduino Framework)

### 🧠 Microcontroller Platform
- **ESP32 Development Board**

### 🛠 Development Environment
- **Arduino IDE** – firmware development and debugging  
- **ESP32 Board Package** – hardware abstraction and drivers

### 📚 Core Libraries
- **Servo.h** – servo motor control  
- **Arduino Core Libraries** – GPIO, ADC, timing functions

### 🔬 Functional Modules

**Sensor Interface Module**
- Reads analog signals from LDR sensors
- Acquires voltage and current sensor data
- Performs signal scaling and normalization

**Tracking Algorithm Module**
- Computes light intensity difference
- Determines optimal panel rotation direction

**Energy-Aware Decision Module**
- Calculates instantaneous solar power

- Compares power gain with motor energy cost
- Enables movement only when energy gain is positive

**Motor Control Module**
- Controls servo motor rotation
- Applies movement constraints and threshold logic

### 📊 Optional Analysis Tools
- **Python (Matplotlib / Pandas)** – solar output visualization
- **Serial Monitor** – real-time debugging and power tracking

### 🔧 Version Control
- **Git**
- **GitHub repository for firmware, documentation, and hardware files**
