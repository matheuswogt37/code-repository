#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include <typeindex>

#include <stdexcept> //* think about it

#include "Entity.hpp"
#include "Component.hpp"
class Registry {
    private:
        Entity nextEntity = 1;

        std::vector<Entity> entities;
        std::unordered_map<std::type_index, std::unordered_map<Entity, std::unique_ptr<Component>>> componentPools;

    public:
        Entity createEntity();
        //* new
        template<typename T, typename... Args>
        T& addComponent(Entity entity, Args&&... args);
        //* old
        template<typename T>
        void addComponent (Entity entity, const T &component);

        template<typename T>
        T &getComponent(Entity entity);


        template<typename T>
        bool hasComponent(Entity entity);

        const std::vector<Entity> &getEntities() const;
};

//* new
template<typename T, typename... Args>
T& Registry::addComponent(Entity entity, Args&&... args) {
    auto component = std::make_unique<T>(std::forward<Args>(args)...);
    T *ref = component.get();
    this->componentPools[typeid(T)][entity] = std::move(component);
    return *ref;
}

//* old
template<typename T>
void Registry::addComponent(Entity entity, const T &component) {
    this->componentPools[typeid(T)][entity] = std::make_unique<T>(component);
}

template<typename T>
T& Registry::getComponent(Entity entity) {

    auto& pool = componentPools[typeid(T)];

    auto it = pool.find(entity);

    if (it == pool.end()) {
        throw std::runtime_error("Component not found");
    }

    return *static_cast<T*>(it->second.get());
}

template<typename T>
bool Registry::hasComponent(Entity entity) {

    auto poolIt = componentPools.find(typeid(T));

    if (poolIt == componentPools.end())
        return false;

    auto& pool = poolIt->second;

    return pool.find(entity) != pool.end();
}

// template<typename T>
// T &Registry::getComponent(Entity entity) {
//     return *static_cast<T*>(this->componentPools[typeid(T)][entity].get());
// }

// template<typename T>
// bool Registry::hasComponent(Entity entity) {
//     auto &pool = this->componentPools[typeid(T)];
//     return pool.find(entity) != pool.end();
// }