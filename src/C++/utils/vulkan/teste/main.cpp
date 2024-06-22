//* VULKAN
#include <vulkan/vulkan.hpp>

//* GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//* OTHERS
#include <cstdlib>
#include <iostream>
#include <stdexcept>

//* WINDOW
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

//* MACROS AND GLOBAL FUNCTIONS
#define HANDLER_ERROR(ERROR, FORMAT, ...)                                                                                   \
    {                                                                                                                       \
        if (ERROR) {                                                                                                        \
            fprintf(stderr, "%s -> %s -> %i -> Error(%i)\n%s\n" FORMAT, __FILE__, __func__, __LINE__, ERROR, #__VA_ARGS__); \
            printf("\n");                                                                                                   \
        }                                                                                                                   \
    }
void glfwHandlerError(int error_code, const char *description) {
    HANDLER_ERROR(error_code, "GLFW: %s", description);
}
void exitCallback() {
    glfwTerminate();
}

class App {
   private:
    GLFWwindow *window;
    VkInstance instace;
    VkAllocationCallbacks *allocator;
    void initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        this->window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    };
    void createInstance() {
        // VkApplicationInfo appInfo{};
        // appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        // appInfo.pApplicationName = "Move point";
        // appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        // appInfo.pEngineName = "No engine";
        // appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        // appInfo.apiVersion = VK_API_VERSION_1_0;

        uint32_t reqExtensionsCount;
        const char **reqExtensions = glfwGetRequiredInstanceExtensions(&reqExtensionsCount);

        // vkCreateInstance(&(VkInstanceCreateInfo){
        //                      .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        //                      .pApplicationInfo = &(VkApplicationInfo){
        //                          .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        //                          .pApplicationName = "Move point",
        //                          .pEngineName = "No engine",
        //                          .apiVersion = VK_API_VERSION_1_0},
        //                      .enabledExtensionCount = reqExtensionsCount,
        //                      .ppEnabledExtensionNames = reqExtensions},
        //                  this->instace, )
    }
    void initVulkan() {
        // todo uncomment these
        // createInstance();

        // selectPhysicalDevice();
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
    void selectPhysicalDevice() {
        uint32_t count;
        vkEnumeratePhysicalDevices(this->instace, &count, NULL);
        std::cout << "physical device count - " << count << std::endl;
    }

   public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
};

int main() {
    glfwSetErrorCallback(glfwHandlerError);
    atexit(exitCallback);

        return 0;

    // todo uncomment these
    //  App app;
    //  try {
    //      app.run();
    //  } catch (const std::exception &e) {
    //      std::cerr << e.what() << std::endl;
    //      return EXIT_FAILURE;
    //  }
    //  return EXIT_SUCCESS;
}