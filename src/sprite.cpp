#include "sprite.h"

using namespace winter;

void create_uv_rect(
        rect &uv_rect,
        rect const &src_rect,
        std::shared_ptr<texture2d> const &tex_ptr){

    glm::vec2 tex_size = tex_ptr->size();
    uv_rect = {
            (float)src_rect.x / tex_size.x,
            (float)src_rect.y / tex_size.y,
            (float)src_rect.w / tex_size.x,
            (float)src_rect.h / tex_size.y
    };
}

sprite::sprite(std::shared_ptr<texture2d> tex_ptr, winter::rect src)
    : m_src_rect(src), m_tex_ptr(tex_ptr) {
    texture(tex_ptr);
}

std::shared_ptr<texture2d> sprite::texture() {
    return m_tex_ptr;
}

rect sprite::src_rect() {
    return m_src_rect;
}

void sprite::texture(std::shared_ptr<texture2d> tex_ptr) {
    m_tex_ptr = tex_ptr;
    if (tex_ptr) {
        create_uv_rect(m_uv_rect, m_src_rect, tex_ptr);
    }
}

rect sprite::uv_rect() {
    return m_uv_rect;
}
