cmake_minimum_required(VERSION 3.20)

project(Morphogen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)

add_executable(Morphogen
    src/application/main.cpp
    src/engine/core/Engine.cpp
    src/render/opengl/Renderer.cpp
    src/render/opengl/Window.cpp
)

target_include_directories(Morphogen PRIVATE
    src/engine/core
    src/render/opengl
)

target_link_libraries(Morphogen PRIVATE glfw)