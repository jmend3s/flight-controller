cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(flight_controller)

zephyr_include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers
#  ${CMAKE_CURRENT_SOURCE_DIR}/../../services
)

file(GLOB_RECURSE DRIVER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers/*.cpp)
target_sources(app PRIVATE
  src/main.cpp
  ${DRIVER_SOURCES}
)