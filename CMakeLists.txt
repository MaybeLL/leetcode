#CMake最低版本号要求
cmake_minimum_required(VERSION 3.12)
#项目信息
project(leetcode)
# set(变量 值)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp dp/reader_writer.cpp)
#指定生成目标
add_executable(leetcode ${SOURCE_FILES})

#cmake_minimum_required(VERSION 3.2)
#
#PROJECT(geometry)
#设置目录
#include_directories("/usr/local/include/eigen3")
#
#add_executable(Geometry useGeometry.cpp)
