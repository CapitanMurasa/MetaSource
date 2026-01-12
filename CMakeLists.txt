cmake_minimum_required(VERSION 3.10)
project(MetaSource LANGUAGES CXX C)


set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

set(SOURCES
    src/main.cpp)

add_executable(MetaSource ${SOURCES})

target_link_libraries(MetaSource PRIVATE SDL2::SDL2 SDL2::SDL2main)