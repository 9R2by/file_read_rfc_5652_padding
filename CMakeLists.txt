cmake_minimum_required(VERSION 3.26)
project(test2323 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_COMPILER "clang")
add_compile_options(-O3 -march=native -Wall -Wextra -Wpedantic)

add_executable(test2323 main.c)
