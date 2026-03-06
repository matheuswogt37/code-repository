#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "../rendering/Shader.hpp"
#include "../rendering/Texture.hpp"
#include "../rendering/Mesh.hpp"
#include "../rendering/MeshFactory.hpp"

class ResourceManager {
    private:
        static std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
        static std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
        static std::unordered_map<std::string, std::shared_ptr<Mesh>> meshes;
    public:
        static std::shared_ptr<Shader> loadShader(const std::string &name, const std::string &vertexPath, const std::string &fragmentPath);
        static std::shared_ptr<Texture> loadTexture(const std::string &name, const std::string &path);
        static std::shared_ptr<Mesh> loadMesh(const std::string &name, const std::string &path);
        static std::shared_ptr<Shader> getShader(const std::string &name);
        static std::shared_ptr<Texture> getTexture(const std::string &name);
        static std::shared_ptr<Mesh> getMesh(const std::string &name);
        static void clear();
};