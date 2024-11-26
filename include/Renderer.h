#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Camera.h"
#include <vector>
#include <string>

class Renderer {
public:
    void render(const std::vector<float>& vertices, Shader& shader, Camera& camera, glm::vec3 center, float scale);
    void renderSkybox(Shader& shader, unsigned int cubemapTexture, Camera& camera);
    unsigned int loadCubemap(const std::vector<std::string>& faces);
    void clear();
};

#endif
