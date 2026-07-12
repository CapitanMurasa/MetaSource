#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera{

    public:
    Camera(int ScreenHeight, int ScreenWidth);
    ~Camera();

    void ChangeRotation(glm::vec3 rotation);
    void ChangePerspective();
    glm::mat4 returnView();
    glm::mat4 returnPerspective();

    protected:
    glm::mat4 view;
    glm::mat4 perspective;
    int SCREEN_WIDTH = 0;
    int SCREEN_HEIGHT = 0;
    float FOV = 0.0f;
    float viewZ = 0.0f;
    float CamrotX = 0.0f;
    float CamrotY = 0.0f;
};