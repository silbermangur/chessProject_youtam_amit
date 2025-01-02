#include "Knight.h"
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0

Knight::Knight(char col, Position pos)
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = 'n';
}

int Knight::checkMove(Position dst, const Manager& board) const
{
	//these are the 2 cases in which the knight's move is legal
	if (std::abs(dst.getLet() - this->getPos().getLet()) == 1 && std::abs(dst.getNum() - this->getPos().getNum()) == 2)
	{
		return VALID_MOVE;
	}
	if (std::abs(dst.getLet() - this->getPos().getLet()) == 2 && std::abs(dst.getNum() - this->getPos().getNum()) == 1)
	{
		return VALID_MOVE;
	}
	return ILLEGAL_MOVE;
}

int Knight::move(Position dst, Manager board)
{
	int moveCode = this->checkMove(dst, board);
	if (moveCode == VALID_MOVE)
	{
		this->setPos(dst.toString());
	}
	return moveCode;
}