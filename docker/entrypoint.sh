#!/bin/bash
# ========================================================================
# Teensy-Flight-Controller Zephyr Development Container Entrypoint
# ========================================================================


set -e

USER="jmendes"
APP="flight_controller"
APP_DIR="/home/$USER/zephyr_ws/$APP/"
ZEPHYR_HEX="/home/$USER/zephyr_ws/build/zephyr/zephyr.hex"

{
  echo "alias build=\"west build -b teensy41 -S cdc-acm-console $APP_DIR -p\""
  echo "alias flash=\"sudo teensy_loader_cli -mmcu=TEENSY41 -w $ZEPHYR_HEX\""
  echo "alias bf=\"build && flash\""
  echo "alias monitor=\"sudo minicom -D /dev/ttyACM1 -b 115200\""
} >> /home/$USER/.bashrc

exec "$@"
