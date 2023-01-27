
cmake_minimum_required(VERSION 3.22.2)
project(search VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/duplicates
)

file(GLOB SOURCE
  ${PROJECT_SOURCE_DIR}/findMaxElem/exhaustiveSearch.cpp
)

file(GLOB SOURCE2
  ${PROJECT_SOURCE_DIR}/findMaxElem/sorting.cpp
)

add_executable(
    max_search ${SOURCE}
)
add_executable(
    max_sorting ${SOURCE2}
)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR intel)