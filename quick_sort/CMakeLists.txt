cmake_minimum_required(VERSION 3.22.2)
project(quick_sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB ALL_SRCS
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(quickSort ${ALL_SRCS})
                           #${PROJECT_NAME}.cpp)
#target_link_libraries(matrix_test qbMatrix2)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)

#set(CMAKE_CXX_FLAGS "--std=c++14")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++")
