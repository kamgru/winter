#include "Mesh.h"
#include "glad/glad.h"

using namespace winter;

Mesh::Mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices) {

    glGenVertexArrays(1, &_vertexArrayObjectId);
    glBindVertexArray(_vertexArrayObjectId);

    glGenBuffers(1, &_vertexBufferObjectId);
    Mesh::setVertices(vertices);

    glGenBuffers(1, &_elementBufferObjectId);
    Mesh::setIndices(indices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::pos_ptr());
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::uv_ptr());
    glEnableVertexAttribArray(1);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &_elementBufferObjectId);
    glDeleteBuffers(1, &_vertexBufferObjectId);
    glDeleteVertexArrays(1, &_vertexArrayObjectId);
}

void Mesh::setVertices(std::vector<vertex> vertices) {
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObjectId);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);
    _vertices = vertices;
}

void Mesh::setIndices(std::vector<unsigned int> indices) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObjectId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    _indices = indices;
}

std::unique_ptr<Mesh> Mesh::createQuad() {

    std::vector<winter::vertex> vertices {
            { glm::vec3(0.5f, 0.5f, 0.0f), glm::vec2(1.0f, 1.0f)},
            { glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)},
            { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
            { glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0f, 1.0f)},
    };

    std::vector<unsigned int> indices = {0, 1, 3, 1, 2, 3};

    return std::make_unique<Mesh>(vertices, indices);
}

std::unique_ptr<Mesh> Mesh::createCube() {
    std::vector<winter::vertex> vertices {
            { glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)},
            { glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)},
            { glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)},
            { glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)},

            { glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
            { glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)},
            { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)},
            { glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
    };

    std::vector<unsigned int> indices = {0, 1, 3, 1, 2, 3, 4, 5, 0, 5, 1, 0, 7, 6, 4, 6, 5, 4};

    return std::make_unique<Mesh>(vertices, indices);
}