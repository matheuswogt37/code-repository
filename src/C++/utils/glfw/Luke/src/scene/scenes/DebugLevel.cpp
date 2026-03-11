#include "DebugLevel.hpp"

void DebugLevel::start() {
    Entity camera = this->registry.createEntity();

    this->registry.addComponent<Transform>(camera);
    this->registry.addComponent<CameraComponent>(camera);

    auto shader = std::make_shared<Shader>(
        "../assets/shaders/basic.vert",
        "../assets/shaders/basic.frag"
    );

    Entity triangle = this->registry.createEntity();
    Transform transform;
    transform.position = {0, 0, -2};
    MeshRenderer renderer;
    renderer.mesh = MeshFactory::createTriangle();
    renderer.material = std::make_shared<Material>(shader);
    renderer.material->setColor({1,0,0});
    this->registry.addComponent<Transform>(triangle, transform);
    this->registry.addComponent<MeshRenderer>(triangle, renderer);

    Entity square = this->registry.createEntity();
    Transform s_transform;
    s_transform.position = {-0.5f, 0, -3};
    MeshRenderer s_renderer;
    s_renderer.mesh = MeshFactory::createCube();
    s_renderer.material = std::make_shared<Material>(shader);
    s_renderer.material->setColor({0,1,0});
    this->registry.addComponent<Transform>(square, s_transform);
    this->registry.addComponent<MeshRenderer>(square, s_renderer);
}