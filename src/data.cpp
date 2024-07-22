#include "data.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

#include <iostream>

float getRandomNumber(int min, int max)
{
    float r = (float)rand() / (float)RAND_MAX;
    return min + r * (max - min);
}

void setDepthMap(float *vertices, int size)
{
    const int width = std::sqrt(size);
    const int height = std::sqrt(size);

    int k = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float x = (j / (width - 1.0)) * 2.0 - 1.0;
            float y = (i / (height - 1.0)) * 2.0 - 1.0;
            // std::cout << x << std::endl;
            float z = getRandomNumber(-1, 1);

            vertices[k] = x;
            vertices[k + 1] = y;
            vertices[k + 2] = z;
            k += 3;
        }
    }
}

void setIndices(int *indices, int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        indices[i] = index;
        index += 3;
    }
}