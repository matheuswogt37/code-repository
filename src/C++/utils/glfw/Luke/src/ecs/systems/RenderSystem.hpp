#pragma once
#include "../../ecs/Registry.hpp"
#include "../components/Transform.hpp"
#include "../components/MeshRenderer.hpp"
#include "../components/CameraComponent.hpp"
#include "../../rendering/Shader.hpp"

class RenderSystem {
    public:
        void render(Registry &registry);
};