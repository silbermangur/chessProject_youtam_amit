#include "Rook.h"
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0

Rook::Rook(char col, Position pos) 
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = 'r';
}

Rook::Rook(char col, Position pos, char type)
{
	this->setPos(pos.toString());
	this->_color = col;
	this->_type = type;
}

/*
desc: checks if the path between the current position and the dst position is clear
intput: the dst position, the manager consisting of the board
output: true if clear, false if not
*/
bool Rook::checkPath(Position dst, const Manager board) const
{
	int i = 0;
	int start = 0;
	int end = 0;
	//checking if the letter is equal or the number is equal
	if (this->getPos().getLet() == dst.getLet())
	{
		start = this->getPos().getNum();
		end = dst.getNum();
		//if the start is bigger than the end, exchanging them 
		if (start > end)
		{
			i = start;
			start = end;
			end = i;
		}
		//also adjusting -1 as to not check the destiantion square
		end -= 1;
		for (i = start; i < end; i++)
		{
			if (board.board[i][dst.getLet() - 'a'])
			{
				return false;
			}
		}
	}
	else
	{
		//if the number is equal, checking where to start from and running a loop to check
		if (this->getPos().getLet() < dst.getLet())
		{
			//adjusting the +1 so i wont check the starting square
			start = this->getPos().turnToNum()+1;
			end = dst.turnToNum();
		}
		else
		{
			start = dst.turnToNum()+1;
			end = this->getPos().turnToNum();
		}
		for (i = start; i < end; i++)
		{
			//checking each square on the path, if theres a piece in one of them, returning false
			if (board.board[0][i])
			{
				return false;
			}
		}
	}
	//if the path is clear, returning true
	return true;
}

/*
desc: checks if the move is legal, and moves the piece if it is
input: the dst position, the manager 
output: the code (as in the slideshow)
*/
int Rook::checkMove(Position dst, const Manager& board) const
{
	//checking if the rook and the dst position dont have neither letter coord and num coord in common
	if (this->getPos().getLet() != dst.getLet() && this->getPos().getNum() != dst.getNum())
	{
		//returning code 6 in that case
		return ILLEGAL_MOVE;
	}
	//checking if the path to the dst is clear
	if (!this->checkPath(dst, board))
	{
		return ILLEGAL_MOVE;
	}
	return VALID_MOVE;
}
 /*
 desc: checks if move is valid then moves the rook if it is
 input: the position to move to, the manager
 output: the code(from the sideshow)
 */
int Rook::move(Position dst, Manager board)
{
	int moveCode = this->checkMove(dst, board);
	if (moveCode == VALID_MOVE)
	{
		this->setPos(dst.toString());
	}
	return moveCode;
}