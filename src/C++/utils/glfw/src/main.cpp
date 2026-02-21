#include <GLFW/glfw3.h>
#include "linmath.h"
#include <iostream>

// ============================
// Global Variables
// ============================

bool rotateLeft = false;
bool rotateRight = false;

// ============================
// Triangle Object
// ============================

class Triangle {
    private:
        float rotation;
    public:
        Triangle() : rotation(0.f) {}
        ~Triangle() {}
        void update(float deltaTime) {
            if (rotateLeft) {
                rotation += 100.0f * deltaTime;
            }
            if (rotateRight) {
                rotation -= 100.0f * deltaTime;
            }
        }
        void draw() {
            glPushMatrix();
            glRotatef(rotation, 0.f, 0.f, 1.f);

            glBegin(GL_TRIANGLES);
                glColor3f(1.f, 0.f, 0.f);
                glVertex3f(-0.6f, -0.4f, 0.f);

                glColor3f(0.f, 1.f, 0.f);
                glVertex3f(0.6f, -0.4f, 0.f);
                
                glColor3f(0.f, 0.f, 1.f);
                glVertex3f(0.f, 0.6f, 0.f);
            glEnd();

            glPopMatrix();
        }
};


// ============================
// Global Input State
// ============================

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    } else if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS) {
            rotateLeft = true;
        } else if (action == GLFW_RELEASE) {
            rotateLeft = false;
        }
    } else if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS) {
            rotateRight = true;
        } else if (action == GLFW_RELEASE) {
            rotateRight = false;
        }
    }
}

// ============================
// Main
// ============================

int main() {
    
    if(!glfwInit()) {
        //! Error init glfw
        return 1;
    }

    GLFWwindow *window = glfwCreateWindow(1, 1, "Hello World!", NULL, NULL);
    if(!window) {
        //! Error init window
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    Triangle triangle;

    float lastTime = 0.0f;
    while(!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        ratio = width / (float) height;
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        //* update objects
        
        triangle.update(deltaTime);
        
        //* draw objects

        triangle.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}