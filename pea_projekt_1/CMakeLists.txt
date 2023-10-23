cmake_minimum_required(VERSION 3.25)
project(pea_projekt_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(pea_projekt_1 main.cpp BruteForce.cpp BruteForce.h Matrix.cpp Matrix.h Dynamic.cpp Dynamic.h)
