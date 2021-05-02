#ifndef WINTER_TEXTURE2D_H
#define WINTER_TEXTURE2D_H

#include <string>
#include <glm/vec2.hpp>

namespace winter {

    typedef unsigned char* raw_texture_data_t;
    typedef unsigned int texture_id_t;

    class texture2d {
    public:
        texture2d();
        ~texture2d();
        void from_file(std::string filename);
        void use();
        glm::vec2 size() { return glm::vec2(m_width, m_height); };
    private:
        texture_id_t m_id;
        int m_width;
        int m_height;
    };
}


#endif
