#include "core/engine.h"

Engine engine;

int main(int argc, char* args[]) {

    if(!engine.Init()){
        return 1;
    }

    engine.Run();

    engine.Shutdown();

    return 0;
}