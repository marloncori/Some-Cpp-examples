
cmake_minimum_required(VERSION 3.22.2)
project(readFile VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRC1 
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
)

add_executable(
    read ${SRC1})

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)