#include "Manager.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include <iostream>
#define BOARD_SIZE 8
#define ILLEGAL_INDEX 5
#define ILLEGAL_MOVE 6
#define EQU_SRC_AND_DST 7
#define OWN_CAPTURE 3
#define INVALID_SOURCE 2
#define MOVE_MAKES_CHECK 4
#define VALID_MOVE 0
#define CHECK_OPP 1

Manager::Manager()
{
	int i = 0;
	this->turn = 'w';
	this->totalMoves = 0;
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		board[0][i] = nullptr;
	}
	board[0][0] = new Rook('w', Position('a', 1));
	board[0][7] = new Rook('w', Position('h', 1));
	board[7][0] = new Rook('b', Position('a', 8));
	board[7][7] = new Rook('b', Position('h', 8));
	board[0][2] = new Bishop('w', Position('c', 1));
	board[0][5] = new Bishop('w', Position('f', 1));
	board[7][2] = new Bishop('b', Position('c', 8));
	board[7][5] = new Bishop('b', Position('f', 8));
	board[0][1] = new Knight('w', Position('b', 1));
	board[0][6] = new Knight('w', Position('g', 1));
	board[7][1] = new Knight('b', Position('b', 8));
	board[7][6] = new Knight('b', Position('g', 8));
	board[0][3] = new King('w', Position('d', 1));
	board[7][3] = new King('b', Position('d', 8));
	board[0][4] = new Queen('w', Position('e', 1));
	board[7][4] = new Queen('b', Position('e', 8));
	//setting up the pawns
	for (i = 0; i < BOARD_SIZE; i++)
	{
		board[1][i] = new Pawn('w', Position('a' + i, 2));
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		board[6][i] = new Pawn('b', Position('a' + i, 7));
	}
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
			if (board[i][j] != nullptr)
			{
				string += board[i][j]->toChar();
			}
			else
			{
				string += '#';
			}
		}
	}
	return string;
}

void Manager::addPiece(Piece& piece, Position position)
{
	board[0][position.turnToNum()] = &piece;
}

char Manager::checkForPiece(Position position) const
{
	return board[0][position.turnToNum()]->toChar();
}

int Manager::movePiece(Position src, Position dst) 
{
	Piece* tempPiece = nullptr;
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
	//making sure there isnt a piece of the player's color in the dst
	if (board[0][dst.turnToNum()] != nullptr && board[0][dst.turnToNum()]->getColor() == this->turn)
	{
		return OWN_CAPTURE;
	}
	if (board[0][src.turnToNum()]->move(dst, *this) == VALID_MOVE)
	{
		//moving the piece on the board, making sure to save the piece in the dst if there is one, to later delete it
		if (board[0][dst.turnToNum()] != nullptr)
		{
			tempPiece = board[0][dst.turnToNum()];
		}
		//moving the pointer to the dst and removing it from the src
		board[0][dst.turnToNum()] = board[0][src.turnToNum()];
		board[0][src.turnToNum()] = nullptr;
		//checking if the move cause a check on the player
		changeTurn();
		if (!this->isSquareSafe(this->findOppKing(), this->oppColor()))
		{
			//if the move cause a check, reveting to turn back
			changeTurn();
			//reverting the changes made to the board
			board[0][src.turnToNum()] = board[0][dst.turnToNum()];
			board[0][dst.turnToNum()] = tempPiece;
			tempPiece = nullptr;
			//reverting the piece's position
			board[0][src.turnToNum()]->setPos(src.toString());
			return MOVE_MAKES_CHECK;
		}
		else if (tempPiece != nullptr)
		{
			//if the move didnt cause a check, deleting the memory of the captured piece
			delete tempPiece;
			tempPiece = nullptr;
		}
		//checking if the move checked the opponet
		changeTurn();
		if (this->isSquareSafe(this->findOppKing(), this->oppColor())==false)
		{
			changeTurn();
			return CHECK_OPP;
		}
		changeTurn();
		return VALID_MOVE;
	}
}

/*
desc: function to determine if a square is safe or not (if a piece of the opposite color can move there)
input: 
	Position square: the square to check for whether it is safe or not
	char col: the player's color (checks for opposite color)
output: bool of whether the square is safe or not
*/
bool Manager::isSquareSafe(Position square, char col) const
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
desc: gives the color of the player whose not in turn
input: none
output: the color of the opponent
*/
char Manager::oppColor() const
{
	if (turn == 'w')
	{
		return 'b';
	}
	else
	{
		return 'w';
	}
}

/*
desc: finds the king of the opponent(the player whose not current turn)
input: none
output: the position
*/
Position Manager::findOppKing() const
{
	int i = 0;
	//searching for the king in the board
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if (board[0][i] != nullptr && board[0][i]->getType() == 'k' && board[0][i]->getColor() == oppColor())
		{
			break;
		}
	}
	//turning the i from index to position
	return Position(i);
}

/*
desc: move method to proccess the message from the front end
input: string msg ("a2a4")
output: int the move code
*/
int Manager::movePieceStr(std::string msg)
{
	char let1 = msg[0];
	int num1 = msg[1] - '0';

	char let2 = msg[2];
	int num2 = msg[3] - '0';

	
	return this->movePiece(Position(let1, num1), Position(let2, num2));
}