#ifndef WINTER_SPRITE_RENDERER_H
#define WINTER_SPRITE_RENDERER_H

#include <memory>
#include "camera.h"

namespace winter {

    class sprite_component;

    class sprite_renderer {
    public:
        sprite_renderer(camera cam);
        void render(std::shared_ptr<sprite_component> spr_comp);

    private:
        camera m_cam;
    };
}

#endif
