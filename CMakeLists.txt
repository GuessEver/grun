cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)

project(grun)
set(SOURCE_FILES main.cc Result.cc Result.h Limit.cc Limit.h Grun.cc Grun.h Runner.cc Runner.h Compiler.cc Compiler.h)
add_executable(grun ${SOURCE_FILES})
