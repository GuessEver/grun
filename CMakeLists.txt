cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)

project(grun)
set(SOURCE_FILES main.cc result.cc result.h limit.cc limit.h grun.cc grun.h)
add_executable(grun ${SOURCE_FILES})
