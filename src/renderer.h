#ifndef WINTER_RENDERER_H
#define WINTER_RENDERER_H

#include "texture2d.h"
#include "shader_program.h"
#include "mesh.h"
#include "glm/glm.hpp"

namespace winter {
    class renderer {
    public:
        void render(
                texture2d const &texture,
                shader_program const &program,
                mesh const &mesh,
                glm::mat4 model,
                glm::mat4 view,
                glm::mat4 projection);
    };
}

#endif
