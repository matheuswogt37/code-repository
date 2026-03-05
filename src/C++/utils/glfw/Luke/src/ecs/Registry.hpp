#pragma once
#include <unordered_map>
#include <vector>
#include <typeindex>

#include "Entity.hpp"
class Registry {
    private:
        Entity nextEntity = 1;

        std::vector<Entity> entities;
        std::unordered_map<std::type_index, std::unordered_map<Entity, void*>> componentPools;

    public:
        Entity createEntity();
        template<typename T>
        void addComponent (Entity entity, T component);

        template<typename T>
        T &getComponent(Entity entity);


        template<typename T>
        bool hasComponent(Entity entity);

        const std::vector<Entity> &getEntities() const;
};