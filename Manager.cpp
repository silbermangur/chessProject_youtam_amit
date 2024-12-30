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

/*
desc: function to determine if a square is safe or not (if a piece of the opposite color can move there)
input: 
	Position square: the square to check for whether it is safe or not
	char col: the player's color (checks for opposite color)
output: bool of whether the square is safe or not
*/
bool Manager::isSquareSafe(Position square, char col)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++) // loop for the whole board
		{
			if (board[i][j] != nullptr && board[i][j]->getColor() != col) // if for if the square is occupied by a piece of the opposite color
			{
				if (board[i][j]->checkMove(square, *this) == 0) // if it can move to the square it will return false
				{
					return false;
				}
			}
		}
	}
	return true; // if there isnt a piece that can move there return true
}