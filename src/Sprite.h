#ifndef WINTER_SPRITE_H
#define WINTER_SPRITE_H

#include "Texture2d.h"
#include "rect.h"
#include <memory>

namespace winter {
    class Sprite {
    public:
        Sprite(const std::shared_ptr<Texture2d>& tex_ptr, rect src);
        std::shared_ptr<Texture2d> getTexture();
        void SetTexture(std::shared_ptr<Texture2d> tex_ptr);
        rect getSourceRect();
        rect getUvRect();
    private:
        std::shared_ptr<Texture2d> _texture;
        rect _sourceRect = {};
        rect _uvRect = {};
    };
}

#endif
