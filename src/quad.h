#ifndef BASOKO_QUAD_H
#define BASOKO_QUAD_H

typedef unsigned int vao_id;
typedef unsigned int vbo_id;
typedef unsigned int ebo_id;

namespace winter {
    class quad {
    public:
        quad();
        ~quad();
        void draw();
    private:
        vao_id m_vao;
        vbo_id m_vbo;
        ebo_id m_ebo;
    };
}

#endif
