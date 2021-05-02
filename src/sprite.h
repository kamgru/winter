#ifndef WINTER_SPRITE_H
#define WINTER_SPRITE_H

#include "texture2d.h"
#include "quad.h"
#include "shader_program.h"
#include "camera.h"
#include <memory>

namespace winter {
    class sprite {
    public:
        sprite(std::shared_ptr<texture2d> tex_ptr, glm::vec2 size);
        ~sprite();
        void draw(camera cam, glm::vec2 pos);

    private:
        std::shared_ptr<texture2d> m_tex_ptr;
        quad m_quad;
        shader_program m_program;
    };
}

#endif
