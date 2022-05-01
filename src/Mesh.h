#ifndef WINTER_MESH_H
#define WINTER_MESH_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>
#include <memory>

namespace winter {

    typedef unsigned int VertexArrayObjectId;
    typedef unsigned int VertexBufferObjectId;
    typedef unsigned int ElementBufferObjectId;

    struct vertex{
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;

        static void* GetPositionPointer() {
            return nullptr;
        }

        static void* GetNormalPointer() {
            return (void*)sizeof(position);
        }

        static void* GetUvPointer() {
            return (void*)(sizeof(position) + sizeof(normal));
        }
    };

    class Mesh {
    public:
        Mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices);
        ~Mesh();

        std::vector<vertex> GetVertices() const { return _vertices; }
        void setVertices(std::vector<vertex> vertices);
        int getIndexCount() const {return (int)_indices.size(); }
        void setIndices(std::vector<unsigned int> indices);
        VertexArrayObjectId getVertexArrayObjectId() const { return _vertexArrayObjectId; }

        static std::unique_ptr<Mesh> createQuad();
        static std::unique_ptr<Mesh> createCube();
    private:
        VertexArrayObjectId _vertexArrayObjectId{};
        VertexBufferObjectId _vertexBufferObjectId{};
        ElementBufferObjectId _elementBufferObjectId{};
        std::vector<vertex> _vertices;
        std::vector<unsigned int> _indices;
    };
}

#endif
