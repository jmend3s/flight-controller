#!/bin/bash
# ========================================================================
# Teensy-Flight-Controller Zephyr Build And Flash Script
# ========================================================================

APP=flight_controller

west build -b teensy41 $APP -p
sudo teensy_loader_cli -mmcu=TEENSY41 -w build/zephyr/zephyr.hex