#include "sprite_component.h"

using namespace winter;

std::vector<winter::vertex> vertices {
        { glm::vec3(0.5f, 0.5f, 0.0f), glm::vec2(1.0f, 1.0f)},
        { glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)},
        { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
        { glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0f, 1.0f)},
};

std::vector<unsigned int> indices = {0, 1, 3, 1, 2, 3};

void winter::sprite_component::render(glm::mat4 model, glm::mat4 view, glm::mat4 projection) {
    if (m_sprite.texture() == nullptr) {
        return;
    }
    m_sprite.texture()->use();
    m_program.use();
    m_program.set_uniform_mat4("u_model", model);
    m_program.set_uniform_mat4("u_view", view);
    m_program.set_uniform_mat4("u_projection", projection);
    m_mesh.render();
}

sprite_component::sprite_component()
    : m_mesh(vertices, indices) {
    m_program.attach_shader_file(SHADER_TYPE_VERTEX, "../assets/shaders/unlit.vert");
    m_program.attach_shader_file(SHADER_TYPE_FRAGMENT, "../assets/shaders/unlit.frag");
}

void sprite_component::sprite(winter::sprite sprite) {
    m_sprite = sprite;

    rect uv_rect = m_sprite.uv_rect();
    vertices[0].uv = glm::vec2(uv_rect.x + uv_rect.w, uv_rect.y + uv_rect.h);
    vertices[1].uv = glm::vec2(uv_rect.x + uv_rect.w, uv_rect.y);
    vertices[2].uv = glm::vec2(uv_rect.x, uv_rect.y);
    vertices[3].uv = glm::vec2(uv_rect.x, uv_rect.y + uv_rect.h);

    m_mesh.vertices(vertices);
}
