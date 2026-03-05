#pragma once
#include <memory>
#include "Mesh.hpp"

class MeshFactory {
    public:
        static std::shared_ptr<Mesh> createTriangle();
        static std::shared_ptr<Mesh> createQuad();
        static std::shared_ptr<Mesh> createCube();
};