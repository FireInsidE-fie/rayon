cmake_minimum_required(VERSION 3.31)
project(rayon)

set(CMAKE_CXX_STANDARD 23)

add_executable(rayon main.cpp
        vec3.h
        color.h
        ray.h)

target_compile_options(rayon PRIVATE -Wall -Wextra -Wpedantic)
