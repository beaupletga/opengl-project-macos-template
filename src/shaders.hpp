#ifndef SHADERS_HPP
#define SHADERS_HPP
#ifdef __APPLE__
// Defined before OpenGL and GLUT includes to avoid deprecation messages
#define GL_SILENCE_DEPRECATION
#endif
#include "vendors/GLFW/glfw3.h"
#include <OpenGL/gl3.h>
#include <string>
#include "file.hpp"
#include <iostream>

class ShaderProgram
{
public:
    ShaderProgram(const std::string &vertexShaderFilePath, const std::string &vgeometryShaderFilePath, const std::string &fragmentShaderFilePath);
    ~ShaderProgram();
    void setPass(int pass) const;

    void use() const;

private:
    unsigned int program;
    bool compileShader(unsigned int shaderType, const std::string &shaderSource);
};

#endif