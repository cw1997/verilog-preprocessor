cmake_minimum_required(VERSION 3.17)
project(verilog_preprocessor)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(utils)

add_executable(verilog_preprocessor main.cpp)

add_library(VerilogPreProcessor STATIC VerilogPreProcessor.cpp VerilogPreProcessor.h)

target_link_libraries(verilog_preprocessor PUBLIC VerilogPreProcessor utils)
