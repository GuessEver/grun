cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_STANDARD 99)

project(demo)
set(LIB_FILES ../src/Result.cc ../src/Result.h ../src/Limit.cc ../src/Limit.h ../src/Grun.cc ../src/Grun.h ../src/Runner.cc ../src/Runner.h ../src/Compiler.cc ../src/Compiler.h ../src/Code.cc ../src/Code.h ../src/Judger.cc ../src/Judger.h ../src/Access.cc ../src/Access.h ../src/okcalls32.h ../src/okcalls64.h)
set(DEMO_FILES main.cc)
add_executable(demo ${DEMO_FILES} ${LIB_FILES})
