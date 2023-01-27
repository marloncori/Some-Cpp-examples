
cmake_minimum_required(VERSION 3.22.2)
project(selection_sort VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(PROJ_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message(" --> Build type: " ${CMAKE_BUILD_TYPE})

enable_language(C CXX ASM)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/lib
)    
# add this one instead, if CMakeLists.txt
# is the same folder as the .cpp files:
# target_include_directories( ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}.c
    ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}_main.c
)
# or
#set(SOURCES src/main.c src/${PROJECT_NAME}.c)
add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)

set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc")