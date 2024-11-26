#include "include/Camera.h"
#include "include/Loader.h"
#include "include/Renderer.h"
#include "include/Window.h"
#include "include/Shader.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    Window window(800, 600, "3D OBJ Viewer");

    Loader loader;
    Renderer renderer;
    Camera camera;

    glm::vec3 center;
    float scale;

    // Load the OBJ model
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    if (!loader.loadOBJ("teapot.obj", vertices, indices, center, scale)) {
        std::cerr << "Failed to load OBJ file!" << std::endl;
        return -1;
    }

    // Skybox setup
    std::vector<std::string> faces = {"textures/right.jpg", "textures/left.jpg",
                                      "textures/top.jpg",   "textures/bottom.jpg",
                                      "textures/front.jpg", "textures/back.jpg"};
    unsigned int cubemapTexture = renderer.loadCubemap(faces);
    Shader skyboxShader("shaders/skybox_vertex.glsl", "shaders/skybox_fragment.glsl");

    // Define shader for the 3D model
    Shader modelShader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Main rendering loop
    while (!window.shouldClose()) {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Process input for camera movement
        window.processInput(camera, deltaTime); 

        window.pollEvents();

        // Render the skybox
        renderer.renderSkybox(skyboxShader, cubemapTexture, camera);

        // Render the model
        renderer.render(vertices, modelShader, camera, center, scale);

        window.swapBuffers();
    }

    return 0;
}
