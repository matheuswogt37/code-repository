// VULKAN
#include <vulkan/vulkan.h>

// GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// OTHERS
#include <iostream>
#include <stdexcept>
#include <cstdlib>

// WINDOW
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class App
{
private:
    GLFWwindow* window;
    void initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        this->window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    };
    void initVulkan() {

    };
    void mainLoop() {
        while (!glfwWindowShouldClose(this->window)) {
            glfwPollEvents();
        }
    };
    void cleanup() {
        glfwDestroyWindow(this->window);

        glfwTerminate();
    };

public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
};


int main() {
    App app;
    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}