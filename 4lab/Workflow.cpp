#include "Workflow.hpp"

void WorkFlow::addKeyPressed(const std::string& key)
{
    std::cout << std::endl << "You pressed: " + key << std::endl;
}

void WorkFlow::addUndo(const std::string& key)
{
    std::cout << std::endl << "Undo action of key: " + key << std::endl;
}
