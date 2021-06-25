cmake_minimum_required(VERSION 3.17)
project(test)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(../src verilog_preprocessor)
add_subdirectory(testing_utils)
add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../src)

add_executable(test_run TestUtils.cpp)

target_link_libraries(test_run VerilogPreProcessor utils)
#target_link_libraries(test_run verilog_preprocessor)

target_link_libraries(test_run testing_utils)
target_link_libraries(test_run gtest gtest_main)
