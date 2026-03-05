#pragma once
#include <memory>
#include "../../rendering/Mesh.hpp"
#include "../../rendering/Material.hpp"

struct MeshRenderer {
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Material> material;
};