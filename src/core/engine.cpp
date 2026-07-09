#define GLEW_STATIC

#include "engine.h"

Engine::Engine(){

}

bool Engine::Init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;


    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


    window = SDL_CreateWindow("MetaSource", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);


    context = SDL_GL_CreateContext(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark(); 

    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 330 core");


    glewExperimental = GL_TRUE; 
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW failed to initialize!" << std::endl;
        return false;
    }

    mainCam = new Camera(SCREEN_HEIGHT, SCREEN_WIDTH);
    CubeShader = new Shader();
    cubeShader = CubeShader->CreateProgram("../src/renderer/shaders/default.vert", "../src/renderer/shaders/default.frag");
    GridShader = new Shader();
    gridShader = GridShader->CreateProgram("../src/renderer/shaders/grid.vert", "../src/renderer/shaders/grid.frag");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(1);

    glGenVertexArrays(1, &emptyVAO);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

void Engine::Run(){
    bool bIsRunning = true;

    while (bIsRunning){
        if (!ProcessInput()){
            return;
        }
        Render();
    }
}

bool Engine::ProcessInput() {
    SDL_Event e;
    
    while (SDL_PollEvent(&e)) {
        ImGui_ImplSDL2_ProcessEvent(&e);
        
        if (e.type == SDL_QUIT) {
            return false; 
        }
    }
    
    return true; 
}

void Engine::Render(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Renderer Controls");
    ImGui::Text("test yo");

    ImGui::SliderFloat("Cube rotation x", &rotX, -1.0f, 1.0f);
    ImGui::SliderFloat("Cube rotation y", &rotY, -1.0f, 1.0f);

    //ImGui::SliderFloat("Camera view Z", &viewZ, -10.0f, 0.0f);
    ImGui::SliderFloat("Camera Rotation X", &CamrotX, -180.0f, 180.0f);
    ImGui::SliderFloat("Camera Rotation Y", &CamrotY, -180.0f, 180.0f);

    if (ImGui::Button("Turn on grid")){
        bEnableGrid = !bEnableGrid;
    }

    ImGui::End();

    mainCam->ChangeView(glm::vec3(CamrotX, CamrotY, 0.0f));

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    CubeShader->use();
    glBindVertexArray(VAO);

    glm::mat4 model = glm::mat4(1.0f);
    float timeValue = SDL_GetTicks() / 1000.0f; 
    model = glm::rotate(model, timeValue, glm::vec3(rotX, rotY, 0.0f)); 

    glm::mat4 view = mainCam->returnView();

    glm::mat4 projection = mainCam->returnPerspective();

    int modelLoc = glGetUniformLocation(cubeShader, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    int viewLoc = glGetUniformLocation(cubeShader, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    int projLoc = glGetUniformLocation(cubeShader, "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glDrawArrays(GL_TRIANGLES, 0, 36);
    if (bEnableGrid){
        GridShader->use();
        glBindVertexArray(emptyVAO);

        glUniformMatrix4fv(glGetUniformLocation(gridShader, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(gridShader, "view"), 1, GL_FALSE, glm::value_ptr(view));

        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

void Engine::Shutdown(){
    delete mainCam;
    delete CubeShader;
    delete GridShader;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}