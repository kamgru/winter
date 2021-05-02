#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "shader_program.h"
#include "texture2d.h"
#include "camera.h"
#include "mesh.h"
#include "sprite_component.h"
#include "actor.h"

int main() {

    winter::window wnd(800, 600, "winter");
    wnd.create();

    std::shared_ptr<winter::texture2d> tex_ptr(new winter::texture2d());
    tex_ptr->from_file("../assets/textures/test_tiles.png");

    winter::camera cam(800, 600);

    winter::sprite spr(tex_ptr, {32, 0, 32, 32});
    winter::sprite_component spr_comp;
    spr_comp.sprite(spr);

    winter::sprite spr2(tex_ptr, { 64, 0, 64, 64});
    winter::sprite_component spr_comp2;
    spr_comp2.sprite(spr2);

    winter::actor act;
    act.transform().position(glm::vec3(400.0f, 300.0f, 0.0f));
    act.transform().scale(glm::vec3(32.0f, 32.0f, 0.0f));

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(400.0f, 300.0f, 0.0f));
    model = glm::scale(model, glm::vec3(32.0f, 32.0f, 0.0f));

    glm::mat4 model1(1.0f);
    model1 = glm::translate(model1, glm::vec3(464.0f, 300.0f, 0.0f));
    model1 = glm::scale(model1, glm::vec3(64.0f, 64.0f, 0.0f));



    while(!wnd.should_close()){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        spr_comp.render(model, cam.view(), cam.projection());
        spr_comp2.render(model1, cam.view(), cam.projection());

        wnd.swap_buffers();
        glfwPollEvents();
    }

    return 0;
}
