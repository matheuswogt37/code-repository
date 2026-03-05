#include "Registry.hpp"

Entity Registry::createEntity() {
    Entity e = this->nextEntity++;
    this->entities.push_back(e);
    return e;
}

const std::vector<Entity> &Registry::getEntities() const {
    return this->entities;
}