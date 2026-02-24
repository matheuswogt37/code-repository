cmake_minimum_required(VERSION 3.16)
project(GenericRenderer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

include_directories(
    external/glad/include 
    src
)

add_executable(app
    src/main.cpp
    src/graphics/Shader.cpp
    src/graphics/Mesh.cpp
    src/graphics/Renderer.cpp
    src/math/Transform.cpp
    external/glad/src/glad.c
)

target_include_directories(app PRIVATE include)

target_link_libraries(app PRIVATE
    glfw
    OpenGL::GL
    glm::glm
)