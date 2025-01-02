#include "Bishop.h"
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0

Bishop::Bishop(char col, Position pos)
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = 'b';
}

int Bishop::checkMove(Position dst, const Manager& board) const
{
	//this ifs contains a check if the move's src and dst positions are legal for a bishop then checks if the path is clear
	if (std::abs(dst.getLet() - this->getPos().getLet()) ==  std::abs(dst.getNum() - this->getPos().getNum()))
	{
		if (checkPath(dst, board))
		{
			return VALID_MOVE;
		}
	}
	return ILLEGAL_MOVE;
	
}

bool Bishop::checkPath(Position dst, const Manager board) const
{
	return true;
}

int Bishop::move(Position dst, Manager board)
{
	int moveCode = this->checkMove(dst, board);
	if (moveCode == VALID_MOVE)
	{
		this->setPos(dst.toString());
	}
	return moveCode;
}