cmake_minimum_required(VERSION 3.10)
project(chip8)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_STANDARD 20)
add_executable(chip8 main.cpp src/emulator_main.h src/emulator_main.cpp)
target_link_libraries(chip8 PRIVATE SDL3::SDL3)

