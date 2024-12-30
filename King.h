#pragma once

#include "Piece.h"

class King : public Piece
{
private:
	bool isChecked;
public:
	King(char col, Position pos);
	int virtual checkMove(Position dst, const Manager& board) const override;
	int virtual move(Position pos, Manager board) override;
};