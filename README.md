# Flight Controller #

![PlatformIO Core 6.1.16](https://img.shields.io/badge/PlatformIO_Core-6.1.16-E37B0D?logo=platformio&logoColor=white)
![CLion Version](https://img.shields.io/badge/CLion-2025.2.4-007ACC)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

This repository contains the firmware for a Teensy 4.1 based flight controller.
It manages sensor signals, control loops, and communication with a companion computer and/or RC controller.
Although developed as part of the [Autonomous Drone](https://github.com/jmend3s/autonomous-drone?tab=readme-ov-file) project, it is designed to be modular and adaptable to other aerial platforms.

---
### Project Objectives
This project aims to develop a flexible flight controller with the following goals:

- **Low-level hardware control** — PWM generation and ESC management.
- **Sensor fusion and state estimation** — combine IMU, barometer, and GPS data for stable attitude control.
- **Telemetry and communication** — serial protocol with companion computer.
- **Remote control input** — interpret manual RC data for pilot-assisted flight.
- **Diagnostics and failsafe routines** — detect communication loss, low battery, or sensor faults.



---
### System Overview

```
+------------------+             +-------------------+             +------------+             
|    Controller    |  <------->  |  Teensy 4.1 MCU   |  <------->  | ESC / IMU  |  
|  (RC, RPY, ...)  |             |  Flight Controller|             | Interfaces |             
+------------------+             +-------------------+             +------------+             
```

---
### Current Status

- [ ] Define base firmware architecture (drivers, services, application layers)
- [ ] Implement IMU driver
- [ ] Integrate NRF24L01 communication
- [ ] Evaluate RTOS options (Zephyr vs bare-metal)
- [ ] Create unit testing environment for control logic

---
### Hardware

- **Microcontroller:** Teensy 4.1 (600 MHz, Cortex-M7)
- **IMU:** BNO086 (SPI/I²C)
- **GPS + Magnetometer:** HGLRC M100-5883 M10 (UART)
- **Transceiver:** NRF24L01-PA + LNA (SPI)
