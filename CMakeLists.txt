cmake_minimum_required(VERSION 3.26)

project(G9)


set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(src)

enable_testing()

# 编译googletest
add_subdirectory(googletest)

# 把待测源码编译成一个静态库
add_library(gs STATIC src/gs.cpp src/gs.h)

# 编译测试用例
add_subdirectory(Test)

