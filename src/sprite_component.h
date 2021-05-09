#ifndef WINTER_SPRITE_COMPONENT_H
#define WINTER_SPRITE_COMPONENT_H

#include "component.h"
#include "sprite.h"
#include "shader_program.h"
#include "mesh.h"

namespace winter {

    class sprite_component : public component {
    public:
        sprite_component(actor *owner);
        void sprite(sprite sprite);
        winter::sprite& sprite() { return m_sprite; };
        shader_program& program() { return m_program; };
        mesh& mesh() { return m_mesh; };
    private:
        winter::sprite m_sprite {nullptr, {0, 0, 0, 0}};
        shader_program m_program;
        winter::mesh m_mesh;
    };
}


#endif
