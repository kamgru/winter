#include "Renderer.h"
#include "glad/glad.h"

glm::mat3 calculateNormalMatrix(glm::mat4 modelMatrix) {
    return glm::transpose(
            glm::inverse(
                    glm::mat3(modelMatrix)));
}

void winter::Renderer::Render(const winter::Mesh &mesh,
                              const winter::ShaderProgram &shaderProgram,
                              const winter::Texture2d &texture2D,
                              const glm::mat4& modelMatrix,
                              const glm::mat4& viewMatrix,
                              const glm::mat4& projectionMatrix,
                              const winter::Camera& camera) {
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture2D.getTextureId());

    shaderProgram.use();
    shaderProgram.SetUniformMatrix4("u_model", modelMatrix);
    shaderProgram.SetUniformMatrix3("u_normal", calculateNormalMatrix(modelMatrix));
    shaderProgram.SetUniformMatrix4("u_view", viewMatrix);
    shaderProgram.SetUniformMatrix4("u_projection", projectionMatrix);
    shaderProgram.SetUniformVector3("u_lightpos", glm::vec3(5.0f, 3.0f, 0.0f));
    shaderProgram.SetUniformVector3("u_campos", camera.GetPosition());

    glBindVertexArray(mesh.getVertexArrayObjectId());
    glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, nullptr);
}
