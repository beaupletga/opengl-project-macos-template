#include <iostream>
#include "data.hpp"
#include "shaders.hpp"
#include "renderer.hpp"
#include "opengl_setup.hpp"
#include <cmath>

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
const unsigned int N = SCR_WIDTH * SCR_HEIGHT;

int main()
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    initializeGL();

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    ShaderProgram shaderProgram("./src/shaders/vertex.glsl","./src/shaders/geometry.glsl", "./src/shaders/fragment.glsl");

    float vertices[N * 3];
    int indices[N];
    setDepthMap(vertices, N);
    setIndices(indices, N);

    unsigned int VBO, VAO, EBO;
    setupVertexDataAndBuffers(VBO, VAO, EBO, vertices, indices, N * 3 * sizeof(float), N * sizeof(int));

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        render(window, shaderProgram, VBO, VAO, EBO, N);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cleanup(VBO, VAO, EBO);
    glfwTerminate();

    return 0;
}
