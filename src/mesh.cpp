#include "mesh.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace winter;

mesh::mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices) {

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_vbo);
    mesh::vertices(vertices);

    glGenBuffers(1, &m_ebo);
    mesh::indices(indices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::pos_ptr());
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::uv_ptr());
    glEnableVertexAttribArray(1);
}

mesh::~mesh() {
    glDeleteBuffers(1, &m_ebo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void mesh::render() {
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
}

void mesh::vertices(std::vector<vertex> vertices) {
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
    m_vertices = vertices;
}

void mesh::indices(std::vector<unsigned int> indices) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    m_indices = indices;
}
