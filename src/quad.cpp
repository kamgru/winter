#include "quad.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/gtc/matrix_transform.hpp"

using namespace winter;

const float VERTICES[] = {
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
};
const size_t VERTEX_ARRAY_SIZE = 20 * sizeof(float);
const GLsizei VERTEX_ARRAY_STRIDE = 5 * sizeof(float);
const void* POSITION_PTR = nullptr;
const void* TEXCOORD_PTR = (void*)(3 * sizeof(float));

const unsigned int INDICES[] {
        0, 1, 3,
        1, 2, 3
};
const size_t ELEMENT_BUFFER_SIZE = 6 * sizeof(unsigned int);
const GLsizei ELEMENT_BUFFER_LEN = 6;

quad::quad()
    : m_pos(glm::vec3(0.0f, 0.0f, 0.0f)),
    m_scale(glm::vec3(1.0f, 1.0f, 1.0f)),
    m_model(glm::mat4(1.0f)) {

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_ARRAY_SIZE, VERTICES, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_ARRAY_STRIDE, POSITION_PTR);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VERTEX_ARRAY_STRIDE, TEXCOORD_PTR);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ELEMENT_BUFFER_SIZE, INDICES, GL_STATIC_DRAW);

    m_model = glm::mat4(1.0f);
}

quad::~quad() {
    glDeleteBuffers(1, &m_ebo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void quad::draw() const {
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, ELEMENT_BUFFER_LEN, GL_UNSIGNED_INT, 0);
}

void quad::scale(glm::vec2 scale) {
    m_scale = glm::vec3(scale.x, scale.y, 0.0);
}

void quad::translate(glm::vec2 translation) {
    m_pos =  glm::vec3(-translation.x, translation.y, 0.0f);
}

glm::mat4 quad::model() {
    m_model = glm::mat4(1.0f);
    m_model = glm::translate(m_model, m_pos);
    m_model = glm::scale(m_model, m_scale);
    return m_model;
}
