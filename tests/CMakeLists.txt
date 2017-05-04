project(tests)

include(CheckFunctionExists)
include(CheckCXXSourceCompiles)
include(CheckLibraryExists)
include(CPack)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

set(LIB_FILES ../src/Result.cc ../src/Result.h ../src/Limit.cc ../src/Limit.h ../src/Grun.cc ../src/Grun.h ../src/Runner.cc ../src/Runner.h ../src/Compiler.cc ../src/Compiler.h ../src/Code.cc ../src/Code.h ../src/Judger.cc ../src/Judger.h ../src/Access.cc ../src/Access.h ../src/okcalls32.h ../src/okcalls64.h)
set(TEST_FILES ../system_tests.cc)
add_executable(tests ${TEST_FILES} ${LIB_FILES})
