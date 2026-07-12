cmake_minimum_required(VERSION 3.10)
project(MetaSource)

add_executable(MetaSource 
    src/main.cpp 
    src/core/engine.cpp
    src/renderer/shader.cpp
    src/renderer/camera.cpp
    src/renderer/texture.cpp
    src/renderer/shapes.cpp
    src/renderer/mesh.cpp
    src/renderer/lighting.cpp
    extras/imgui/imgui.cpp
    extras/imgui/imgui_demo.cpp
    extras/imgui/imgui_draw.cpp
    extras/imgui/imgui_tables.cpp
    extras/imgui/imgui_widgets.cpp
    extras/imgui/backends/imgui_impl_sdl2.cpp
    extras/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(MetaSource PRIVATE ${CMAKE_SOURCE_DIR}/extras/glm)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(MetaSource 
    PRIVATE
    OpenGL::GL
    SDL2::SDL2
    GLEW::GLEW
)
target_include_directories(MetaSource PRIVATE 
    ${CMAKE_SOURCE_DIR}/extras/glm
    ${CMAKE_SOURCE_DIR}/extras/imgui          # Tells the compiler where to find imgui.h
    ${CMAKE_SOURCE_DIR}/extras/imgui/backends # Tells the compiler where to find backend headers
)