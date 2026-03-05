#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "Scene.hpp"

class SceneManager {
    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
        std::shared_ptr<Scene> currentScene;
    public:
        void addScene(const std::string &name, std::shared_ptr<Scene> scene);
        void loadScene(const std::string &name);
        void update(float dt);
        void render();
        std::shared_ptr<Scene> getCurrentScene();
};