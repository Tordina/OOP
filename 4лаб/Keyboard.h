#pragma once 

#include <iostream>
#include <functional>
#include <deque>
#include <thread>
#include <chrono>
#include <map>
#include <cassert>
#include <vector>
#include <windows.h>


using Action = std::function<void()>;
using Keymap = std::map<std::string, std::pair<Action, Action>>;

class Keyboard
{
public:
    void registerKey(const std::string& key, const Action& action, const Action& undoAction = []() {})
    {
        keymap[key] = { action, undoAction };
    }
    void pressKey(const std::string& key);

    void undo();

    bool isKeyRegistered(const std::string& key) const;

private:
    Keymap keymap;
    std::deque<std::string> history; 
};

