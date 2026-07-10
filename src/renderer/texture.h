#pragma once
#include <GL/glew.h>
#include <string>
#include <iostream>

class Texture{
    public:

    Texture(const std::string& path);
    //~Texture();

    void Bind();
    void Unbind();

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }

    private:
    GLuint ID;
    unsigned int texture;
    int width, height, nrChannels;
};