cmake_minimum_required(VERSION 3.8)
project(week2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES list.c list.h)
add_executable(menu ${SOURCE_FILES} menu.c)
add_executable(merge_test ${SOURCE_FILES} merge_test.c)