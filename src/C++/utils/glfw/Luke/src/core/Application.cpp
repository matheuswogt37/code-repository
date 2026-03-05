#include "Application.hpp"

//! private:
void terminate() {
    //* terminate glad
    //* terminate window
}

//! public:
Application::Application() {
    std::cout << "Application construct\n";
}

Application::~Application() {
    std::cout << "Application destructor\n";
}

void Application::initialize(int width, int heigth, std::string windowTittle) {
    std::cout << "Application initialize\n";
    //* init glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //* init Window
    this->window = std::make_unique<Window>(width, heigth, windowTittle);

    //* init Input
    this->time = std::make_unique<Time>();
}

void Application::run() {
    //* process input
    while (!glfwWindowShouldClose(this->window->window)) {
        //* time update
        this->time->update();

        //* input update

        //* scene manager actual scene update

        //* window update
        this->window->update();
    }
    //* update
        //* camera
        //* physics system
        //* animation system
    //* render
        //* all the render pass
    //* shutdown -> call terminate
}