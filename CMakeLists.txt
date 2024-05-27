cmake_minimum_required(VERSION 3.27.4)
project(OS_2_Project C)

set(CMAKE_C_STANDARD 23)

add_library(OS_2_Project STATIC src/vladutz_lib.c
        include/memory_management/memory_management.h)
