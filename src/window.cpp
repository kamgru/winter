#include <iostream>
#include <utility>
#include "window.h"

using namespace winter;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

window::window(int width, int height, std::string title)
    : m_width(width), m_height(height), m_title(std::move(title)){
}

window::~window() {
    glfwTerminate();
}

void window::create() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(
            m_width,
            m_height,
            m_title.c_str(),
            nullptr,
            nullptr);

    if (m_window == nullptr)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return;
    }
}

bool window::should_close() {
    return glfwWindowShouldClose(m_window);
}

void window::swap_buffers() {
    glfwSwapBuffers(m_window);
}
