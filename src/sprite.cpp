#include "sprite.h"

using namespace winter;

sprite::sprite(std::shared_ptr<texture2d> tex_ptr, glm::vec2 size)
    : m_tex_ptr(tex_ptr) {
    m_quad.scale(size);
    m_program.attach_shader_file(SHADER_TYPE_VERTEX, "../assets/shaders/unlit.vert");
    m_program.attach_shader_file(SHADER_TYPE_FRAGMENT, "../assets/shaders/unlit.frag");
}

sprite::~sprite() {
}

void sprite::draw(camera cam, glm::vec2 pos) {
    m_quad.translate(pos);
    m_tex_ptr.get()->use();
    m_program.use();
    m_program.set_uniform_mat4("u_model", m_quad.model());
    m_program.set_uniform_mat4("u_view", cam.view());
    m_program.set_uniform_mat4("u_projection", cam.projection());
    m_quad.draw();
}
