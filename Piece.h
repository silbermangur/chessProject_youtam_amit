#pragma once

#include "Position.h"
#include "Manager.h"

class Manager;

class Piece
{
protected:
	Position _pos;
	char _color; // ONLY 'b' or 'w' other chars will result in an exception
	char _type;
public:
	Piece(Position pos, char col, char type);
	Piece();
	virtual ~Piece();
	
	char toChar();
	string getStringPos() const;
	Position getPos() const;
	char getColor() const;
	char getType() const;
	
	void setPos(string pos);
	int virtual checkMove(Position pos, const Manager& board) const= 0;
	int virtual move(Position pos, Manager board) = 0;
};

// exception class for if the pieces color is invalid
class PieceColorException : public exception
{
	const char* what() const noexcept override
	{
		return "invalid Color! only 'b' or 'w'";
	}
};