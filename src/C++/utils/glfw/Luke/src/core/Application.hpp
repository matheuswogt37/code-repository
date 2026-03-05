#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Window.hpp"
#include "Time.hpp"

class Application {
    private:
        std::unique_ptr<Window> window;
        std::unique_ptr<Time> time;
        void terminate();
    public:
        /// @brief Construtor da aplicacao
        Application();
        /// @brief Finaliza todo o programa com suas variaveis
        ~Application();
        /// @brief Inicializa glfw e outras classes necessarias, argumentos 0-2 sao para construir a janela
        void initialize(int width, int heigth, std::string windowTittle);
        /// @brief Roda todo o programa
        ///
        /// Processa inputs, da update na camera, sistema de fisica e animacao, renderiza os RenderPass's
        void run();
};