cmake_minimum_required(VERSION 3.9.1)

project(NeuralNetwork)

set(CMAKE_BUILD_TYPE Debug)
add_definitions(-O0)
add_definitions(-Wall)
set(CMAKE_CXX_STANDARD 17)

add_executable(NeuralNetwork Testing.cpp)
