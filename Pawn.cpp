#include "Pawn.h"
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0

Pawn::Pawn(char col, Position pos)
{
	this->firstMove = true;
	this->_color = col;
	this->_pos = pos;
	this->_type = 'p';
}

int Pawn::move(Position dst, Manager board)
{
	int moveCode = this->checkMove(dst, board);
	if (moveCode == VALID_MOVE)
	{
		this->setPos(dst.toString());
		//making sure to turn the firstMove to false after moving
		firstMove = false;
	}
	return moveCode;
}

int Pawn::checkMove(Position dst, const Manager& board) const
{
	//checking if its a normal move
	if (this->getPos().getLet() == dst.getLet() && board.board[0][dst.turnToNum()] == nullptr)
	{
		//for white
		if (this->getColor() == 'w' && dst.getNum() == this->getPos().getNum() + 1)
		{
			return VALID_MOVE;
		}
		//for black
		if (this->getColor() == 'b' && dst.getNum() == this->getPos().getNum() - 1)
		{
			return VALID_MOVE;
		}
		//checking if its a starting move
		if (this->firstMove && std::abs(dst.getNum() - this->getPos().getNum()) == 2)
		{
			//making sure there nothing blocking the path
			//for white
			if (this->_color == 'w' && board.board[-1][dst.turnToNum()] == nullptr)
			{
				return VALID_MOVE;
			}
			//for black
			if (this->_color == 'b' && board.board[1][dst.turnToNum()] == nullptr)
			{
				return VALID_MOVE;
			}
		}
	}
	//checking for a capture move
	if (board.board[0][dst.turnToNum()] != nullptr)
	{
		//checking if the dst is 1 collum to the side
		if (std::abs(dst.getLet() - this->getPos().getLet()) == 1)
		{
			//for white
			if (this->getColor() == 'w' && dst.getNum() == this->getPos().getNum() + 1)
			{
				return VALID_MOVE;
			}
			//for black
			if (this->getColor() == 'b' && dst.getNum() == this->getPos().getNum() - 1)
			{
				return VALID_MOVE;
			}
		}
	}
	//if after everything the move is still not valid, returning code 6
	return ILLEGAL_MOVE;
}