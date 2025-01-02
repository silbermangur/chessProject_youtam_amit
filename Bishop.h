#pragma once
#include "Position.h"
#include "Piece.h"

class Bishop :public Piece
{
public:
	Bishop(char col, Position pos);
	int virtual move(Position dst, Manager board) override;
	bool checkPath(Position dst, const Manager board) const;
	int checkMove(Position dst, const Manager& board) const override;
};