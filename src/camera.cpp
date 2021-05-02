#include "camera.h"

using namespace winter;

camera::camera(int window_width, int window_height)
    : m_width(window_width), m_height(window_height) {

    m_view = glm::mat4(1.0f);
    m_projection = glm::mat4(1.0f);

    m_pos = glm::vec3(0.0f, 0.0f, -10.0f);
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    m_forward = glm::vec3(0.0f, 0.0f, -1.0f);

    m_view = glm::lookAt(m_pos, m_pos - m_forward, m_up);
    m_projection = glm::ortho(0.0f, m_width, 0.0f, m_height, 0.1f, 100.0f);
}

camera::~camera() {

}

glm::mat4 camera::view() {
    return m_view;
}

glm::mat4 camera::projection() {
    return m_projection;
}

void camera::update(float dt) {
    m_view = glm::lookAt(m_pos, glm::normalize(m_pos - m_forward), m_up);
}
