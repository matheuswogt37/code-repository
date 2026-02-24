#pragma once
#include <memory>
#include "../math/Transform.hpp"
#include "../graphics/Mesh.hpp"
#include "../graphics/Material.hpp"

class GameObject {
    public:
        Transform transform;
        Material material;
        std::shared_ptr<Mesh> mesh;
};