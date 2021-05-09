#ifndef WINTER_TRANSFORM_COMPONENT_H
#define WINTER_TRANSFORM_COMPONENT_H

#include "glm/glm.hpp"
#include "component.h"

namespace winter {

    class transform_component : public component  {
    public:
        using component::component;
        void position(glm::vec3 position) { m_position = position; };
        glm::vec3 position() { return m_position; };
        void scale(glm::vec3 scale) { m_scale = scale; };
        glm::vec3 scale() { return m_scale; };
    private:
        glm::vec3 m_position {glm::vec3(0.0f)};
        glm::vec3 m_scale {glm::vec3(1.0f)};
    };
}
#endif
