#include "ResourceManager.hpp"

std::unordered_map<std::string, std::shared_ptr<Mesh>> ResourceManager::meshes;
std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::textures;
std::unordered_map<std::string, std::shared_ptr<Shader>> ResourceManager::shaders;

std::shared_ptr<Shader> ResourceManager::loadShader(const std::string &name, const std::string &vertexPath, const std::string &fragmentPath) {
    auto shader = std::make_shared<Shader>(vertexPath, fragmentPath);
    shaders[name] = shader;
    return shader;
}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string &name, const std::string &path) {
    if (textures.find(name) != textures.end()) {
        return textures[name];
    }

    auto texture = std::make_shared<Texture>(path);
    textures[name] = texture;
    return texture;
}

std::shared_ptr<Mesh> ResourceManager::loadMesh(const std::string &name, const std::string &type) {
    if (meshes.find(name) != meshes.end()) {
        return meshes[name];
    }

    std::shared_ptr<Mesh> mesh;

    if (type == "triangle")
        mesh = MeshFactory::createTriangle();
    else if (type == "quad")
        mesh = MeshFactory::createQuad();
    else if (type == "cube")
        mesh = MeshFactory::createCube();
    else {
        std::cerr << "Unknown mesh type: " << type << "\n";
        return nullptr;
    }

    meshes[name] = mesh;
    return mesh;
}

std::shared_ptr<Shader> ResourceManager::getShader(const std::string &name) {
    if (shaders.find(name) == shaders.end()) {
        std::cerr << "Shader not found: " << name << "\n";
        return nullptr;
    }
    return shaders[name];
}

std::shared_ptr<Texture> ResourceManager::getTexture(const std::string &name) {
    if (textures.find(name) == textures.end()) {
        std::cerr << "Texture not found: " << name << "\n";
        return nullptr;
    }
    return textures[name];
}

std::shared_ptr<Mesh> ResourceManager::getMesh(const std::string &name) {
    if (meshes.find(name) == meshes.end()) {
        std::cerr << "Mesh not found: " << name << "\n";
        return nullptr;
    }
    return meshes[name];
}

void ResourceManager::clear() {
    shaders.clear();
    textures.clear();
    meshes.clear();

    std::cout << "ResourceManager cleared all resources.\n";
}



// #include "ResourceManager.hpp"

// std::shared_ptr<Shader> ResourceManager::loadShader(const std::string &name, const std::string &vertexPath, const std::string &fragmentPath) {
//     auto shader = std::make_shared<Shader>(vertexPath, fragmentPath);
//     shaders[name] = shader;
//     return shader;
// }

// std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string &name, const std::string &path) {
//     if (textures.find(name) != textures.end()) {
//         return textures[name];
//     }
//     std::shared_ptr<Texture> texture = std::make_shared<Texture>(path);
//     textures[name] = texture;
//     return texture;
// }

// std::shared_ptr<Mesh> ResourceManager::loadMesh(const std::string &name, const std::string &path) {
//     if (meshes.find(name) != meshes.end()) {
//         return meshes[name];
//     }
//     std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(path);
//     meshes[name] = mesh;
//     return mesh;
// }

// std::shared_ptr<Shader> ResourceManager::getShader(const std::string &name) {
//     if (shaders.find(name) == shaders.end()) {
//         std::cerr << "Shader not found: " << name << "\n";
//         return nullptr;
//     }
//     return shaders[name];
// }

// std::shared_ptr<Texture> ResourceManager::getTexture(const std::string &name) {
//     if (textures.find(name) == textures.end()) {
//         std::cerr << "Texture not found: " << name << "\n";
//         return nullptr;
//     }
//     return textures[name];
// }

// std::shared_ptr<Mesh> ResourceManager::getMesh(const std::string &name) {
//     if (meshes.find(name) == meshes.end()) {
//         std::cerr << "Mesh not found: " << name << "\n";
//         return nullptr;
//     }
//     return meshes[name];
// }

// void ResourceManager::clear() {
//     shaders.clear();
//     textures.clear();
//     meshes.clear();

//     std::cout << "ResourceManager cleared all resources.\n";
// }