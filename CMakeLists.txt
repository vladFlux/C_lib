cmake_minimum_required(VERSION 3.27.4)
project(OS_2_Project C)

set(CMAKE_C_STANDARD 23)

include_directories(include src)

file(GLOB SOURCES "src/*.c")

add_library(OS_2_Project STATIC ${SOURCES})
