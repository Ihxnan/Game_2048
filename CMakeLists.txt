cmake_minimum_required(VERSION 3.10)

project(MyProject)

# set(SOURCES main.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(2048 ${SOURCES})
