cmake_minimum_required(VERSION 3.20.0)
project(flight_workspace NONE)

if(NOT DEFINED ENV{ZEPHYR_BASE})
  message(FATAL_ERROR "ZEPHYR_BASE environment variable not set")
endif()

list(APPEND CMAKE_PREFIX_PATH $ENV{ZEPHYR_BASE})
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

if(NOT DEFINED BOARD)
  set(BOARD "teensy41" CACHE STRING "Default board" FORCE)
endif()

set(APP_LIST
  apps/flight_controller
)

foreach(APP_PATH ${APP_LIST})
  add_subdirectory(${APP_PATH})
endforeach()