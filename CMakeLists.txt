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
        src/quad.cpp
        src/quad.h src/texture2d.cpp src/texture2d.h)

target_include_directories(winter PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(winter PUBLIC opengl32.lib)
target_link_libraries(winter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3.lib)
