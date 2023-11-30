
#include "lab4.hpp"

int main()
{

	DT::Keyboard key;
	setlocale(LC_ALL, "Russian");
	key.addCommand("ctrl+v", "insert");
	key.addCommand("ctrl+x", "cut");
	key.addCommand("ctrl+c", "copy");

	key.workflow("ctrl+v ctrl+c ctrl+x ctrl+c ");
	key.undoLastCommand();

	return 0;

}