docker build -t flight_controller-zephyr-dev \
  --build-arg USER_UID=$(id -u) \
  --build-arg USER_GID=$(id -g) \
  docker/
