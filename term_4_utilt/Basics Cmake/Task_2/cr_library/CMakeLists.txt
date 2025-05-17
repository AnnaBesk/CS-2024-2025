cmake_minimum_required(VERSION 3.20)
project(CubeProject)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_library(cube main.cpp cube.cpp cube.hpp)