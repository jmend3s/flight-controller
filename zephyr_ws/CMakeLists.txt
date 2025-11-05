cmake_minimum_required(VERSION 3.20.0)
project(flight_workspace NONE)

if(NOT DEFINED ENV{ZEPHYR_BASE})
  message(FATAL_ERROR "ZEPHYR_BASE environment variable not set")
endif()

if(NOT DEFINED BOARD)
  set(BOARD "teensy41" CACHE STRING "Default board" FORCE)
endif()

list(APPEND CMAKE_PREFIX_PATH $ENV{ZEPHYR_BASE})

set(APP_LIST
  apps/blinky
)

foreach(APP_PATH ${APP_LIST})
  add_subdirectory(${APP_PATH})
endforeach()