#ifndef WINTER_SPRITE_COMPONENT_H
#define WINTER_SPRITE_COMPONENT_H

#include "component.h"
#include "sprite.h"
#include "shader_program.h"
#include "mesh.h"

namespace winter {
    class sprite_component : public component {
    public:
        sprite_component();
        void sprite(sprite sprite);
        void render(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
    private:
        winter::sprite m_sprite {nullptr, {0, 0, 0, 0}};
        shader_program m_program;
        mesh m_mesh;
    };
}


#endif
