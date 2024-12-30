#include "King.h"
#define ILLEGAL_INDEX 5
#define ILLEGAL_MOVE 6
#define EQU_SRC_AND_DST 7
#define VALID_MOVE 0
#define MOVE_MAKES_CHECK 4

/*
desc: function returns true or false if the move is an illegal move
input: 
	Position pos: the current position of the piece
	Position move: the position to move to
output: bool of if the move is valid or not
*/
bool validMove(Position pos, Position move)
{
	if (std::abs(pos.getNum() - move.getNum() > 2))
	{
		return false;
	}
	if (std::abs(pos.getLet() - move.getLet() > 2))
	{
		return false;
	}
	return true;
}

int King::checkMove(Position move, Manager board)
{
	Position pos = this->getPos(); 
	if (pos == move)
	{
		return EQU_SRC_AND_DST;
	}
	if (!(move.checkBounds()))
	{
		return ILLEGAL_INDEX;
	}
	if (validMove(pos, move))
	{
		return VALID_MOVE;
	}
	if (board.isSquareSafe(move, this->getColor())) // function to check if the square if safe
	{
		return MOVE_MAKES_CHECK;
	}
	return ILLEGAL_MOVE;
}

int King::move(Position pos, Manager board)
{
	int moveCode = this->checkMove(pos, board);
	if (moveCode == 0)
	{
		this->setPos(pos.toString());
		return 0;
	}
	else
	{
		return moveCode;
	}
}