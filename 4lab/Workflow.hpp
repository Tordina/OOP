#include <vector>
#include <iostream>
#include <iomanip>

class WorkFlow
{
public:
    void addKeyPressed(const std::string& key);
    void addUndo(const std::string& key);
};
