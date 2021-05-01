#ifndef BASOKO_WINDOW_H
#define BASOKO_WINDOW_H

#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace winter {
    class window {
    public:
        window(int width, int height, std::string title);
        ~window();
        void create();
        bool should_close();
        void swap_buffers();
    private:
        int m_width;
        int m_height;
        std::string m_title;
        GLFWwindow *m_window{};
    };
}

#endif
