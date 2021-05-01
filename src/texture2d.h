#ifndef BASOKO_TEXTURE2D_H
#define BASOKO_TEXTURE2D_H

#include <string>

namespace winter {

    typedef unsigned char* raw_texture_data_t;
    typedef unsigned int texture_id_t;

    class texture2d {
    public:
        texture2d();
        ~texture2d();
        void from_file(std::string filename);
        void use();
    private:
        texture_id_t m_id;
        int m_width;
        int m_height;
    };
}


#endif
