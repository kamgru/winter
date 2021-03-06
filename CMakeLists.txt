cmake_minimum_required(VERSION 3.19)
project(winter)
set(CMAKE_CXX_STANDARD 11)
add_executable(winter
        ext/glad.c
        ext/stb_image.cpp
        src/main.cpp
        src/Window.cpp
        src/Window.h
        src/ShaderProgram.cpp
        src/ShaderProgram.h
        src/file_io.cpp
        src/file_io.h
        src/Texture2d.cpp
        src/Texture2d.h
        src/Camera.cpp
        src/Camera.h
        src/Sprite.cpp
        src/Sprite.h
        src/rect.h
        src/Mesh.cpp
        src/Mesh.h
        src/sprite_component.cpp
        src/sprite_component.h src/Renderer.cpp src/Renderer.h)

target_include_directories(winter PUBLIC ${CMAKE_SOURCE_DIR}/include/)
if (WIN32)
    target_link_libraries(winter PUBLIC opengl32.lib)
    target_link_libraries(winter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3_win32.lib)
endif()
if (UNIX)
    target_link_libraries(winter PUBLIC libGL.so)
    target_link_libraries(winter PUBLIC libXrandr.so)
    target_link_libraries(winter PUBLIC libXi.so)
    target_link_libraries(winter PUBLIC libdl.so)
    target_link_libraries(winter PUBLIC ${CMAKE_DL_LIBS})
    target_link_libraries(winter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/libglfw3.a)
    target_link_libraries(winter PUBLIC libpthread.so)
    target_link_libraries(winter PUBLIC libX11.so)

endif()