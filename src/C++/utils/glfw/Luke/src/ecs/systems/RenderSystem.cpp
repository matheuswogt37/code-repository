#include "RenderSystem.hpp"

void RenderSystem::render(Registry &registry) {
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

            renderer.material->bind();
            renderer.mesh->draw();
        }
    }
}