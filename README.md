# Flight Controller #

![Docker](https://img.shields.io/badge/Docker-28.5.1-blue)
![OS](https://img.shields.io/ubuntu/v/ubuntu-wallpapers/noble?color=6A0DAD)
![Zephyr](https://img.shields.io/badge/Zephyr_RTOS-v4.2.0-44B7E9.svg?logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMDAwIDEwMDAiPjxwYXRoIGZpbGw9IiNmZmYiIGQ9Ik00OTcuNyAwQzI0My45IDAtMzguNCA1MDMuOCAyLjQgOTcwLjNsNDYzLjktMjE5LjljMCAwIDI1LjQtMzkuNiAyOC42LTg3LjIgNC40LTUyLjUgNS41LTEwMi45IDguNy0xNTIuMiAxNS43LTY4LjMgMTQuNy01OC45IDktMTg3LjktNS41LTEzNC4xLTUuNS0xMjktNS41LTEyOS00Ni42LTQ0LjgtODAuNy00NS45LTQxLjYtMTQ5LjIgNDYuMi03Ni40IDEyMi4zLTY5LjEgMTQ4LjUtMTkuOCAzMS45IDYwLjYgMjcuNSAxMjAuMiAyMi42IDIyNC4xLTE0LjcgMjYwLjYtNDkuMiA0MjguMi02Mi42IDQ3OC44LTExLjEgNTUuNi0xNzIuNyA3OC41LTMzMy41IDM4LjgtMTY4LjgtNDEuNi0yNzQuNi0xNjMuOC0yODQuMi0zMzguNi00LjQtNjkuMy0yMS40LTEyOS00MS42LTIzOC4xLTExLjEtNTYuNy0xMC44LTYwIDMyLTcwLjUgNDAuMy03LjQgNDcuNi01LjUgMzEuNC03Mi44LTE3LjktNzMuNi01MS4yLTE1NS44LTgxLjQtMjM2LjgtMjYuNS02OS45LTk0LjQtMTQ3LjYtMTYxLjctMjA0LjMtNjguMy01OC4yLTIyMC4xLTk4LjUtMjA2LjctNDM5LjIgMi40LTU3LjcgMTcuMi01OS4yIDU1LTMwLjggOTguOSA3My4yIDkyLjUgNDcuNyAzMi43LTExNi41LTM4LjgtMTYwLjEtMTY4LjgtMTQyLjQtMTM0LjEtMzguOC00Ni4yIDc3LjEtMTMuMiAxNzUuOCAyMi41IDI1NS41IDI1LjUgMzguMSAxNS4xIDM4LjEtMTUuMS02Mi41LTEzMS41LTM3LjMtMTc0LjUtMTkuOC0yODcuNyAyMC03NC44IDk3LjItMTAwLjUgMTYwLjktOTIuOSAyNTkuMyA2LjEgNTIuMiA2LjEgMTIwLjktNC4yIDE3Mi41LTMuMiAxMy40LTcuNCA0Ny45LTMwLjggMTAwLjgtMjYuNSA2MC40LTIwLjEgNjMuMiA0LjIgMjIuMyA0MS42LTQ5LjIgNDIuMi0xMDMuOCAzMi43LTE3OC42LTcuMi01My43LTExLjEtODcuMS0xMi42LTE1MS40LTEuMS00OS40IDQuNC0xMzEuOS0zLjItMTU0LjctMjMuMi02MS4zLTc0LjgtMTA0LjUtMTU4LjEtMTQ5LjItNzcuNC00MS42LTE2NC4xLTY2LjgtMjQ5LjEtNjguMi0xMTkuMi0yLjItMjEwLjMgNDQuMi0yNjguNyAxMTguMi01Mi41IDY2LjgtNTUuOCAxNjguOS0xNy41IDI3Ni41IDc1LjggMjE1LjMgMjM4IDQxOC42IDU3Ny4zIDM3OC40IDMzMi4zLTQwLjMgNTMzLjktMjQ4LjUgNTM3LjMtNTQ5LjEgMy43LTMzMC0yMjMuNS01OTAuNS01MzEuNS01NzktNDMuMiAxLjUtNzYuMSA2LjYtMTAzLjEgMjMuMS0yNy43IDE2LjQtNDMuNiAzNy42LTQ3LjggNjUuOC02LjYgNDMuOC03LjkgOTUuNi0xNi4xIDE0OC41LTguNyA1NC41LTEyLjYgODcuMi0xMy40IDEyNS40LS40IDIxLjYgMS40IDc0LjItMi44IDE0NC44LTExLjQgMTg4LjctMzUuNiAyMjEuNi04MC4xIDIyMS42IDAgMC00LjUgMC01LjctLjQtMS41LS41LTIuOS0xLjEtMy41LTEuNy0xLjUtMS43LTIuNi0zLjQtMy4xLTUuNC01LjEtMzIuMy02LjktMTAyLjQtNS45LTEzMS41IDUtMTUzIDcuNS0xNjYuMiA3LjgtMjIyLjUgLjktNzMuMy00LjYtOTguMy0xOS4zLTE1OC4yLTEyLjMtNDkuMi0xMi45LTYwLjUtNy44LTEwMy4zIDguMy02OC42IDcuMi0xNDMuNyAxMC0yMzUuNiAxLjQtNTQuOC00NS40LTQ5LjItMTQxLjQtMTMuNi0xMjEuMiAzOS41LTE3Mi43IDEwMS40LTIwMy4xIDE3NS00MC42IDk1LjYtNDUuMiAxNzEuNi0xOC40IDI2Mi40IDMzLjQgMTEwLjcgNTkuNSAyMzUuMiA1MS45IDMzOS44LTkuOCAxMzYuNy04Ny40IDI1Ni4zLTIyMS4yIDMwOC4xLTM1LjYgMTMuNi03My43IDIyLjQtMTEzLjQgMjUuMy0xNzEuNCAxMi41LTM2MS41LTcyLjYtNDQ1LjgtMjE1LjMtNDEuOS03Mi4zLTg1LjItMTg2LjQtMTExLjYtMjQzLjcgNjAuNyAzNy43IDExMy40IDMyLjEgMTM4LjQtMjQuMiA0Mi4zLTkyLjMtNDkuMi0xOTcuNi0xOTQuMy0xOTcuNi0xMzIuNSAwLTIyMy40IDc3LjUtMjg2LjcgMjIyLjUtMTQuMyAxMDEuNC0xNi43IDIwNS40LTkuOSAzMTQuOSAxNC44IDI0NC4yIDIyMC42IDQzNy42IDQ3OC44IDQyMi40IDIwOS4xLTEyLjMgMzY5LjctMjEyLjkgMzc1LjItNDI3LjEgNC44LTIwMi41LTE3Ny40LTM3MC45LTM5MS41LTM2NS44Ii8+PC9zdmc+)
![CLion Version](https://img.shields.io/badge/CLion-2025.2.4-007ACC)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

This repository contains the firmware for a flight controller built around **Teensy 4.1**.
It manages sensor signals, control loops, and communication with a companion computer and/or the RC controller.
Although developed as part of the [Autonomous Drone](https://github.com/jmend3s/autonomous-drone?tab=readme-ov-file) project, it is designed to be modular and adaptable to other 
aerial or robotic platforms.

---
### Project Objectives
This project aims to develop a flexible flight controller with the following goals:

- **Low-level hardware control** — PWM generation and ESC management.
- **Sensor fusion and state estimation** — Combine IMU, barometer, and GPS data for stable attitude control.
- **Telemetry and communication** — Define a robust serial protocol for data exchange with companion computer.
- **Remote control input** — Interpret manual RC data for pilot-assisted flight.
- **Diagnostics and failsafe routines** — Detect communication loss, low battery, or sensor faults.
- **Portable and testable architecture** — Modular layers and clear interfaces to support simulation and unit testing.

---
### System Overview

```
+------------------+             +-------------------+             +------------+             
|    Controller    |  <------->  |  Teensy 4.1 MCU   |  <------->  | ESC / IMU  |  
|  (RC, RPY, ...)  |             |  Flight Controller|             | Interfaces |             
+------------------+             +-------------------+             +------------+             
```

---
### Project Structure

```
docker/                   # Dockerfile and helper scripts
docs/                     # Diagrams and documentation
zephyr_ws/                # Zephyr's workspace
├── core_kit/             # CoreKit framework 
│   ├── application/      # Base Application 
│   ├── components/       # Base Components
│   ├── core/             # Core of the framework
│   └── drivers/          # Base Drivers
├── flight_controller/    # Flight Controller application
│   ├── src/              # main.c
└── CMakeLists.txt
```

---
### Quick Start 

 - Clone the repository ```git clone git@github.com:jmend3s/flight-controller.git``` <br>
 - Go to project root ```cd flight-controller/```
 - Build the docker image ```./docker/build.sh``` <br>
 - Start container ```./docker/run.sh``` **refer to the documentation on the script to use without Terminator and xdotool** <br>
 - **Inside the container** build and flash Teensy use the command aliases ```build```, ```flash``` and ```bf``` for both <br>
 - Use the alias ```monitor``` to bring up minicom serial monitor <br>
 - Click the reset button on Teensy for bootloader mode <br>
**Be sure to run all the Docker scripts on the project's root!**

---
### CoreKit

CoreKit is a modular light-weight framework that abstracts Zephyr's HAL and presents it in a C++ friendly architecture.
While Zephyr works in terms of devices, drivers, and macros, CoreKit enables development in terms of **components, services, and behavior**. <br>
Although designed for the Flight Controller, CoreKit is intended to evolve into an independent, reusable framework for 
any Zephyr-based application.  

---
### Current Status

**Software**
- [x] Set up Docker and Zephyr environments
- [x] Set a working component system
- [x] Set a DeviceTree-aware GPIO driver
- [x] Set a basic application loop
- [x] Set a basic software timer
- [ ] Define base firmware architecture (drivers, services, application layers)
- [ ] Implement IMU driver
- [ ] Integrate NRF24L01 communication
- [ ] Create unit testing environment for control logic

**Hardware**
- [ ] Create electrical schematics
- [ ] PCB and components arrangement
- [ ] Drone platform integration

---
### Hardware

- **Microcontroller:** Teensy 4.1 (600 MHz, Cortex-M7)
- **IMU:** BNO086 (SPI/I2C)
- **GPS + Magnetometer:** HGLRC M100-5883 M10 (UART)
- **Transceiver:** NRF24L01-PA + LNA (SPI)
