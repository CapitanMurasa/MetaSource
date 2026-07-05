#define GLEW_STATIC

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "renderer/vertex.h"
#include "renderer/shader.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

bool quit = false;

SDL_Event e;

int main(int argc, char* args[]) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) return -1;


    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


    SDL_Window* window = SDL_CreateWindow("MetaSource", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);


    SDL_GLContext context = SDL_GL_CreateContext(window);


    glewExperimental = GL_TRUE; 
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW failed to initialize!" << std::endl;
        return -1;
    }


    Shader triangleShader;
    GLuint shaderProgram = triangleShader.CreateProgram("../src/renderer/shaders/default.vert", "../src/renderer/shaders/default.frag");

    Vertex cube[] = {
        // Front face (Red)
        {-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f}, { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f}, { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f},
        { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f}, {-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f}, {-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f},
        // Back face (Green)
        {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f}, { 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f}, { 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f},
        { 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f}, {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f}, {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f},
        // Left face (Blue)
        {-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f}, {-0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f}, {-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f},
        {-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f}, {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f}, {-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f},
        // Right face (Yellow)
        { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f}, { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f}, { 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f},
        { 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f}, { 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f}, { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f},
        // Top face (Cyan)
        {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f}, { 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f}, { 0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f},
        { 0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f}, {-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f}, {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f},
        // Bottom face (Magenta)
        {-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f}, { 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f}, { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f},
        { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f}, {-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f}, {-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f}
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glEnable(GL_DEPTH_TEST);

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        triangleShader.use();
        glBindVertexArray(VAO);

        int uni_loc = glGetUniformLocation(shaderProgram, "src_aspect");
        glUniform1f(uni_loc, (float)SCREEN_HEIGHT / SCREEN_WIDTH);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}