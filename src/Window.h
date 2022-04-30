#ifndef WINTER_WINDOW_H
#define WINTER_WINDOW_H

#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Camera.h"

namespace winter {
    class Window {
    public:
        Window(int width, int height, std::string title);
        ~Window();
        void Create();
        bool ShouldClose();
        void SwapBuffers();
        GLFWwindow* GetGlfwWindow() { return _glfwWindow; }
        glm::vec2 GetSize() const { return {_width, _height};}
    private:
        int _width;
        int _height;
        std::string _title;
        GLFWwindow *_glfwWindow{};
    };
}

#endif
