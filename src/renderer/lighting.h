#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "shapes.h"
#include "vertex.h"
#include "mesh.h"

class lighting{
    public:
    lighting();

    void light(glm::vec3 color, glm::mat4 model, glm::mat4 view, glm::mat4 proj);
    void SetuplightingSource(glm::vec3 color, glm::mat4 model, glm::mat4 view, glm::mat4 proj);

    private:
    glm::vec3 col;
    glm::vec3 Ambient = glm::vec3(0.15, 0.15, 0.15);
    glm::vec3 LightPos;

    GLuint objColorLoc, objModelLoc, objViewLoc, objProjLoc;
    GLuint srcColorLoc, srcModelLoc, srcViewLoc, srcProjLoc, srcAmbient, srcLightpos, srcTransposeInvModel, srcViewPosLoc;
    
    Shader* lighthingShader;
    Shader* lightSourceShader;
    GLuint shaderProgram, shaderSourceProgram;
    Mesh* Cube;
};