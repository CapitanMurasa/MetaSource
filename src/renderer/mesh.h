#pragma once
#include "vertex.h"

#include <GL/glew.h>

class Mesh{
    public:
    GLuint VAO, VBO;
    int vertexCount;

    Mesh(Vertex* vertrices, int count);
    ~Mesh();
    void Draw();
};