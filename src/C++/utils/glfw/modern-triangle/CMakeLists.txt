cmake_minimum_required(VERSION 3.16)
project(TriangleApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

include_directories(
    external/glad/include 
    src
)

add_executable(app 
    src/main.cpp

    src/objects/Triangle.cpp
    src/graphics/Renderer.cpp
    src/graphics/Shader.cpp

    external/glad/src/glad.c
)

target_link_libraries(app
    OpenGL::GL
    glfw
    glm::glm
)
