# Luke structure

## Ordem a fazer

- [x] Window + GLAD
- [x] Shader
- [x] Buffers (VAO/VBO/EBO)
- [x] Mesh
- [x] Transform
- [ ] ECS mínimo
- [ ] RenderSystem
- [ ] Camera
- [ ] Scene
- [ ] ResourceManager

## Estrutura

``` bash
Luke/
│
├── core/
│   ├── Application.hpp
│   ├── Window.hpp
│   ├── Time.hpp
│   ├── Input.hpp
│
├── ecs/
│   ├── Entity.hpp
│   ├── Component.hpp
│   ├── Registry.hpp
│   ├── components/
│   │    ├── Transform.hpp
│   │    ├── MeshRenderer.hpp
│   │    ├── CameraComponent.hpp
│   │    ├── LightComponent.hpp
│   └── systems/
│        ├── MovementSystem.hpp
│        ├── RenderSystem.hpp
│        ├── InputSystem.hpp
│        └── PhysicsSystem.hpp
│
├── rendering/
│   ├── Renderer.hpp
│   ├── RenderCommand.hpp
│   ├── RenderQueue.hpp
│   ├── Framebuffer.hpp
│   ├── Skybox.hpp
│   ├── Material.hpp
│   ├── Shader.hpp
│   ├── Texture.hpp
│   ├── Mesh.hpp
│   ├── MeshFactory.hpp
│   ├── VertexArray.hpp
│   ├── VertexBuffer.hpp
│   ├── IndexBuffer.hpp
│   └── pipeline/
│        ├── RenderPass.hpp
│        ├── ForwardPass.hpp
│        ├── ShadowPass.hpp
│        └── WaterPass.hpp
│
│
├── scene/
│   ├── Scene.hpp
│   ├── SceneManager.hpp
│   └── scenes/
│        ├── Level1.hpp
│        ├── Level2.hpp
│        └── Pause.hpp
│
├── resources/
│   └── ResourceManager.hpp
│
└── main.cpp
```
