#ifndef WINTER_COMPONENT_H
#define WINTER_COMPONENT_H

#include <glm/vec3.hpp>
#include "sprite.h"
#include "shader_program.h"

namespace winter {

    class component {

    };

    class transform : public component {
    public:
        void position(glm::vec3 position) { m_position = position; };
        glm::vec3 position() { return m_position; };
        void scale(glm::vec3 scale) { m_scale = scale; };
        glm::vec3 scale() { return m_scale; };
    private:
        glm::vec3 m_position;
        glm::vec3 m_scale;
    };

}

#endif //WINTER_COMPONENT_H
