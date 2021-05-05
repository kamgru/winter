#ifndef WINTER_TRANSFORM_H
#define WINTER_TRANSFORM_H

#include "glm/glm.hpp"
#include "actor.h"
#include "component.h"

namespace winter {

    class transform  {
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
#endif
