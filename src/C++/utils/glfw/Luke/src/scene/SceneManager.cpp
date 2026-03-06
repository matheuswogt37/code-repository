#include "SceneManager.hpp"

void SceneManager::addScene(const std::string &name, std::shared_ptr<Scene> scene) {
    this->scenes[name] = scene;
}

void SceneManager::loadScene(const std::string &name) {
    this->currentScene = this->scenes[name];
    if (this->currentScene) {
        this->currentScene->start();
    }
}

void SceneManager::update(float dt) {
    if (this->currentScene) {
        this->currentScene->update(dt);
    }
}

void SceneManager::render() {
    if (this->currentScene) {
        this->currentScene->render();
    }
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() {
    return this->currentScene;
}