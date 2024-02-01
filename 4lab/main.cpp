#include "keyboard.hpp"

int main()
{
    setlocale(LC_ALL, "Rus");

    WorkFlow workFlow;
    Keyboard keyboard = *new Keyboard(workFlow);

    keyboard.setKey("x", []() { std::cout << "The action of the key <x> is completed" << std::endl; }, []() { std::cout << "The action of the key <x> is canceled" << std::endl; });
    keyboard.setKey("a", []() { std::cout << "The action of the key <a> is completed" << std::endl; }, []() { std::cout << "The action of the key <a> is canceled" << std::endl; });
    keyboard.setKey("Ctrl+c", []() { std::cout << "The action of the key <Ctrl+c> is completed" << std::endl; }, []() { std::cout << "The action of the key <Ctrl+c> is canceled" << std::endl; });

    keyboard.pressKey("x");
    keyboard.pressKey("a");
    keyboard.pressKey("Ctrl+c");
    keyboard.undo();
    keyboard.undo();

    //�������������� ������������ �������
    keyboard.setKey("a", []() { std::cout << "����� �������� a" << std::endl; }, []() { std::cout << "����� ������ a" << std::endl; });
    keyboard.pressKey("a");
    keyboard.undo();

    //��� ���� �������������� ������� a
    keyboard.setKey("a", []() { std::cout << "����� ����� �������� a" << std::endl; }, []() { std::cout << "����� ����� ������ a" << std::endl; });
    keyboard.pressKey("a");
    keyboard.undo();

    return 0;
}

