#pragma once
#include "Position.h"
#include "Piece.h"

class Rook :public Piece
{
	int virtual move(Position dst, Manager board) override;
	bool checkPath(Position dst, const Manager board) const;
};