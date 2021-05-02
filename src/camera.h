#ifndef WINTER_CAMERA_H
#define WINTER_CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace winter {

    class camera {
    public:
        camera(int window_width, int window_height);
        ~camera();
        glm::mat4 view();
        glm::mat4 projection();
        void update(float dt);
    private:
        float m_width;
        float m_height;
        glm::vec3 m_forward;
        glm::vec3 m_up;
        glm::vec3 m_pos;
        glm::mat4 m_view;
        glm::mat4 m_projection;
    };
}

#endif
