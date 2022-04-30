#include "Camera.h"

using namespace winter;

static glm::vec3 WORLD_UP;

Camera::Camera(float viewportWidth, float viewportHeight)
    : _viewportWidth(viewportWidth), _viewportHeight(viewportHeight) {

    _viewMatrix = glm::mat4(1.0f);
    _projectionMatrix = glm::mat4(1.0f);

    WORLD_UP = glm::vec3 (0.0f, 1.0f, 0.0f);
    _position = glm::vec3(0.0f, 0.0f, 10.0f);
    _up = glm::vec3(0.0f, 1.0f, 0.0f);
    _forward = glm::vec3(0.0f, 0.0f, -1.0f);
    _right = glm::cross(WORLD_UP, _forward);

    _viewMatrix = glm::lookAt(_position, _position + _forward, _up);

    float aspect = (float)_viewportWidth / (float)_viewportHeight;
    _projectionMatrix = glm::perspective(glm::radians(60.0f), aspect, 0.05f, 100.0f);
}

Camera::~Camera() = default;

glm::mat4 Camera::GetViewMatrix() {
    return _viewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix() {
    return _projectionMatrix;
}

void Camera::Update() {
    _up = glm::cross(_forward, _right);
    _viewMatrix = glm::lookAt(_position, _position + _forward, _up);
}

void Camera::SetPosition(glm::vec3 position) {
    _position = position;
}

void Camera::SetForward(glm::vec3 forward) {
    _forward = forward;
    _right = glm::cross(WORLD_UP, _forward);
}
