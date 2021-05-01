#include "quad.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace winter;

const float VERTICES[] = {
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
};
const size_t VERTEX_ARRAY_SIZE = 20 * sizeof(float);
const GLsizei VERTEX_ARRAY_STRIDE = 5 * sizeof(float);
const void* POSITION_PTR = (void*)(0);
const void* TEXCOORD_PTR = (void*)(3 * sizeof(float));

const unsigned int INDICES[] {
        0, 1, 3,
        1, 2, 3
};
const size_t ELEMENT_BUFFER_SIZE = 6 * sizeof(unsigned int);
const GLsizei ELEMENT_BUFFER_LEN = 6;

quad::quad() {
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
}

quad::~quad() {
    glDeleteBuffers(1, &m_ebo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void quad::draw() {
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, ELEMENT_BUFFER_LEN, GL_UNSIGNED_INT, 0);
}
