#include "renderer.h"

using namespace winter;

void renderer::render(
        texture2d const& texture,
        shader_program const& program,
        mesh const& mesh,
        glm::mat4 model,
        glm::mat4 view,
        glm::mat4 projection){

    texture.use();
    program.use();
    program.set_uniform_mat4("u_model", model);
    program.set_uniform_mat4("u_view", view);
    program.set_uniform_mat4("u_projection", projection);
    mesh.render();
}
