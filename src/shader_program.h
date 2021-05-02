#ifndef WINTER_SHADER_PROGRAM_H
#define WINTER_SHADER_PROGRAM_H

#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

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
        void set_uniform_mat4(std::string name, glm::mat4 mat);
        void use();
    private:
        program_id m_program_id;
    };
}
#endif
