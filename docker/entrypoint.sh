#!/bin/bash
# ========================================================================
# Zephyr Development Container Entrypoint
# Mirrors ROS 2 Jazzy environment style
# ========================================================================

set -e

# Environment setup
export ZEPHYR_TOOLCHAIN_VARIANT=${ZEPHYR_TOOLCHAIN_VARIANT:-zephyr}
export ZEPHYR_SDK_INSTALL_DIR=${ZEPHYR_SDK_INSTALL_DIR:-/home/jmendes/zephyr-sdk}
export PATH=$ZEPHYR_SDK_INSTALL_DIR/arm-zephyr-eabi/bin:$HOME/.local/bin:$PATH
export ZEPHYR_BASE=${ZEPHYR_BASE:-/home/jmendes/zephyrproject/zephyr}

if [ -f "$ZEPHYR_BASE/zephyr-env.sh" ]; then
    source "$ZEPHYR_BASE/zephyr-env.sh"
fi

exec "$@"
