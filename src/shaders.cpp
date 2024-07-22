#include "shaders.hpp"

ShaderProgram::ShaderProgram(const std::string &vertexShaderFilePath, const std::string &vgeometryShaderFilePath, const std::string &fragmentShaderFilePath)
{
    const std::string vertexShaderSource = readFile(vertexShaderFilePath);
    const char *vertexShaderSourcePtr = vertexShaderSource.c_str();
    const std::string geometryShaderSource = readFile(vgeometryShaderFilePath);
    const char *geometryShaderSourcePtr = geometryShaderSource.c_str();
    const std::string fragmentShaderSource = readFile(fragmentShaderFilePath);
    const char *fragmentShaderSourcePtr = fragmentShaderSource.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSourcePtr, NULL);

    unsigned int geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometryShader, 1, &geometryShaderSourcePtr, NULL);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourcePtr, NULL);

    if (!compileShader(vertexShader, vertexShaderSource) || !compileShader(geometryShader, geometryShaderSource) || !compileShader(fragmentShader, fragmentShaderSource))
    {
        throw std::runtime_error("Failed to compile shaders");
    }

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, geometryShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);
    glDeleteShader(fragmentShader);
}

bool ShaderProgram::compileShader(unsigned int shaderType, const std::string &shaderSource)
{
    glCompileShader(shaderType);

    int success;
    char infoLog[512];
    glGetShaderiv(shaderType, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        std::string shaderTypeStr;
        if (shaderType == GL_VERTEX_SHADER)
        {
            shaderTypeStr = "VERTEX";
        }
        else if (shaderType == GL_FRAGMENT_SHADER)
        {
            shaderTypeStr = "FRAGMENT";
        }
        else
        {
            shaderTypeStr = "UNKNOWN";
        }

        glGetShaderInfoLog(shaderType, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << shaderTypeStr << "::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        return false;
    }

    return true;
}

void ShaderProgram::setPass(int pass) const
{
    glUniform1i(glGetUniformLocation(program, "pass"), pass);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(program);
}

void ShaderProgram::use() const
{
    glUseProgram(program);
}