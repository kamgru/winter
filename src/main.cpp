#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "ShaderProgram.h"
#include "Texture2d.h"
#include "Camera.h"
#include "Mesh.h"
#include "sprite_component.h"
#include "Renderer.h"
#include <chrono>

const float WINDOW_WIDTH = 800.0f;
const float WINDOW_HEIGHT = 600.0f;

void HandleCameraInput(float elapsed, winter::Window* window, winter::Camera *camera){
    glm::vec3 cameraPosition = camera->GetPosition();
    glm::vec3 cameraForward = camera->GetForward();

    float cameraSpeed = 1.0f;

    int moveLeft = glfwGetKey(window->GetGlfwWindow(), GLFW_KEY_A);
    if (moveLeft == GLFW_PRESS){
        auto left = glm::vec3 ((-1) * cameraForward.z, 0, cameraForward.x);
        cameraPosition -= left * cameraSpeed * elapsed;
    }

    int moveRight = glfwGetKey(window->GetGlfwWindow(), GLFW_KEY_D);
    if (moveRight == GLFW_PRESS){
        auto right = glm::vec3(cameraForward.z, 0, (-1) * cameraForward.x);
        cameraPosition -= right * cameraSpeed * elapsed;
    }

    int moveForward = glfwGetKey(window->GetGlfwWindow(), GLFW_KEY_W);
    if (moveForward == GLFW_PRESS){
        cameraPosition += glm::normalize(glm::vec3(cameraForward.x, 0, cameraForward.z)) * cameraSpeed * elapsed;
    }

    int moveBackward = glfwGetKey(window->GetGlfwWindow(), GLFW_KEY_S);
    if (moveBackward == GLFW_PRESS){
        cameraPosition -= glm::normalize(glm::vec3(cameraForward.x, 0, cameraForward.z)) * cameraSpeed * elapsed;
    }

    int moveUp = glfwGetKey(window->GetGlfwWindow(), GLFW_KEY_SPACE);
    if (moveUp == GLFW_PRESS){
        cameraPosition.y += cameraSpeed * elapsed;
    }

    int moveDown = glfwGetKey(window->GetGlfwWindow(), GLFW_KEY_LEFT_SHIFT);
    if (moveDown == GLFW_PRESS){
        cameraPosition.y -= cameraSpeed * elapsed;
    }

    camera->SetPosition(cameraPosition);

    float pitch = 0.0f;
    float yaw = -90.0f;

    glm::vec2 windowSize = window->GetSize();
    float previousX =  windowSize.x / 2.0f;
    float previousY =  windowSize.y / 2.0f;

    double currentX, currentY;
    glfwGetCursorPos(window->GetGlfwWindow(), &currentX, &currentY);

    auto horizontalDelta = (float)(currentX - previousX);
    auto verticalDelta = (float)(previousY - currentY);

    float sensitivity = 0.1f;
    pitch += verticalDelta * sensitivity;
    pitch = glm::clamp(pitch, -89.9f, 89.9f);
    yaw += horizontalDelta * sensitivity;

    auto lookDirection = glm::vec3 (
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch)));

    camera->SetForward(glm::normalize(lookDirection));
}

int main() {

    winter::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "winter");
    window.Create();

    std::shared_ptr<winter::Texture2d> texture = winter::Texture2d::loadFromFile("../assets/textures/wall.jpg");
    winter::Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT);

    auto shaderProgram = winter::ShaderProgram::loadFromFile(
            "../assets/shaders/diffuse.vert",
            "../assets/shaders/diffuse.frag");

    auto cube = winter::Mesh::createCube();
    glm::mat4 cubeModelMatrix(1.0f);
    cubeModelMatrix = glm::translate(cubeModelMatrix, glm::vec3(0.0f, 3.0f, 0.0f));
    cubeModelMatrix = glm::scale(cubeModelMatrix, glm::vec3(2.0f, 2.0f, 2.0f));

    auto floorMesh = winter::Mesh::createQuad();
    glm::mat4 floorModelMatrix(1.0f);
    floorModelMatrix = glm::translate(floorModelMatrix, glm::vec3(0.0f, -3.0f, 0.0f));
    floorModelMatrix = glm::rotate(floorModelMatrix, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    floorModelMatrix = glm::scale(floorModelMatrix, glm::vec3(10.0f, 10.0f, 1.0f));

    winter::Renderer renderer;

    auto start = std::chrono::steady_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);

    glfwSetInputMode(window.GetGlfwWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(window.GetGlfwWindow(), WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

    while(!window.ShouldClose()){

        dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        start = std::chrono::steady_clock::now();
        float elapsed = (dt.count() / 60.0f);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cubeModelMatrix = glm::rotate(cubeModelMatrix, .05f * elapsed, glm::vec3(0, 1, 0));

        HandleCameraInput(elapsed, &window, &camera);

        camera.Update();

        renderer.Render(
                *cube,
                *shaderProgram,
                *texture,
                cubeModelMatrix,
                camera.GetViewMatrix(),
                camera.GetProjectionMatrix(),
                camera);

        renderer.Render(
                *floorMesh,
                *shaderProgram,
                *texture,
                floorModelMatrix,
                camera.GetViewMatrix(),
                camera.GetProjectionMatrix(),
                camera);

        window.SwapBuffers();
        glfwPollEvents();
    }

    return 0;
}