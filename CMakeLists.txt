cmake_minimum_required(VERSION 3.1)
project(Hybrid_Quicksort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hybrid_Quicksort
        hoare.cpp
        hoare.h
        lomuto.cpp
        lomuto.h
        m5.cpp
        m5.h
        hf.cpp
        hf.h
        shell.cpp
        shell.h)
