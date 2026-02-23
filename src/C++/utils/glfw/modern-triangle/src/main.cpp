#include "../external/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "graphics/Renderer.hpp"

//* Window size
const unsigned int SCR_WIDTH = 1980;
const unsigned int SCR_HEIGHT = 1080;

//* Process input
bool rotateLeft = false;
bool rotateRight = false;
bool moveLeft = false;
bool moveRight = false;
bool moveUp = false;
bool moveDown = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    
    if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS)
            moveLeft = true;
        else if (action == GLFW_RELEASE)
            moveLeft = false;
    }
    if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS)
            moveRight = true;
        else if (action == GLFW_RELEASE)
            moveRight = false;
    }
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS)
            moveUp = true;
        else if (action == GLFW_RELEASE)
            moveUp = false;
    }
    if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS)
            moveDown = true;
        else if (action == GLFW_RELEASE)
            moveDown = false;
    }
    if (key == GLFW_KEY_LEFT) {
        if (action == GLFW_PRESS)
            rotateLeft = true;
        else if (action == GLFW_RELEASE)
            rotateLeft = false;
    }
    if (key == GLFW_KEY_RIGHT) {
        if (action == GLFW_PRESS)
            rotateRight = true;
        else if (action == GLFW_RELEASE)
            rotateRight = false;
    }
}

int main() {
    //* glfw init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //* glfw create window and set current context
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Modern Triangle", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    //* glad load
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    //* set key callback
    glfwSetKeyCallback(window, key_callback);

    //* renderer creation
    Renderer renderer;
    Triangle triangle;

    float lastTime = 0.f;

    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.update(deltaTime, moveLeft, moveRight, moveUp, moveDown, rotateLeft, rotateRight);
        renderer.draw(triangle);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}