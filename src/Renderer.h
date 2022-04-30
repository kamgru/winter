#ifndef WINTER_RENDERER_H
#define WINTER_RENDERER_H

#include "Mesh.h"
#include "ShaderProgram.h"
#include "Texture2d.h"

namespace winter{
    class Renderer {
    public:
        void Render(
                const Mesh& mesh,
                const ShaderProgram& shaderProgram,
                const Texture2d& texture2D,
                const glm::mat4& modelMatrix,
                const glm::mat4& viewMatrix,
                const glm::mat4& projectionMatrix);
    };

}
#endif //WINTER_RENDERER_H
