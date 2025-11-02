#!/bin/bash
# ========================================================================
# Teensy-Flight-Controller Development Zephyr Docker Image Build Script
# ========================================================================

set -e

CONTAINER_NAME="flight_controller-zephyr-dev"
IMAGE_NAME="flight_controller-zephyr-dev"
WORKSPACE_DIR="zephyr_ws"
WORKSPACE_PATH="$PWD/$WORKSPACE_DIR"
USER_NAME="jmendes"

if [ "$(docker ps -q -f name=^/${CONTAINER_NAME}$)" ]; then
    echo "Container ${CONTAINER_NAME} is already running."
else
    docker run -itd --rm \
      --name $CONTAINER_NAME \
      --hostname $CONTAINER_NAME \
      --privileged \
      -v "$WORKSPACE_PATH":/home/$USER_NAME/$WORKSPACE_DIR \
      --device=/dev/bus/usb \
      $IMAGE_NAME
fi

sleep 1

xdotool key ctrl+shift+e
sleep 0.1
xdotool type "docker exec -it flight_controller-zephyr-dev bash -c 'cd /home/$USER_NAME/zephyr_ws; exec bash'"
xdotool key Return
