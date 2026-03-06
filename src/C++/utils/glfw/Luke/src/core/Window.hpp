#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

class Window {
    private:
    public:
        GLFWwindow* window;
        /// @brief Construtor da janela, passa como parâmetros o tamanho, largura e nome para a janela
        Window(int width, int height, std::string windowTittle);
        /// @brief Destroi a janela pelo glfw
        ~Window();
        /// @brief Troca buffers e poll events
        void update();
};