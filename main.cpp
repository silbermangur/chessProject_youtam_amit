#include "Manager.h"
#include <iostream>

int main()
{
	int code = 0;
	Manager mana = Manager();
	std::cout << mana.toString() << std::endl;
	code = mana.movePiece(Position(0), Position(1));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position(0), Position(1));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position(63), Position(62));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position(1), Position('b', 8));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position(62), Position('g', 1));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
}