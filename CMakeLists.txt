cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_STANDARD 99)

project(grun)
set(SOURCE_FILES main.cc src/Result.cc src/Result.h src/Limit.cc src/Limit.h src/Grun.cc src/Grun.h src/Runner.cc src/Runner.h src/Compiler.cc src/Compiler.h src/Code.cc src/Code.h)
add_executable(grun ${SOURCE_FILES})
