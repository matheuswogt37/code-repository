#include "Scene.hpp"

void Scene::start() {}

void Scene::update(float dt) {
    // inputSystem.update(this->registry); //* working on
    // movementSystem.update(this->registry, dt); //* working on
    // physicsSystem.update(this->registry, dt); //* working on
}

void Scene::render() {
    renderSystem.render(this->registry);
}

Registry &Scene::getRegistry() {
    return this->registry;
}