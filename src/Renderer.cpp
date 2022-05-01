#include "Renderer.h"
#include "glad/glad.h"

void winter::Renderer::Render(const winter::Mesh &mesh,
                              const winter::ShaderProgram &shaderProgram,
                              const winter::Texture2d &texture2D,
                              const glm::mat4& modelMatrix,
                              const glm::mat4& viewMatrix,
                              const glm::mat4& projectionMatrix) {
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture2D.getTextureId());

    shaderProgram.use();
    shaderProgram.SetUniformMatrix("u_model", modelMatrix);
    shaderProgram.SetUniformMatrix("u_view", viewMatrix);
    shaderProgram.SetUniformMatrix("u_projection", projectionMatrix);

    glBindVertexArray(mesh.getVertexArrayObjectId());
    glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, nullptr);
}
