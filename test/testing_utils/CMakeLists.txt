cmake_minimum_required(VERSION 3.19)
project(testing_utils)
set(CMAKE_CXX_STANDARD 14)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(testing_utils STATIC testing_utils.cpp testing_utils.h)
