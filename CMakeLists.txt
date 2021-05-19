cmake_minimum_required(VERSION 3.19)
project(winter)

set(CMAKE_CXX_STANDARD 11)
add_executable(winter
        ext/glad.c
        ext/stb_image.cpp
        src/main.cpp
        src/window.cpp
        src/window.h
        src/shader_program.cpp
        src/shader_program.h
        src/file_io.cpp
        src/file_io.h
        src/texture2d.cpp
        src/texture2d.h
        src/camera.cpp
        src/camera.h
        src/sprite.cpp
        src/sprite.h
        src/rect.h
        src/mesh.cpp
        src/mesh.h
        src/component.h
        src/actor.h
        src/sprite_component.cpp
        src/sprite_component.h
        src/sprite_renderer.cpp
        src/sprite_renderer.h
        src/transform_component.h src/actor.cpp src/renderer.cpp src/renderer.h src/material.cpp src/material.h src/resource_manager.cpp src/resource_manager.h)

target_include_directories(winter PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(winter PUBLIC opengl32.lib)
target_link_libraries(winter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3.lib)
