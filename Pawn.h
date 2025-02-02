#pragma once
#include "Position.h"
#include "Piece.h"


class Pawn :public Piece
{
private:
	bool firstMove;
public:
	Pawn(char col, Position pos);
	int virtual move(Position dst, Manager board) override;
	int checkMove(Position dst, const Manager& board) const override;
};