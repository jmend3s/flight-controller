
cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(flight_controller)

zephyr_include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../application
  ${CMAKE_CURRENT_SOURCE_DIR}/../components
  ${CMAKE_CURRENT_SOURCE_DIR}/../core
  ${CMAKE_CURRENT_SOURCE_DIR}/../drivers
#  ${CMAKE_CURRENT_SOURCE_DIR}/../../services
)

file(GLOB_RECURSE APPLICATION_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../application/*.cpp)
file(GLOB_RECURSE COMPONENT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../components/*.cpp)
file(GLOB_RECURSE CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../core/*.cpp)
file(GLOB_RECURSE DRIVER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../drivers/*.cpp)

target_sources(app PRIVATE
  src/main.cpp
  ${APPLICATION_SOURCES}
  ${COMPONENT_SOURCES}
  ${CORE_SOURCES}
  ${DRIVER_SOURCES}
)