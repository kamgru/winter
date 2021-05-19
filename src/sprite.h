#ifndef WINTER_SPRITE_H
#define WINTER_SPRITE_H

#include "rect.h"
#include <memory>
#include "resource_manager.h"

namespace winter {

    class texture2d;

    class sprite {
    public:
        sprite(std::shared_ptr<texture2d> tex_ptr, rect src);
        std::shared_ptr<texture2d> texture();
        void texture(std::shared_ptr<texture2d> tex_ptr);
        rect src_rect();
        rect uv_rect();
    private:
        std::shared_ptr<texture2d> m_tex_ptr = nullptr;
        res_handle<texture2d> m_tex_hnd;
        rect m_src_rect = {};
        rect m_uv_rect = {};
    };
}

#endif
