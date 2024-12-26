#include "Manager.h"
#include <iostream>
#define BOARD_SIZE 8

Manager::Manager()
{
	
}

std::string Manager::toString() const
{
	int i = 0;
	int j = 0;
	std::string string;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j])
			{
				string += board[i][j]->toChar();
				string += " ";
			}
			else
			{
				string += '#';
				string += "  ";
			}
		}
	}
	return string;
}

bool Manager::addPiece(Piece& piece, Position position)
{
	board[0][position.turnToNum()] = &piece;
}

void Manager::removePiece(Position position)
{
	delete board[0][position.turnToNum()];
	board[0][position.turnToNum()] = NULL;
}

char Manager::checkForPiece(Position position)
{
	board[0][position.turnToNum()]->toChar();
}

int Manager::movePiece(Position src, Position dst) 
{

}
