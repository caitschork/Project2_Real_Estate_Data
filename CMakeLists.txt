cmake_minimum_required(VERSION 3.30)
project(Project2b)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project2b main.cpp
        DataLoader.h
        DataLoader.cpp
        HeapSort.cpp)
