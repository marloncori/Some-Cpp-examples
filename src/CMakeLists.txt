
cmake_minimum_required(VERSION 3.22.2)
project(binary_search VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/lib
)    
# add this one instead, if CMakeLists.txt
# is the same folder as the .cpp files:
# target_include_directories( ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}_test.cpp
)

add_executable(${PROJECT_NAME}_test ${SOURCES})

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)

set(CMAKE_CXX_FLAGS "-Wall --std=c++17")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++")

