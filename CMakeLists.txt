cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GTK_CFLAGS} -std=c++11)

project(grun)
set(LIB_FILES src/Result.cc src/Result.h src/Limit.cc src/Limit.h src/Grun.cc src/Grun.h src/Runner.cc src/Runner.h src/Compiler.cc src/Compiler.h src/Code.cc src/Code.h src/Judger.cc src/Judger.h src/Access.cc src/Access.h src/okcalls32.h src/okcalls64.h)
set(DEMO_FILES main.cc)
add_executable(grun ${DEMO_FILES} ${LIB_FILES})

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

project(system_tests)
set(TEST_FILES system_tests.cc)
add_executable(system_tests ${TEST_FILES} ${LIB_FILES})
target_link_libraries(system_tests ${GTEST_LIBRARIES} pthread)

project(unit_tests)
set(TEST_FILES unit_tests.cc)
add_executable(unit_tests ${TEST_FILES} ${LIB_FILES})
target_link_libraries(unit_tests ${GTEST_LIBRARIES} pthread)
