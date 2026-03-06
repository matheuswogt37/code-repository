cmake_minimum_required(VERSION 3.16)
project(MyProject VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.4 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    external/glad/include
    src
)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

set(GLAD_SRC external/glad/src/glad.c)

add_executable(app ${SOURCES} ${GLAD_SRC})

target_link_libraries(app
        PRIVATE
        glfw
        OpenGL::GL
)