#include "RenderSystem.hpp"

void RenderSystem::render(Registry &registry) {
    Transform *cameraTransform = nullptr;
    CameraComponent *camera = nullptr;
    for (Entity e : registry.getEntities()) {
        if (registry.hasComponent<Transform>(e) && registry.hasComponent<CameraComponent>(e)) {
            auto& cam = registry.getComponent<CameraComponent>(e);

            if (cam.primary) {
                cameraTransform = &registry.getComponent<Transform>(e);
                camera = &cam;
                break;
            }
        }
    }

    if (!cameraTransform || !camera) {
        return;
    }

    if (camera->dirty) {
        camera->updateProjection();
    }

    glm::mat4 view = glm::inverse(cameraTransform->getModelMatrix());
    glm::mat4 projection = camera->projection;

    for (Entity e : registry.getEntities()) {
        if (registry.hasComponent<Transform>(e) && registry.hasComponent<MeshRenderer>(e)) {
            auto& transform = registry.getComponent<Transform>(e);
            auto& renderer = registry.getComponent<MeshRenderer>(e);
            if (!renderer.mesh || !renderer.material) {
                continue;
            }

            Shader &shader = renderer.material->getShader();
            shader.bind();
            shader.setMat4("u_Model", transform.getModelMatrix());
            shader.setMat4("u_View", view);
            shader.setMat4("u_Projection", projection);

            renderer.material->bind();
            renderer.mesh->draw();
        }
    }
}