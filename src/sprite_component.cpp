#include "sprite_component.h"

using namespace winter;

#include "Renderer.h"

Renderer renderer;

void winter::sprite_component::render(glm::mat4 model, glm::mat4 view, glm::mat4 projection) {
    if (m_sprite.getTexture() == nullptr) {
        return;
    }

    renderer.Render(
            *m_mesh,
            *m_program,
            *m_sprite.getTexture(),
            model,
            view,
            projection);
}

sprite_component::sprite_component() {

    m_mesh = Mesh::createQuad();
    m_program = ShaderProgram::loadFromFile(
            "../assets/shaders/unlit.vert",
            "../assets/shaders/unlit.frag");
}

void sprite_component::sprite(winter::Sprite sprite) {
    m_sprite = sprite;

    rect uv_rect = m_sprite.getUvRect();
    std::vector<vertex> vertices2 = m_mesh->getVertices();

    vertices2.at(0).uv = glm::vec2(uv_rect.x + uv_rect.w, uv_rect.y + uv_rect.h);
    vertices2.at(1).uv = glm::vec2(uv_rect.x + uv_rect.w, uv_rect.y);
    vertices2.at(2).uv = glm::vec2(uv_rect.x, uv_rect.y);
    vertices2.at(3).uv = glm::vec2(uv_rect.x, uv_rect.y + uv_rect.h);

    m_mesh->setVertices(vertices2);
}
