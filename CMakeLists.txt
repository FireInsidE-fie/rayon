cmake_minimum_required(VERSION 3.22)
project(rayon)

set(CMAKE_CXX_STANDARD 23)

add_executable(rayon main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h)

target_compile_options(rayon PRIVATE -Wall -Wextra -Wpedantic)
