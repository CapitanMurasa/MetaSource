#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h> 

class Shader {
public:
    unsigned int ID; 

    Shader();
    
    void use();
    
    GLuint CreateProgram(const char* vertexPath, const char* fragmentPath);
    //void setBool(const std::string &name, bool value) const;
    //void setInt(const std::string &name, int value) const;
    //void setFloat(const std::string &name, float value) const;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
    std::string fpathvert, fpathfrag;
};

#endif