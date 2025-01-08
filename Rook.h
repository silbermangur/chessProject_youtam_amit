#pragma once
#include "Position.h"
#include "Piece.h"

class Rook :public virtual Piece
{
public:
	Rook(char col, Position pos);
	Rook(char col, Position pos, char type);

	int virtual move(Position dst, Manager board) override;
	bool checkPath(Position dst, const Manager board) const;
	int checkMove(Position dst, const Manager& board) const override;
};