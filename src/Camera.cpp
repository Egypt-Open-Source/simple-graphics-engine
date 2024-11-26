#include "../include/Camera.h"
#include "../vendors/glfw/include/GLFW/glfw3.h"
#include "../vendors/glm/glm/gtc/matrix_transform.hpp"

Camera::Camera() 
    : position(glm::vec3(0.0f, 0.0f, 3.0f)), 
      front(glm::vec3(0.0f, 0.0f, -1.0f)), 
      up(glm::vec3(0.0f, 1.0f, 0.0f)), 
      yaw(-90.0f), 
      pitch(0.0f), 
      fov(45.0f), 
      speed(2.5f), 
      sensitivity(0.1f) {}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(int direction, float deltaTime) {
    float velocity = speed * deltaTime;
    if (direction == GLFW_KEY_W)
        position += front * velocity;
    if (direction == GLFW_KEY_S)
        position -= front * velocity;
    if (direction == GLFW_KEY_A)
        position -= glm::normalize(glm::cross(front, up)) * velocity;
    if (direction == GLFW_KEY_D)
        position += glm::normalize(glm::cross(front, up)) * velocity;
}

void Camera::processMouseMovement(float xoffset, float yoffset) {
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = glm::normalize(front);
}

void Camera::processMouseScroll(float yoffset) {
    fov -= yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}