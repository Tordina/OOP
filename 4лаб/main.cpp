#include "Workflow.h"
#include "Keyboard.h"

int main()
{
    SetConsoleOutputCP(1251); 
    Keyboard keyboard; 

    keyboard.registerKey("A", []() { std::cout << "Key A pressed\n"; }, []() { std::cout << "Key A action undone\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C pressed\n"; }, []() { std::cout << "Ctrl+C action undone\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V pressed\n"; }, []() { std::cout << "Ctrl+V action undone\n"; });


    Workflow workflow(keyboard);


    workflow.addAction([&]() { workflow.keypress("A"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+C"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+V"); });
    workflow.addAction([&]() { workflow.undo(); });
    workflow.addAction([&]() { workflow.undo(); });

    std::cout << "������ ������...\n";
    workflow.perform();

    std::cout << "\n�������������� ������ � ���������� ��������...\n";
    keyboard.registerKey("A", []() { std::cout << "Key A ������ ������� ��� ���������\n"; }, []() { std::cout << "Undo action for A\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C ������ ������ �� ������\n"; }, []() { std::cout << "Undo action for Ctrl+C\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V ������ ������� ������\n"; }, []() { std::cout << "Undo action for Ctrl+V\n"; });

    workflow.perform();

    if (keyboard.isKeyRegistered("Ctrl+V"))
    {
        std::cout << "������� Ctrl+V ���������������� � �������\n";
    }

    return 0;
}
