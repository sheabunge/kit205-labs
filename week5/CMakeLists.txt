cmake_minimum_required(VERSION 3.8)
project(week5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES list.h list.c hashtable.h hashtable.c main.c)
add_executable(week5 ${SOURCE_FILES})