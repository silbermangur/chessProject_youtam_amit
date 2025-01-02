#pragma once
#include "Position.h"
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(char col, Position pos);
	int virtual move(Position dst, Manager board) override;
	int checkMove(Position dst, const Manager& board) const override;
};