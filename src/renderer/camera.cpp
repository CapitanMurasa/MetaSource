#include "camera.h"

Camera::Camera(int ScreenHeight, int ScreenWidth) 
    : SCREEN_HEIGHT(ScreenHeight), SCREEN_WIDTH(ScreenWidth) {
}

Camera::~Camera(){

}

void Camera::ChangeRotation(glm::vec3 rotation){
    CamrotX += rotation.x;
    CamrotY += rotation.y;

    /*
    if (CamrotY > 89.0f) {
        CamrotY = 89.0f;
    }
    if (CamrotY < -89.0f) {
        CamrotY = -89.0f;
    }
    */
}

glm::mat4 Camera::returnView(){
    view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -7.0f));
    view = glm::rotate(view, glm::radians(CamrotX), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, glm::radians(CamrotY), glm::vec3(0.0f, 1.0f, 0.0f));
    return view;
}

glm::mat4 Camera::returnPerspective(){
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
    return projection;
}