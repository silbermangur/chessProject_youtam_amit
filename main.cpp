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
	code = mana.movePiece(Position('d', 8), Position('e', 8));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position('b', 1), Position('b', 8));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position('e', 8), Position('d', 7));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position('b', 8), Position('a', 8));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position('h', 8), Position('h', 1));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;
	code = mana.movePiece(Position('a', 8), Position('d', 8));
	std::cout << mana.toString() << std::endl;
	std::cout << code << std::endl;

}