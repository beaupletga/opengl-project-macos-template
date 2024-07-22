#ifndef OPENGL_SETUP_HPP
#define OPENGL_SETUP_HPP

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include "vendors/GLFW/glfw3.h"
#include <OpenGL/gl3.h>

void initializeGL();
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void setupVertexDataAndBuffers(unsigned int &VBO, unsigned int &VAO, unsigned int &EBO, float *vertices, int *indices, size_t vertexSize, size_t indexSize);
void cleanup(unsigned int &VBO, unsigned int &VAO, unsigned int &EBO);

#endif