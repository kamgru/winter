#include "Sprite.h"

using namespace winter;

void create_uv_rect(
        rect &uv_rect,
        rect const &src_rect,
        std::shared_ptr<Texture2d> const &tex_ptr){

    glm::vec2 tex_size = tex_ptr->getSize();
    uv_rect = {
            (float)src_rect.x / tex_size.x,
            (float)src_rect.y / tex_size.y,
            (float)src_rect.w / tex_size.x,
            (float)src_rect.h / tex_size.y
    };
}

Sprite::Sprite(const std::shared_ptr<Texture2d>& tex_ptr, winter::rect src)
    : _sourceRect(src), _texture(tex_ptr) {
    SetTexture(tex_ptr);
}

std::shared_ptr<Texture2d> Sprite::getTexture() {
    return _texture;
}

rect Sprite::getSourceRect() {
    return _sourceRect;
}

void Sprite::SetTexture(std::shared_ptr<Texture2d> tex_ptr) {
    _texture = tex_ptr;
    if (tex_ptr) {
        create_uv_rect(_uvRect, _sourceRect, tex_ptr);
    }
}

rect Sprite::getUvRect() {
    return _uvRect;
}
