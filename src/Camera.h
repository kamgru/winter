#ifndef WINTER_CAMERA_H
#define WINTER_CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace winter {

    class Camera {
    public:
        Camera(float viewportWidth, float viewportHeight);
        ~Camera();
        glm::mat4 GetViewMatrix();
        glm::mat4 GetProjectionMatrix();
        void Update();
        void SetPosition(glm::vec3 position);
        glm::vec3 GetPosition() const {return _position;}
        void SetForward(glm::vec3 forward);
        glm::vec3 GetForward() const {return _forward;}
    private:
        float _viewportWidth;
        float _viewportHeight;
        glm::vec3 _forward;
        glm::vec3 _right;
        glm::vec3 _up;
        glm::vec3 _position;
        glm::mat4 _viewMatrix;
        glm::mat4 _projectionMatrix;
    };
}

#endif
