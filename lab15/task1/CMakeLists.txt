cmake_minimum_required(VERSION 3.17)
project(task1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(task1
        src/lib.c
        src/lib.h
        src/main.c)
