cmake_minimum_required(VERSION 3.22.2)
project(robot VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/lib
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRC
    ${PROJECT_SOURCE_DIR}/lib/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
                           
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)

#set(CMAKE_CXX_FLAGS "--std=c++14")
#set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++")
#set(CMAKE_CXX_COMPILER "D:\\msys64\\mingw64\\bin\\g++")
