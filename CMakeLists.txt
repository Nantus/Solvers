cmake_minimum_required(VERSION 3.5)
project(Solver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RungeKutta4.cpp RungeKutta4.h CError.cpp CError.h Euler1.cpp Euler1.h TextEncoder.cpp TextEncoder.h mainConstants.h DTree.h DTree.cpp)
add_executable(Solver ${SOURCE_FILES})