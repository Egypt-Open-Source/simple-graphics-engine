#include "include/Camera.h"
#include "include/Loader.h"
#include "include/Renderer.h"
#include "include/Shader.h"
#include "include/Window.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Window window(800, 600, "3D OBJ Viewer");

    Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    Camera camera;
    Renderer renderer;

    glfwSetWindowUserPointer(window.getGLFWwindow(), &camera);
    glfwSetCursorPosCallback(window.getGLFWwindow(), Window::mouse_callback);
    glfwSetInputMode(window.getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    vector<float> vertices;
    vector<unsigned int> indices;

    if (!Loader::loadOBJ("teapot.obj", vertices, indices)) {
        cerr << "Failed to load OBJ file" << "\n";
        return -1;
    }

    float lastFrame = 0.0f;

    while (!window.shouldClose()) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Clear the screen with gray color
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Process input
        GLFWwindow* glfwWindow = window.getGLFWwindow();
        if (glfwGetKey(glfwWindow, GLFW_KEY_W) == GLFW_PRESS)
            camera.processKeyboard(GLFW_KEY_W, deltaTime);
        if (glfwGetKey(glfwWindow, GLFW_KEY_S) == GLFW_PRESS)
            camera.processKeyboard(GLFW_KEY_S, deltaTime);
        if (glfwGetKey(glfwWindow, GLFW_KEY_A) == GLFW_PRESS)
            camera.processKeyboard(GLFW_KEY_A, deltaTime);
        if (glfwGetKey(glfwWindow, GLFW_KEY_D) == GLFW_PRESS)
            camera.processKeyboard(GLFW_KEY_D, deltaTime);

        // Render the scene
        renderer.render(vertices, shader, camera);

        // Swap buffers
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}
