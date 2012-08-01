cmake_minimum_required(VERSION 2.8)

set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain

project(ArduinoExample C CXX)

set(ARDUINO_DEFAULT_BOARD mega2560) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0) # Default Port, when not specified

add_subdirectory(libs)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_subdirectory(src)   #add the example directory into build

