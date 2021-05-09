#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window.h"
#include "texture2d.h"
#include "camera.h"
#include "sprite_component.h"
#include "actor.h"
#include "sprite_renderer.h"

int main() {

    winter::window wnd(800, 600, "winter");
    wnd.create();

    std::shared_ptr<winter::texture2d> tex_ptr(new winter::texture2d());
    tex_ptr->from_file("../assets/textures/test_tiles.png");

    winter::camera cam(800, 600);

    std::shared_ptr<winter::actor> player = std::make_shared<winter::actor>();
    winter::sprite player_spr(tex_ptr, {0, 0, 32, 32});
    std::shared_ptr<winter::sprite_component>  player_spr_comp = player->add_component<winter::sprite_component>();
    player_spr_comp->sprite(player_spr);

    std::shared_ptr<winter::transform_component> player_transform = player->get_transform();

    player_transform->position(glm::vec3(400.0f, 300.0f, 0.0f));
    player_transform->scale(glm::vec3(player_spr.src_rect().w, player_spr.src_rect().h, 0.0f));

    winter::sprite_renderer renderer(cam);

    std::shared_ptr<winter::sprite_component> node;
    node = player->get_component<winter::sprite_component>();

    while(!wnd.should_close()){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.render(node);

        wnd.swap_buffers();
        glfwPollEvents();
    }

    return 0;
}
