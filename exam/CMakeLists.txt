cmake_minimum_required(VERSION 3.10)
project(exam C)

set(CMAKE_C_STANDARD 99)

add_executable(exam main.c questions.h questions.c list.h bst.h graph.h list.c bst.c graph.c)

add_executable(sort sort.c)
