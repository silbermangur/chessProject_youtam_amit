#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"

#define PieceType 'q'

class Queen : public Rook , public Bishop
{
public:
	Queen(char col, Position pos) : Rook(col, pos, 'q'), Bishop(col, pos, 'q') {};
	int virtual move(Position dst, Manager board) override;
	int checkMove(Position dst, const Manager& board) const override;
};