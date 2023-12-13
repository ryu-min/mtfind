cmake_minimum_required(VERSION 3.5)

project(mtfind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mtfind
    src/main.cpp
    src/patterns.cpp
    src/findpatterns.cpp
    )
target_include_directories(mtfind PRIVATE src)
