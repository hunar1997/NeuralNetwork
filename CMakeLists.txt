cmake_minimum_required(VERSION 3.9.1)

project(NeuralNetwork)

add_definitions(-g)
add_definitions(-O0)
add_definitions(-Wall)

add_executable(NeuralNetwork Testing.cpp)
