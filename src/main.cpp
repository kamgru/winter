#include <iostream>
#include <stb/stb_image.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "quad.h"
#include "shader_program.h"
#include "texture2d.h"

int main() {

    winter::window wnd(800, 600, "winter");
    wnd.create();

    winter::texture2d tex;
    tex.from_file("../assets/textures/metal.jpg");

    winter::shader_program prog;
    prog.attach_shader_file(winter::SHADER_TYPE_VERTEX, "../assets/shaders/unlit.vert");
    prog.attach_shader_file(winter::SHADER_TYPE_FRAGMENT, "../assets/shaders/unlit.frag");

    winter::quad q;

    while(!wnd.should_close()){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        tex.use();
        prog.use();

        q.draw();

        wnd.swap_buffers();
        glfwPollEvents();
    }

    return 0;
}
