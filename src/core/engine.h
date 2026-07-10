#pragma once

#include <iostream>
#include <cstddef>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include "../renderer/vertex.h"
#include "../renderer/shader.h"
#include "../renderer/shapes.h"
#include "../renderer/camera.h"
#include "../renderer/texture.h"

class Engine{
    public:

    Engine();

    bool Init();

    void Run();

    void Shutdown();

    bool ProcessInput();

    void Update();

    void Render();

    protected:
    int SCREEN_WIDTH = 1280;
    int SCREEN_HEIGHT = 720;

    bool bEnableGrid = false;
    bool bIsDragging = false;

    unsigned int VAO, VBO;
    unsigned int emptyVAO;

    float rotX = 0.0f;
    float rotY = 0.0f;
    float CamrotX = 0.0f;
    float CamrotY = 0.0f;

    float yaw = 0.0f;   
    float pitch = 0.0f;
    float sensetivity = 0.9f;

    double lastTime;
    int frameCount = 0;
    float fps = 0.0f;

    private:
    GLuint cubeShader;
    GLuint gridShader;

    SDL_Window* window;
    SDL_GLContext context;

    Camera* mainCam;
    Shader* CubeShader;
    Shader* GridShader;
    Texture* MeishoDoto;
};