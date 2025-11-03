#!/bin/bash
# ========================================================================
# Teensy-Flight-Controller Zephyr Development Container Entrypoint
# ========================================================================


set -e

export ZEPHYR_TOOLCHAIN_VARIANT=${ZEPHYR_TOOLCHAIN_VARIANT:-gnuarmemb}
export ZEPHYR_BASE=${ZEPHYR_BASE:-/home/jmendes/zephyrproject/zephyr}
export GNUARMEMB_TOOLCHAIN_PATH=${GNUARMEMB_TOOLCHAIN_PATH:-/usr}
export PATH=$HOME/.local/bin:/usr/bin:$PATH

# If board definitions are in custom path
export ZEPHYR_BOARD_ROOT=${ZEPHYR_BOARD_ROOT:-$HOME/zephyr_ws/boards}

if [ -f "$ZEPHYR_BASE/zephyr-env.sh" ]; then
    source "$ZEPHYR_BASE/zephyr-env.sh"
fi

exec "$@"
