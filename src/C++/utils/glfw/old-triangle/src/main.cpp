#include <GLFW/glfw3.h>
#include "linmath.h"
#include <iostream>

// ============================
// Global Variables
// ============================

bool rotateLeft = false;
bool rotateRight = false;
bool moveLeft = false;
bool moveRight = false;
bool moveUp = false;
bool moveDown = false;

// ============================
// Triangle Object
// ============================

class Triangle {
    private:
        //* movement
        float posX, posY;
        float moveSpeed;

        //* rotation
        float rotation;
        float rotateSpeed;
    public:
        Triangle() : posX(0.f), posY(0.f), moveSpeed(2.5f), 
        rotation(0.f), rotateSpeed(100.f) {}
        ~Triangle() {}
        void update(float deltaTime) {
            //* movement
            if (moveLeft) {
                posX -= moveSpeed * deltaTime;
            }
            if (moveRight) {
                posX += moveSpeed * deltaTime;
            }
            if (moveUp) {
                posY += moveSpeed * deltaTime;
            }
            if (moveDown) {
                posY -= moveSpeed * deltaTime;
            }

            //* rotation
            if (rotateLeft) {
                rotation += 100.0f * deltaTime;
            }
            if (rotateRight) {
                rotation -= 100.0f * deltaTime;
            }
        }
        void draw() {
            glPushMatrix();

            glTranslatef(posX, posY, 0.f);
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
    } else if (key == GLFW_KEY_LEFT) {
        if (action == GLFW_PRESS) {
            rotateLeft = true;
        } else if (action == GLFW_RELEASE) {
            rotateLeft = false;
        }
    } else if (key == GLFW_KEY_RIGHT) {
        if (action == GLFW_PRESS) {
            rotateRight = true;
        } else if (action == GLFW_RELEASE) {
            rotateRight = false;
        }
    } else if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS) {
            moveLeft = true;
        } else if (action == GLFW_RELEASE) {
            moveLeft = false;
        }
    } else if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS) {
            moveRight = true;
        } else if (action == GLFW_RELEASE) {
            moveRight = false;
        }
    } else if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS) {
            moveUp = true;
        } else if (action == GLFW_RELEASE) {
            moveUp = false;
        }
    } else if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS) {
            moveDown = true;
        } else if (action == GLFW_RELEASE) {
            moveDown = false;
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