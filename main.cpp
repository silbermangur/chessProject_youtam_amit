#include "Manager.h"
#include <iostream>

int main()
{
	int code = 0;
	Manager mana = Manager();
	std::cout << mana.toString() << std::endl;
	code = mana.movePiece(Position(0), Position('a', 3));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
}