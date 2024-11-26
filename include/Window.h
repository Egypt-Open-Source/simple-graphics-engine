#ifndef WINDOW_H
#define WINDOW_H

#include "../vendors/glfw/include/GLFW/glfw3.h"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose();
    void swapBuffers();
    void pollEvents();
    GLFWwindow* getGLFWwindow();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

private:
    GLFWwindow* window;

};

#endif // WINDOW_H