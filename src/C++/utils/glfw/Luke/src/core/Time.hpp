#pragma once
#include <GLFW/glfw3.h>

class Time {
    private:
        float deltaTime;
        float lastTime;
    public:
        /// @brief  da update no deltatime usando o glfwGetTime()
        void update();
        /// @brief  construtor do Time
        Time();
        /// @brief  destrutor do Time
        ~Time();
        /// @brief  retorna o deltaTime
        float getDeltaTime();
};