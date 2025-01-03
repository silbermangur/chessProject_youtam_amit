#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"

#define PieceType 'q'

class Queen : public Piece , private Rook , private Bishop
{
	Queen(char col, Position pos) : Piece(pos, col, PieceType), Rook(col, pos), Bishop(col, pos) {};
	int virtual move(Position dst, Manager board) override;
	int checkMove(Position dst, const Manager& board) const override;
};