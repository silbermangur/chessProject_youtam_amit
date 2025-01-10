#include "Bishop.h"
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0

Bishop::Bishop(char col, Position pos)
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = 'b';
}

Bishop::Bishop(char col, Position pos, char type)
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = type;
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
	int moves[][2] = { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} }; // moves of the bishop
	Position localPos = _pos;
	int index = 0;

	if (dst.getLet() - localPos.getLet() > 0) // checking what direction to the dst is and choosing the move accordingly
	{
		if (dst.getNum() - localPos.getNum() > 0) // up right
		{
			index = 2;
		}
		else // down right
		{
			index = 3;
		}
	}
	else
	{
		if (dst.getNum() - localPos.getNum() > 0) // up left
		{
			index = 1;
		}
		else // down left
		{
			index = 0;
		}
	}

	localPos += moves[index];
	while ((localPos == dst) == false)
	{
		if (board.board[0][localPos.turnToNum()] != nullptr)
		{
			return false;
		}
		localPos += moves[index];
	}
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