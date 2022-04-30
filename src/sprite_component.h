#ifndef WINTER_SPRITE_COMPONENT_H
#define WINTER_SPRITE_COMPONENT_H

#include "Sprite.h"
#include "ShaderProgram.h"
#include "Mesh.h"

namespace winter {
    class sprite_component {
    public:
        sprite_component();
        void sprite(Sprite sprite);
        void render(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
    private:
        winter::Sprite m_sprite {nullptr, {0, 0, 0, 0}};
        std::shared_ptr<ShaderProgram> m_program;
        std::unique_ptr<Mesh> m_mesh;
    };
}


#endif
