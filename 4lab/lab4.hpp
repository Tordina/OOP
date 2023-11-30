#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <chrono>

namespace DT
{
	
	class Keyboard
	{
	
	public:
		
		Keyboard(); 
		~Keyboard(); 

		void addCommand(const std::string& key, const std::string& command); 
		void pressKey(const std::string& key); 
		void workflow(const std::string& strKey); 
		void undoLastCommand(); 

	private:
		std::string _keys, _pressedKey; 
		std::vector<std::string> _keysV; 
		std::unordered_map<std::string, std::string> _commands; 

		void splitKeys(std::string keys); 
	};
}