#include "Window.hpp"

Window::Window(int width, int height, std::string windowTittle) {
    this->window = glfwCreateWindow(width, height, windowTittle.c_str(), NULL, NULL);
    glfwMakeContextCurrent(this->window);
}

Window::~Window() {
    glfwDestroyWindow(this->window);
}

void Window::update() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}