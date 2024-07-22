#include "renderer.hpp"

void render(GLFWwindow *window, ShaderProgram &shaderProgram, unsigned int &VBO, unsigned int &VAO, unsigned int &EBO, int N)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.f);

    shaderProgram.use();
    shaderProgram.setPass(1);
    glBindVertexArray(VAO);
    glDrawElements(GL_POINTS, N, GL_UNSIGNED_INT, 0);
}