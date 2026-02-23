```
Application
   ├── handles window + loop
   ├── updates Triangle
   └── calls Renderer

Triangle
   └── contains Transform + update logic

Renderer
   └── owns VAO/VBO/Shader
   └── draws Triangle

Shader
   └── compiles + manages uniforms
```