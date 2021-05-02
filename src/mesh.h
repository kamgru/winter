#ifndef WINTER_MESH_H
#define WINTER_MESH_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>

namespace winter {

    typedef unsigned int vao_t;
    typedef unsigned int vbo_t;
    typedef unsigned int ebo_t;

    struct vertex{
        glm::vec3 pos;
        glm::vec2 uv;

        static void* pos_ptr() {
            return nullptr;
        }

        static void* uv_ptr() {
            return (void*)sizeof(pos);
        }
    };

    class mesh {
    public:
        mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices);
        ~mesh();
        void render();
        const std::vector<vertex>* vertices() { return &m_vertices; }
        void vertices(std::vector<vertex> vertices);
        const std::vector<unsigned int>* indices() { return &m_indices; }
        void indices(std::vector<unsigned int> indices);
    private:
        vao_t m_vao;
        vbo_t m_vbo;
        ebo_t m_ebo;
        std::vector<vertex> m_vertices;
        std::vector<unsigned int> m_indices;
    };
}

#endif
