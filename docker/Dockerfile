# ========================================================================
# ZEPHYR DEVELOPMENT ENVIRONMENT
# ========================================================================

FROM ubuntu:24.04

ARG USERNAME=jmendes
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG WORKDIR=zephyr_ws

RUN apt-get update && apt-get install -y --no-install-recommends \
    sudo git cmake ninja-build gperf ccache dfu-util device-tree-compiler wget \
    python3-pip python3-setuptools python3-wheel xz-utils file make gcc g++ \
    udev minicom usbutils curl unzip gdb \
  && rm -rf /var/lib/apt/lists/*

RUN if getent passwd $USER_UID >/dev/null; then \
      userdel -r -f $(getent passwd $USER_UID | cut -d: -f1); \
    fi && \
    if getent group $USER_GID >/dev/null; then \
      groupdel $(getent group $USER_GID | cut -d: -f1); \
    fi && \
    groupadd --gid $USER_GID $USERNAME && \
    useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME && \
    mkdir -p /home/$USERNAME/.config && chown $USER_UID:$USER_GID /home/$USERNAME/.config

RUN apt-get update \
  && apt-get install -y sudo \
  && echo "$USERNAME ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME \
  && chmod 0440 /etc/sudoers.d/$USERNAME \
  && rm -rf /var/lib/apt/lists/*

USER $USERNAME
WORKDIR /home/$USERNAME

RUN wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.4/zephyr-sdk-0.17.4_linux-x86_64.tar.xz && \
    tar xf zephyr-sdk-0.17.4_linux-x86_64.tar.xz && \
    rm zephyr-sdk-0.17.4_linux-x86_64.tar.xz && \
    mv zephyr-sdk-0.17.4 zephyr-sdk && \
    yes | /home/$USERNAME/zephyr-sdk/setup.sh -t arm-zephyr-eabi

RUN pip install --break-system-packages --user west && \
    echo 'export PATH=$HOME/.local/bin:$PATH' >> ~/.bashrc

ENV PATH="/home/$USERNAME/.local/bin:/home/$USERNAME/zephyr-sdk/arm-zephyr-eabi/bin:$PATH" \
    ZEPHYR_TOOLCHAIN_VARIANT=zephyr \
    ZEPHYR_SDK_INSTALL_DIR=/home/$USERNAME/zephyr-sdk

RUN mkdir -p ~/zephyrproject && cd ~/zephyrproject && \
    west init && west update && west zephyr-export

COPY entrypoint.sh /entrypoint.sh
RUN sudo chmod +x /entrypoint.sh

RUN mkdir -p /home/$USERNAME/$WORKDIR
WORKDIR /home/$USERNAME/$WORKDIR

ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
CMD ["bash"]