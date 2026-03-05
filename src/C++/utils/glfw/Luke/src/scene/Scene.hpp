#pragma once
#include "../ecs/Registry.hpp"
#include "../ecs/systems/RenderSystem.hpp"
#include "../ecs/systems/MovementSystem.hpp"
#include "../ecs/systems/InputSystem.hpp"
#include "../ecs/systems/PhysicsSystem.hpp"

class Scene {
    protected:
        Registry registry;

        RenderSystem renderSystem;
        MovementSystem movementSystem;
        InputSystem inputSystem;
        PhysicsSystem physicsSystem;
    public:
        virtual ~Scene() = default;

        virtual void start();
        virtual void update(float dt);
        virtual void render();

        Registry &getRegistry();
};