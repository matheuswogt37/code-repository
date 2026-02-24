#include "../external/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include "graphics/Renderer.hpp"

std::vector<float> createCircle(float radius, int segments)
{
    std::vector<float> vertices;

    for (int i = 0; i < segments; i++)
    {
        float angle1 = 2.0f * 3.1415926f * i / segments;
        float angle2 = 2.0f * 3.1415926f * (i+1) / segments;

        vertices.push_back(0.0f);
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);

        vertices.push_back(radius * cos(angle1));
        vertices.push_back(radius * sin(angle1));
        vertices.push_back(0.0f);

        vertices.push_back(radius * cos(angle2));
        vertices.push_back(radius * sin(angle2));
        vertices.push_back(0.0f);
    }

    return vertices;
}

std::shared_ptr<Mesh> createSquare(float size)
{
    float h = size / 2.0f;

    std::vector<float> vertices = {
        -h, -h, 0.0f,  // 0
         h, -h, 0.0f,  // 1
         h,  h, 0.0f,  // 2
        -h,  h, 0.0f   // 3
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3
    };

    return std::make_shared<Mesh>(vertices, indices);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Generic Renderer", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Renderer renderer;

    std::vector<float> triangleVerts = {
        -0.5f,-0.5f,0.0f,
         0.5f,-0.5f,0.0f,
         0.0f, 0.5f,0.0f
    };

    auto triangleMesh = std::make_shared<Mesh>(triangleVerts);
    auto circleMesh = std::make_shared<Mesh>(createCircle(0.4f, 40));
    auto squareMesh = createSquare(0.6f);

    GameObject triangle;
    triangle.mesh = triangleMesh;
    triangle.material.color = {1,0,0,1};

    GameObject circle;
    circle.mesh = circleMesh;
    circle.transform.position = {0.5f,0.0f};
    circle.material.color = {0,0.6f,1,1};

    GameObject square;
    square.mesh = squareMesh;
    square.transform.position = {0.2f, 0.3f};
    square.material.color = {0,1,0,1};

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f,0.1f,0.15f,1);
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.transform.rotation += 0.5f;

        renderer.draw(circle);
        renderer.draw(triangle);
        renderer.draw(square);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}