#include <functional>
#include <map>
#include <iostream>
#include <stack>
#include <thread>

#include "Workflow.hpp"
using Action = std::function<void()>;
using Keymap = std::map<std::string, std::pair<Action, Action>>;
class Keyboard
{
public:
    Keyboard(WorkFlow workFlow) : workFlow(workFlow) {};
    void setKey(const std::string& key, const std::function<void()>& action, const std::function<void()>& undoAction = []() {});
    void pressKey(const std::string& key);
    void undo();
    bool isKey(const std::string& key) const;

private:
    WorkFlow workFlow;
    std::map<std::string, std::pair< std::function<void()>, std::function<void()>>> keyMap;
    std::stack<std::string> keysPressed;
};
