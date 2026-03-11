#include <GLFW/glfw3.h>
#include "linmath.h"
#include <iostream>

void peppaHouse() {
    //* chao
    glBegin(GL_QUADS);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(-1.f, -1.f, 0.f);
        glVertex3f( 1.f, -1.f, 0.f);
        glVertex3f( 1.f,  -0.5f, 0.f);
        glVertex3f(-1.f,  -0.5f, 0.f);
    glEnd();


    //* telhado
    glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.3f, 0.f, 0.f);
        glVertex3f(0.3f, 0.f, 0.f);
        glVertex3f(0.f, 0.3f, 0.f);
    glEnd();


    //* casa
    glBegin(GL_QUADS);
        glColor3f(1.f, 1.f, 0.f);
        glVertex3f(-0.3f, -0.5f, 0.f);
        glVertex3f( 0.3f, -0.5f, 0.f);
        glVertex3f( 0.3f,  0.f, 0.f);
        glVertex3f(-0.3f,  0.f, 0.f);
    glEnd();


    //* porta (137,81,41) rgb
    glBegin(GL_QUADS);
        glColor3f((float) 137/255,(float) 81/255,(float) 41/255);
        glVertex3f(-0.3f, -0.5f, 0.f);
        glVertex3f(-0.1f, -0.5f, 0.f);
        glVertex3f(-0.1f, -0.2f, 0.f);
        glVertex3f(-0.3f, -0.2f, 0.f);
    glEnd();

    //* janela esq
    glLineWidth(5.f);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.075f, -0.35f, 0.f);
        glColor3f(0.f, 0.f, 0.f);
        glVertex3f( 0.1f, -0.35f, 0.f);
        glColor3f(0.f, 0.f, 0.f);
        glVertex3f( 0.1f,  -0.1f, 0.f);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.075f,  -0.1f, 0.f);
    glEnd();
    glLineWidth(1.f);
    //* janela dir
    glLineWidth(5.f);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(0.1125f, -0.35f, 0.f);
        glColor3f(0.f, 0.f, 0.f);
        glVertex3f(0.275f, -0.35f, 0.f);
        glColor3f(0.f, 0.f, 0.f);
        glVertex3f(0.275f,  -0.1f, 0.f);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(0.1125f,  -0.1f, 0.f);
    glEnd();
    glLineWidth(1.f);
    //* macaneta
    glColor3f(0.f, 0.f, 0.f);
    glBegin(GL_TRIANGLE_FAN);
        float centerX = -0.15f;
        float centerY = -0.375f;
        float segments = 50;
        float radius = 0.015f;
        glVertex3f(centerX, centerY, 0.f);

        for (int i = 0; i <= segments; i++) {
            float angle = 2.0f * 3.1415926f * float(i) / float(segments);
            float x = centerX + radius * cosf(angle);
            float y = centerY + radius * sinf(angle);
            glVertex3f(x, y, 0.f);
        }

    glEnd();
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

    glClearColor(0.f, 0.f, 1.f, 1.f);

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

        //* draw objects
        peppaHouse();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}