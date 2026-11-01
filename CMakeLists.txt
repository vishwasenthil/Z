cmake_minimum_required(VERSION 3.10)
project(Z LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(platform/stm32g4)
add_subdirectory(lib/CMSIS_DSP)
add_subdirectory(zactuator_node)