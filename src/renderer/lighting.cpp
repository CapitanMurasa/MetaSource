#include "lighting.h"

#include <iostream>


lighting::lighting(){
    lighthingShader = new Shader();
    shaderProgram = lighthingShader->CreateProgram("../src/renderer/shaders/lighting.vert", "../src/renderer/shaders/lighting.frag");

    lightSourceShader = new Shader();
    shaderSourceProgram = lightSourceShader->CreateProgram("../src/renderer/shaders/lightsource.vert", "../src/renderer/shaders/lightsource.frag");

    Cube = new Mesh(square, 36);

    
    srcColorLoc = glGetUniformLocation(shaderProgram, "Color");
    srcModelLoc = glGetUniformLocation(shaderProgram, "model");
    srcViewLoc = glGetUniformLocation(shaderProgram, "view");
    srcProjLoc = glGetUniformLocation(shaderProgram, "projection");
    srcAmbient = glGetUniformLocation(shaderProgram, "AmbientLight");


    objColorLoc = glGetUniformLocation(shaderSourceProgram, "lightColor");
    objModelLoc = glGetUniformLocation(shaderSourceProgram, "model");
    objViewLoc = glGetUniformLocation(shaderSourceProgram, "view");
    objProjLoc = glGetUniformLocation(shaderSourceProgram, "proj");
}

void lighting::light(glm::vec3 color, glm::mat4 model, glm::mat4 view, glm::mat4 proj){
    lighthingShader->use();

    /*
    std::cout << srcColorLoc << std::endl;
    std::cout << srcModelLoc << std::endl;
    std::cout << srcViewLoc << std::endl;
    std::cout << srcProjLoc << std::endl;
    std::cout << srcAmbient << std::endl;
    */

    glUniform3f(srcColorLoc, color.x, color.y, color.z);
    glUniform3f(srcAmbient, 0.15, 0.15, 0.15);
    glUniformMatrix4fv(srcModelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(srcViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(srcProjLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

void lighting::SetuplightingSource(glm::vec3 color, glm::mat4 model, glm::mat4 view, glm::mat4 proj){
    lightSourceShader->use();
    
    glUniform3f(objColorLoc, color.x, color.y, color.z);
    glUniformMatrix4fv(objModelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(objViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(objProjLoc, 1, GL_FALSE, glm::value_ptr(proj));

    Cube->Draw();
}