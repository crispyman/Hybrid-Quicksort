cmake_minimum_required(VERSION 3.1)
project(Hybrid_Quicksort)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --Wl, --stack,116777216")


add_executable(Hybrid_Quicksort
        Main.cpp Main.h sort.h)
