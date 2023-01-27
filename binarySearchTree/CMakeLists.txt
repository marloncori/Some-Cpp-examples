
cmake_minimum_required(VERSION 3.22.2)
project(binarySearchTree VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
   ${PROJECT_SOURCE_DIR}/lib
   ${PROJECT_SOURCE_DIR}/src
)

file(GLOB ALL_SRCS
   ${PROJECT_SOURCE_DIR}/lib/*.h
   ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(
   ${PROJECT_NAME} ${ALL_SRCS}
)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++")