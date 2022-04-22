#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "ShaderProgram.h"
#include "Texture2d.h"
#include "camera.h"
#include "Mesh.h"
#include "sprite_component.h"
#include "Renderer.h"
#include <chrono>

int main() {

    winter::window wnd(800, 600, "winter");
    wnd.create();

    std::shared_ptr<winter::Texture2d> texture = winter::Texture2d::loadFromFile("../assets/textures/test_tiles.png");

    winter::camera cam(800, 600);

//    winter::Sprite spr(texture, {32, 0, 32, 32});
//    winter::sprite_component spr_comp;
//    spr_comp.sprite(spr);
//
//    winter::Sprite spr2(texture, {64, 0, 64, 64});
//    winter::sprite_component spr_comp2;
//    spr_comp2.sprite(spr2);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(400.0f, 300.0f, 0.0f));
    //model = glm::rotate(model, 10.0f, glm::vec3(0, 1, 0));
    model = glm::scale(model, glm::vec3(64.0f, 64.0f, 0.0f));

    std::unique_ptr<winter::Mesh> mesh = winter::Mesh::createCube();

    auto shaderProgram = winter::ShaderProgram::loadFromFile(
            "../assets/shaders/unlit.vert",
            "../assets/shaders/unlit.frag");

//    glm::mat4 model1(1.0f);
//    model1 = glm::translate(model1, glm::vec3(464.0f, 300.0f, 0.0f));
//    model1 = glm::scale(model1, glm::vec3(64.0f, 64.0f, 0.0f));

    winter::Renderer renderer;

    auto start = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);

    while(!wnd.should_close()){

        dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        start = std::chrono::steady_clock::now();
        float elapsed = (dt.count() / 60.0f);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        model = glm::rotate(model, .05f * elapsed, glm::vec3(0.25, 1, 0));


        renderer.Render(
                *mesh,
                *shaderProgram,
                *texture,
                model,
                cam.view(),
                cam.projection());

//        spr_comp.render(model, cam.view(), cam.projection());
//        spr_comp2.render(model1, cam.view(), cam.projection());

        wnd.swap_buffers();
        glfwPollEvents();


    }

    return 0;
}