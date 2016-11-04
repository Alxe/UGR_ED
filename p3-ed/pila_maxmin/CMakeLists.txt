cmake_minimum_required(VERSION 3.6)
project(pila_maxmin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/VD.h
    include/VD.cpp
    src/VD_test.cpp)

include_directories(./src ./include)

add_executable(pila_maxmin ${SOURCE_FILES})