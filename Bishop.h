#pragma once
#include "Position.h"
#include "Piece.h"

class Bishop :public virtual Piece
{
public:
	Bishop(char col, Position pos);
	Bishop(char col, Position pos, char type);

	int virtual move(Position dst, Manager board) override;
	bool checkPath(Position dst, const Manager board) const;
	int checkMove(Position dst, const Manager& board) const override;
};