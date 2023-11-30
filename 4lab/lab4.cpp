#include "lab4.hpp"
//1) Создать виртуальную клавиатуру с переназначаемыми действиями для клавиш и комбинаций клавиш, с возможностью отката действий назад.
//2) Продемонстрировать работу клавиатуры сделав Workflow из нажатий различных комбинаций клавиш и откатов назад.
//Симулировать демонстрацию нажатий клавиш путем вывода значения в консоль и задержкой между нажатиями
//3) Продемонстрировать переназначение клавиши и комбинации клавиш с перезапуком Workflow


namespace DT
{
    

    Keyboard::Keyboard() = default;

    Keyboard::~Keyboard()
    {

    }
   
    void Keyboard::addCommand(const std::string& key, const std::string& command)
    {
        _commands.insert({ key, command });
        _keys += key;
    }

    void Keyboard::pressKey(const std::string& key)
    {
        std::cout << "Команда для ключа '" << key << "': " << _commands[key] << std::endl;
    }

   
    void Keyboard::workflow(const std::string& strKey)
    {
        splitKeys(strKey); 
        for (const auto& i : _keysV)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });
            std::cout << "Выполнение команды для ключа '" << i << "': " << _commands[i] << std::endl;
        }
        std::cout << "Workflow закончил свою работу" << std::endl; 
        std::cout << "------------------------------------------------------------------------------------------" << std::endl; 
    }
  

    void Keyboard::undoLastCommand()
    {
        if (!_keysV.empty())
        {
            _keysV.pop_back();
            for (const auto& i : _keysV)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
                std::cout << "undoLastCommand -Выполнение команды для ключа  '" << i << "': " << _commands[i] << std::endl;
            }
            std::cout << "undoLastCommand закончил свою работу" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
        }
        
        else
        {
            std::cout << "Нет действия для undoLastCommand" << std::endl; 
        }
    }
   
    void Keyboard::splitKeys(std::string keys)
    {
        std::stringstream keyssStringstream(keys); 
        std::string str;
        while (getline(keyssStringstream, str, ' ')) 
        {
            _keysV.push_back(str); 
        }
    }
}