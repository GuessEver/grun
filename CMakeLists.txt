cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)

project(tester)
set(TESTER_SOURCE_FILES tester.c)
add_executable(tester ${TESTER_SOURCE_FILES})

project(grun)
set(SOURCE_FILES main.c result.c result.h limit.c limit.h grun.c grun.h)
add_executable(grun ${SOURCE_FILES})
