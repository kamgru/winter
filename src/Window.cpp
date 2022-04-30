#include <iostream>
#include "Window.h"

using namespace winter;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

Window::Window(int width, int height, std::string title)
    : _width(width), _height(height), _title(std::move(title)){
}

Window::~Window() {
    glfwTerminate();
}

void Window::Create() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _glfwWindow = glfwCreateWindow(
            _width,
            _height,
            _title.c_str(),
            nullptr,
            nullptr);

    if (_glfwWindow == nullptr)
    {
        std::cout << "Failed to Create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(_glfwWindow);
    glfwSetFramebufferSizeCallback(_glfwWindow, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return;
    }

    glfwSetInputMode(_glfwWindow, GLFW_STICKY_KEYS, GLFW_TRUE);
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(_glfwWindow);
}

void Window::SwapBuffers() {
    glfwSwapBuffers(_glfwWindow);
}