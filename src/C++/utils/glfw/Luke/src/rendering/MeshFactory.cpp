#include "MeshFactory.hpp"

std::shared_ptr<Mesh> MeshFactory::createTriangle() {

    std::vector<Vertex> vertices = {

        {
            glm::vec3(-0.5f, -0.5f, 0.0f),  // position
            glm::vec3(0.0f, 0.0f, 1.0f),    // normal
            glm::vec2(0.0f, 0.0f)           // texCoord
        },

        {
            glm::vec3(0.5f, -0.5f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec2(1.0f, 0.0f)
        },

        {
            glm::vec3(0.0f, 0.5f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec2(0.5f, 1.0f)
        }
    };

    std::vector<unsigned int> indices = {
        0,1,2
    };

    return std::make_shared<Mesh>(vertices, indices);
}

// std::shared_ptr<Mesh> MeshFactory::createTriangle() {
//     std::vector<float> vertices = {
//         0.f, 0.5f, 0.f,
//         -0.5f, -0.5f, 0.f,
//         0.5f, -0.5f, 0.f
//     };

//     std::vector<unsigned int> indices = {
//         0,1,2
//     };

//     return std::make_shared<Mesh>(vertices, indices);
// }

std::shared_ptr<Mesh> MeshFactory::createQuad() {

    std::vector<Vertex> vertices = {

        { glm::vec3(-0.5f,-0.5f,0.f), glm::vec3(0,0,1), glm::vec2(0,0) },
        { glm::vec3( 0.5f,-0.5f,0.f), glm::vec3(0,0,1), glm::vec2(1,0) },
        { glm::vec3( 0.5f, 0.5f,0.f), glm::vec3(0,0,1), glm::vec2(1,1) },
        { glm::vec3(-0.5f, 0.5f,0.f), glm::vec3(0,0,1), glm::vec2(0,1) }

    };

    std::vector<unsigned int> indices = {
        0,1,2,
        2,3,0
    };

    return std::make_shared<Mesh>(vertices, indices);
}

// std::shared_ptr<Mesh> MeshFactory::createQuad() {

//     std::vector<float> vertices = {
//         -0.5f, -0.5f, 0.f,
//         0.5f, -0.5f, 0.f,
//         0.5f,  0.5f, 0.f,
//         -0.5f,  0.5f, 0.f
//     };

//     std::vector<unsigned int> indices = {
//         0,1,2,
//         2,3,0
//     };

//     return std::make_shared<Mesh>(vertices, indices);
// }

std::shared_ptr<Mesh> MeshFactory::createCube() {

    std::vector<Vertex> vertices = {

        { glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0,0,-1), glm::vec2(0,0) },
        { glm::vec3( 0.5f,-0.5f,-0.5f), glm::vec3(0,0,-1), glm::vec2(1,0) },
        { glm::vec3( 0.5f, 0.5f,-0.5f), glm::vec3(0,0,-1), glm::vec2(1,1) },
        { glm::vec3(-0.5f, 0.5f,-0.5f), glm::vec3(0,0,-1), glm::vec2(0,1) },

        { glm::vec3(-0.5f,-0.5f, 0.5f), glm::vec3(0,0,1), glm::vec2(0,0) },
        { glm::vec3( 0.5f,-0.5f, 0.5f), glm::vec3(0,0,1), glm::vec2(1,0) },
        { glm::vec3( 0.5f, 0.5f, 0.5f), glm::vec3(0,0,1), glm::vec2(1,1) },
        { glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0,0,1), glm::vec2(0,1) }

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

// std::shared_ptr<Mesh> MeshFactory::createCube() {

//     std::vector<float> vertices = {
//         -0.5f,-0.5f,-0.5f,
//         0.5f,-0.5f,-0.5f,
//         0.5f, 0.5f,-0.5f,
//         -0.5f, 0.5f,-0.5f,

//         -0.5f,-0.5f, 0.5f,
//         0.5f,-0.5f, 0.5f,
//         0.5f, 0.5f, 0.5f,
//         -0.5f, 0.5f, 0.5f
//     };

//     std::vector<unsigned int> indices = {
//         0,1,2, 2,3,0,
//         4,5,6, 6,7,4,
//         0,1,5, 5,4,0,
//         2,3,7, 7,6,2,
//         1,2,6, 6,5,1,
//         3,0,4, 4,7,3
//     };

//     return std::make_shared<Mesh>(vertices, indices);
// }