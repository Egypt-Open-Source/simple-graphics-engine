#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Camera.h"
#include <vector>

class Renderer {
public:
    Renderer();
    ~Renderer();
    void render(const std::vector<float>& vertices, Shader& shader, Camera& camera);

private:
    GLuint VAO, VBO;
    void setupMesh(const std::vector<float>& vertices);
};

#endif