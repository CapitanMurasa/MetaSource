cmake_minimum_required(VERSION 3.10)
project(MetaSource)


find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})


add_executable(MetaSource 
    src/main.cpp 
    src/renderer/shader.cpp
)


target_link_libraries(MetaSource 
    PRIVATE 
    SDL2::SDL2 
    ${OPENGL_LIBRARIES} 
    ${GLEW_LIBRARIES}
)