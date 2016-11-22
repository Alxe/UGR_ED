cmake_minimum_required(VERSION 3.6)
project(pila_maxmin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES
        src/pila_maxmin.cpp
        src/pila_maxmin_vd.cpp
        src/usopilas_max.cpp)

include_directories(./src ./include)

add_executable(pila_maxmin ${SOURCE_FILES})