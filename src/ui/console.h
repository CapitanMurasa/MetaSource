#pragma once
#include <string>
#include <vector>

#include "../core/engine.h"
#include "../renderer/shader.h"

class Engine;

enum LogType{
    INFO,
    WARNING,
    ERROR
};

struct Log
{
    std::string text;
    LogType type;
};


class Console{

    public:
    Console(const Console&) = delete;
    Console& operator=(const Console&) = delete;

    static Console& GetInstance() {
        static Console instance;
        return instance;
    }

    void Show();
    void Hide();
    bool IsActive();
    void log(std::string text, LogType type);
    void Body();

    private:
    Console();
    ~Console();

    std::vector<Log> logHistory = {};
    int lastMessageIndex = 0;
    bool bShowConsole = false;

};