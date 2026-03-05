#include "DebugLevel.hpp"

void DebugLevel::start() {
    Entity camera = this->registry.createEntity();

    this->registry.addComponent<Transform>(camera);
    this->registry.addComponent<CameraComponent>(camera);

    Entity triangle = this->registry.createEntity();

    Transform transform;
    transform.position = {0, 0, -3};

    MeshRenderer renderer;
    renderer.mesh = MeshFactory::createTriangle();

    this->registry.addComponent(triangle, transform);
    this->registry.addComponent(triangle, render);
}