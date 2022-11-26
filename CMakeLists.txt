cmake_minimum_required(VERSION 3.23)
set(PROJECT_NAME find_app)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

add_executable(${PROJECT_NAME} main.cpp)

