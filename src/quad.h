#ifndef WINTER_QUAD_H
#define WINTER_QUAD_H

#include <glm/glm.hpp>

typedef unsigned int vao_id;
typedef unsigned int vbo_id;
typedef unsigned int ebo_id;

namespace winter {
    class quad {
    public:
        quad();
        ~quad();
        void draw() const;
        void scale(glm::vec2 scale);
        void translate(glm::vec2 translation);
        glm::mat4 model();
    private:
        vao_id m_vao;
        vbo_id m_vbo;
        ebo_id m_ebo;
        glm::mat4 m_model;
        glm::vec3 m_pos;
        glm::vec3 m_scale;
    };
}

#endif
