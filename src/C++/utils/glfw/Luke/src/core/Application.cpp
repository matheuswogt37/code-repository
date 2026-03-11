#include "Application.hpp"

//! private:
void Application::terminate() {
    ResourceManager::clear();
    //* terminate glad
    //* terminate window (destructor make this)
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

    //* init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }
    glEnable(GL_DEPTH_TEST);

    //* init Input
    this->time = std::make_unique<Time>();

    //* others
    this->running = true;
    this->sceneManager = std::make_unique<SceneManager>();

    //* start debug scene
    std::shared_ptr<DebugLevel> debugLevel = std::make_shared<DebugLevel>();
    this->sceneManager->addScene("debugLevel", debugLevel);
    //* load debug scene
    this->sceneManager->loadScene("debugLevel");
}

void Application::run() {
    //* process input
    while (!glfwWindowShouldClose(this->window->window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //* time update
        this->time->update();

        //* input update

        //* scene manager actual scene update
        this->sceneManager->update(this->time->getDeltaTime());
        this->sceneManager->render();

        //* window update
        this->window->update();
    }

    // * update
    //     * camera
    //     * physics system
    //     * animation system
    // * render
    //     * all the render pass
    // * shutdown -> call terminate
}