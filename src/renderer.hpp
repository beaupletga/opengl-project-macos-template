#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shaders.hpp"

void render(GLFWwindow *window, ShaderProgram &shaderProgram, unsigned int &VBO, unsigned int &VAO, unsigned int &EBO, int N);

#endif