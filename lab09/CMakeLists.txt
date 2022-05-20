cmake_minimum_required(VERSION 3.22)
project(labs C)

set(CMAKE_C_STANDARD 99)

add_executable(labs src/main.c test/test.c)
