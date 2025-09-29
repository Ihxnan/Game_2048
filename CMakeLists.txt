cmake_minimum_required(VERSION 3.10)

project(MyProject)

# set(SOURCES main.cpp)

file(GLOB SOURCES "*.cpp")

add_executable(a.out ${SOURCES})
