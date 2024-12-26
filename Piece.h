#pragma once

#include "Position.h"


class Piece
{
private:
	Position _pos;
	char _color; // ONLY 'b' or 'w' other chars will result in an exception
	string _type;
public:

	Piece(Position pos, char col, string type);
	Piece(Piece&);
	
	string getPos();
	char getColor();
	
	void setPos(string pos);
	int virtual move(Position pos) = 0;
};

// exception class for if the pieces color is invalid
class PieceColorException : public exception
{
	const char* what() const noexcept override
	{
		return "invalid Color! only 'b' or 'w'";
	}
};