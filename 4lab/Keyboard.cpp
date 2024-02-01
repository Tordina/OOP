#include "keyboard.hpp"

void Keyboard::pressKey(const std::string& key)
{

    if (!isKey(key))
    {
        std::cout << std::endl << "You pressed >" << key << "< There is no such key" << std::endl;
        return;
    }

    workFlow.addKeyPressed(key);
    keysPressed.push(key);
    keyMap[key].first();

    std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
}

void Keyboard::undo()
{
    if (keysPressed.empty()) return;

    const std::string key = keysPressed.top();
    workFlow.addUndo(key);
    keyMap[key].second();
    keysPressed.pop();

    std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
}

void Keyboard::setKey(const std::string& key, const std::function<void()>& action,
    const std::function<void()>& undoAction)
{
    keyMap[key] = { action, undoAction };
}

bool Keyboard::isKey(const std::string& key) const
{
    return keyMap.count(key) > 0;
}

