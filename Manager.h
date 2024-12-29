#pragma once
#include "Piece.h"

class Piece;

class Manager
{
public:
	Piece* board[8][8];
	Manager();
	string toString() const;
	bool addPiece(Piece& piece, Position position);
	void removePiece(Position position);
	char checkForPiece(Position position);
	int movePiece(Position src, Position dst);
};
