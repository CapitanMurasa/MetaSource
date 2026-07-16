#include <fstream>
#include <sstream>
#include <iostream>

#include "shader.h"
#include "../ui/console.h"

using namespace std;

Shader::Shader(){

}

GLuint Shader::CreateProgram(const char* vertexPath, const char* fragmentPath){
    string vertexCode;
    string fragmentCode;
    ifstream vShaderFile;
    ifstream fShaderFile;

    fpathfrag = std::string(fragmentPath);
    fpathvert = std::string(vertexPath);

    vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        stringstream vShaderStream, fShaderStream;
        
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        
        vShaderFile.close();
        fShaderFile.close();
        
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch (ifstream::failure& e) {
        cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << endl;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    ID = glCreateProgram();
    if (ID){
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
        return ID;
    }
}

void Shader::use() { 
    glUseProgram(ID);
}

/*
void Shader::Cleanup(){
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
*/


void Shader::checkCompileErrors(unsigned int shader, string type) {
    int success;
    char infoLog[1024];
    std::string sourcefile;

    
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            if (type == "VERTEX"){
                sourcefile = fpathvert;
            }
            else if (type == "FRAGMENT"){
                sourcefile = fpathfrag;
            }
            std::string errormessage = "error at " + type + " in shader: " + sourcefile + "\n" + "shader compilation error:" "\n" + infoLog + "\n";
            Console::GetInstance().log(errormessage, ERROR);
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::string errormessage = "error at " + type + "\n" + "program linking error: " + infoLog + "\n";
            Console::GetInstance().log(errormessage, ERROR);
            
        }
    }
}