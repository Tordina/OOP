#include "Keyboard.h"


void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "Unknown key pressed");
    history.push_back(key);
    keymap[key].first();
}


void Keyboard::undo()
{
    if (!history.empty())
    {
        std::cout << "Undo action for key: " << history.back() << "\n";
        keymap[history.back()].second();
        history.pop_back();
    }
}


bool Keyboard::isKeyRegistered(const std::string& key) const
{
    return keymap.count(key) > 0;
}