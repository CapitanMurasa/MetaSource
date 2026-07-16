#include "console.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

Console::Console(){
}

Console::~Console(){

}

const char* LogTypeToString(LogType type) {
    switch (type) {
        case LogType::INFO:    
        return "INFO";
        case LogType::WARNING: 
        return "WARNING";
        case LogType::ERROR:   
        return "ERROR";
        default:                
        return "UNKNOWN";
    }
}

ImVec4 GetColorForLogType(LogType type) {
    switch (type) {
        case LogType::INFO:    
        return ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // white
        case LogType::WARNING: 
        return ImVec4(1.0f, 0.8f, 0.2f, 1.0f); // yellow
        case LogType::ERROR:   
        return ImVec4(1.0f, 0.3f, 0.3f, 1.0f); // red
        default:                
        return ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    }
}

void Console::Body(){
    if(bShowConsole){
        ImGui::Begin("Console");
        //ImGui::Text("%d", logHistory.size());
        if (logHistory.empty()){
            
        }
        else{
            for(int i = 0; i < logHistory.size(); i++){
                //lastMessageIndex = logHistory.size() - 1;
                Log LastMessage = logHistory[i];
                std::string textToDisplay = "[" + std::string(LogTypeToString(LastMessage.type)) + "]" + " " + LastMessage.text;
                ImGui::TextColored(GetColorForLogType(LastMessage.type), "%s", textToDisplay.c_str());
            }
        }
        ImGui::End();
    }
}

void Console::log(std::string text, LogType type){
    logHistory.push_back({text, type});
}

void Console::Show(){
    bShowConsole = true;
}

void Console::Hide(){
    bShowConsole = false;
}

bool Console::IsActive(){
    return bShowConsole;
}