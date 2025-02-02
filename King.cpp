#include "King.h"
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0
#define MOVE_MAKES_CHECK 4

King::King(char col, Position pos)
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = 'k';
}

/*
desc: function returns true or false if the move is an illegal move
input: 
	Position pos: the current position of the piece
	Position move: the position to move to
output: bool of if the move is valid or not
*/
bool validMove(Position pos, Position move)
{
	if (std::abs(pos.getNum() - move.getNum()) > 1)
	{
		return false;
	}
	if (std::abs(pos.getLet() - move.getLet()) > 1)
	{
		return false;
	}
	return true;
}

int King::checkMove(Position dst, const Manager& board) const
{
	if (!validMove(this->getPos(), dst))
	{
		return ILLEGAL_MOVE;
	}
	return VALID_MOVE;
}

int King::move(Position pos, Manager board)
{
	int moveCode = this->checkMove(pos, board);
	if (moveCode == VALID_MOVE)
	{
		this->setPos(pos.toString());
	}
	return moveCode;
}