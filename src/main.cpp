#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "quad.h"
#include "shader_program.h"
#include "texture2d.h"
#include "camera.h"
#include "sprite.h"

int main() {

    winter::window wnd(800, 600, "winter");
    wnd.create();

    std::shared_ptr<winter::texture2d> tex_ptr(new winter::texture2d());
    tex_ptr->from_file("../assets/textures/wall.jpg");

    winter::sprite spr(tex_ptr, glm::vec2(256.0f, 256.0f));
    winter::sprite spr2(tex_ptr, glm::vec2(64.0f, 64.0f));

    winter::camera cam(800, 600);

    while(!wnd.should_close()){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        spr.draw(cam, glm::vec2(400.0f, 300.0f));
        spr2.draw(cam, glm::vec2(32.0f, 32.0f));

        wnd.swap_buffers();
        glfwPollEvents();
    }

    return 0;
}
