#pragma once 

#include "Keyboard.h"

class Workflow
{
public:
    explicit Workflow(Keyboard& keyboard) : keyboard(keyboard) {}

    void keypress(const std::string& key);

    void undo();

    void perform();

    void addAction(const Action& action);

private:
    Keyboard& keyboard;
    std::vector<Action> actions; 
};
