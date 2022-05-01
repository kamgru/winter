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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::GetPositionPointer());
    glEnableVertexAttribArray(0);

    glad_glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::GetNormalPointer());
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), vertex::GetUvPointer());
    glEnableVertexAttribArray(2);
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
            /*0*/{ glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
            /*1*/{ glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
            /*2*/{ glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
            /*3*/{ glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
    };

    std::vector<unsigned int> indices = {0, 1, 2, 2, 3, 0};

    return std::make_unique<Mesh>(vertices, indices);
}

std::unique_ptr<Mesh> Mesh::createCube() {
    std::vector<winter::vertex> vertices {

        /*          6----------7
         *         /|         /|
         *        3----------2 |
         *        | |        | |
         *        | 5 -------|-4
         *        |/         |/
         *        0----------1
         */
            //front
            /*0*/{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
            /*1*/{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
            /*2*/{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
            /*3*/{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},

            //back
            /*4*/{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f)},
            /*5*/{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f)},
            /*6*/{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f)},
            /*7*/{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f)},

            //left
            /*0(8)*/{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
            /*3(9)*/{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
            /*6(10)*/{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
            /*5(11)*/{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

            //right
            /*1(12)*/{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
            /*4(13)*/{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
            /*7(14)*/{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
            /*2(15)*/{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

            //top
            /*3(16)*/{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
            /*2(17)*/{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
            /*7(18)*/{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
            /*6(19)*/{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

            //bottom
            /*1(20)*/{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
            /*0(21)*/{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
            /*5(22)*/{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
            /*4(23)*/{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},

    };

    std::vector<unsigned int> indices = {
            //front
            0, 1, 2, 2, 3, 0,
            //back
            4, 5, 6, 6, 7, 4,
            //left
            8, 9, 10, 10, 11, 8,
            // right
            12, 13, 14, 14, 15, 12,
            //top
            16, 17, 18, 18, 19, 16,
            //bottom
            20, 21, 22, 22, 23, 20
    };

    return std::make_unique<Mesh>(vertices, indices);
}