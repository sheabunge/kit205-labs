cmake_minimum_required(VERSION 3.8)
project(week4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c bst.c bst.h)
add_executable(week4 ${SOURCE_FILES})