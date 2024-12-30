#pragma once

#include "Piece.h"

class King : public Piece
{
private:
	bool isChecked;
public:
	int virtual checkMove(Position pos, Manager board) const override;
	int virtual move(Position pos, Manager board) override;
};