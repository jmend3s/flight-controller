#!/bin/bash
# ========================================================================
# Teensy-Flight-Controller Zephyr Build And Flash Script
# ========================================================================

APP=blinky

west build -b teensy41 apps/$APP
sudo teensy_loader_cli -mmcu=TEENSY41 -w build/zephyr/zephyr.hex