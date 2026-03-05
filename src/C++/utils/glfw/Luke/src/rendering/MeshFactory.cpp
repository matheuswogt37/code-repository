#include "MeshFactory.hpp"

std::shared_ptr<Mesh> MeshFactory::createTriangle() {
    std::vector<float> vertices = {
        0.f, 0.5f, 0.f,
        -0.5f, -0.5f, 0.f,
        0.5f, -0.5f, 0.f
    };

    std::vector<unsigned int> indices = {
        0,1,2
    };

    return std::make_shared<Mesh>(vertices, indices);
}

std::shared_ptr<Mesh> MeshFactory::createQuad() {

    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.f,
        0.5f, -0.5f, 0.f,
        0.5f,  0.5f, 0.f,
        -0.5f,  0.5f, 0.f
    };

    std::vector<unsigned int> indices = {
        0,1,2,
        2,3,0
    };

    return std::make_shared<Mesh>(vertices, indices);
}

std::shared_ptr<Mesh> MeshFactory::createCube() {

    std::vector<float> vertices = {
        -0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,-0.5f,
        0.5f, 0.5f,-0.5f,
        -0.5f, 0.5f,-0.5f,

        -0.5f,-0.5f, 0.5f,
        0.5f,-0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f
    };

    std::vector<unsigned int> indices = {
        0,1,2, 2,3,0,
        4,5,6, 6,7,4,
        0,1,5, 5,4,0,
        2,3,7, 7,6,2,
        1,2,6, 6,5,1,
        3,0,4, 4,7,3
    };

    return std::make_shared<Mesh>(vertices, indices);
}