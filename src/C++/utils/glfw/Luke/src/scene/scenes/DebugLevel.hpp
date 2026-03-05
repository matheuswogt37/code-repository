#pragma once
#include "../Scene.hpp"
#include "../../ecs/components/Transform.hpp"
#include "../../ecs/components/MeshRenderer.hpp"
#include "../../ecs/components/CameraComponent.hpp"
#include "../../rendering/MeshFactory.hpp"

class DebugLevel : public Scene {
    public:
        void start() override;
};