#include "file.hpp"

std::string readFile(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::in | std::ios::binary);
    std::string contents;

    if (file.is_open())
    {
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        contents.resize(size);
        file.seekg(0, std::ios::beg);
        file.read(&contents[0], size);
        file.close();
    }
    else
    {
        std::cerr << "Failed to open file: " << filePath << std::endl;
    }

    return contents;
}