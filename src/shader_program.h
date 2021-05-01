#ifndef BASOKO_SHADER_PROGRAM_H
#define BASOKO_SHADER_PROGRAM_H

#include <string>

namespace winter {

    enum SHADER_TYPE {
        SHADER_TYPE_VERTEX = 0,
        SHADER_TYPE_FRAGMENT = 1
    };

    typedef unsigned int program_id;

    class shader_program {
    public:
        shader_program();
        ~shader_program();
        void attach_shader_file(SHADER_TYPE shader_type, std::string filename);
        void use();
    private:
        program_id m_program_id;
    };
}
#endif
