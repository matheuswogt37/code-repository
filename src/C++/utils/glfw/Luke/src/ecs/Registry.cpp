#include "Registry.hpp"

Entity Registry::createEntity() {
    Entity e = this->nextEntity++;
    this->entities.push_back(e);
    return e;
}

template<typename T>
void Registry::addComponent(Entity entity, T component) {
    componentPools[typeid(T)][Entity] = new T(component);
}

template<typename T>
T &Registry::getComponent(Entity entity) {
    return *static_cast<T*>(componentPools[typeid(T)][entity]);
}

template<typename T>
bool Registry::hasComponent(Entity entity) {
    auto &pool = componentPools[typeid(T)];
    return pool.find(entity) != pool.end();
}

const std::vector<Entity> &Registry::getEntities() const {
    return this->entities;
}