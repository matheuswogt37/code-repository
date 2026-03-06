#pragma once
#include <memory>
#include "../../rendering/Mesh.hpp"
#include "../../rendering/Material.hpp"
#include "../Component.hpp"

struct MeshRenderer : public Component {
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Material> material;
};