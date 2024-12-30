#include "Manager.h"
#include <iostream>
#define BOARD_SIZE 8
#define ILLEGAL_INDEX 5
#define ILLEGAL_MOVE 6
#define EQU_SRC_AND_DST 7
#define INVALID_SOURCE 2
#define VALID_MOVE 0
#define CHECK_OPP 1

Manager::Manager()
{
	this->turn = 'w';
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

void Manager::addPiece(Piece& piece, Position position)
{
	board[0][position.turnToNum()] = &piece;
}

void Manager::removePiece(Position position)
{
	delete board[0][position.turnToNum()];
	board[0][position.turnToNum()] = NULL;
}

char Manager::checkForPiece(Position position) const
{
	return board[0][position.turnToNum()]->toChar();
}

int Manager::movePiece(Position src, Position dst) 
{
	//making sure the src and dst positions are not the same
	if (src == dst)
	{
		return EQU_SRC_AND_DST;
	}
	//making sure both the src and dst are in bounds
	if (!src.checkBounds() || !dst.checkBounds())
	{
		return ILLEGAL_INDEX;
	}
	//making sure the src has a piece in the color of the current player's turn
	if (board[0][src.turnToNum()] == nullptr)
	{
		return INVALID_SOURCE;
	}
	if (board[0][src.turnToNum()]->getColor() != this->turn)
	{
		return INVALID_SOURCE;
	}
	if (board[0][src.turnToNum()]->move(dst, *this) == VALID_MOVE)
	{
		//moving the piece on the board, making sure to delete the piece in the dst if there is one
		if (board[0][dst.turnToNum()] != nullptr)
		{
			delete board[0][dst.turnToNum()];
		}
		//moving the pointer to the dst and removing it from the src
		board[0][dst.turnToNum()] = board[0][src.turnToNum()];
		board[0][src.turnToNum()] = nullptr;
		//changing the turn for a second just to see if the move cause a check
		changeTurn();
		if (this->isSquareSafe(this->findOppKing(), turn))
		{
			//changing the turn back
			changeTurn();
			return CHECK_OPP;
		}
		changeTurn();
	}
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

/*
desc: switches the turn from white to black and other way around
input: none
output: none
*/
void Manager::changeTurn()
{
	if (this->turn == 'b')
	{
		this->turn = 'w';
	}
	else
	{
		this->turn = 'b';
	}
}

/*
desc: finds the king of the opponent(the player whose not current turn)
input: none
output: the position
*/
Position Manager::findOppKing() const
{
	char typeToLookFor = 'k';
	int i = 0;
	//getting the type of the king
	if (this->turn == 'w')
	{
		typeToLookFor = 'K';
	}
	//searching for it in the board
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if (board[0][i]->getType() == typeToLookFor)
		{
			break;
		}
	}
	//turning the i from index to position
	return Position(i % BOARD_SIZE + 'a', i / BOARD_SIZE + 1);
}
