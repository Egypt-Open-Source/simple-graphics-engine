#ifndef CAMERA_H
#define CAMERA_H

#include "../vendors/glm/glm/glm.hpp"

class Camera {
public:
    Camera();
    glm::mat4 getViewMatrix();
    void processKeyboard(int direction, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset);
    void processMouseScroll(float yoffset);

    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw;
    float pitch;
    float fov;

private:
    float speed;
    float sensitivity;
};

#endif