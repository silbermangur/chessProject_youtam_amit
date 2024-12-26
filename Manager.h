#pragma once
#include "Piece.h"

class Manager
{
private:
	Piece* board[8][8];
public:
	Manager();
	string toString() const;
	bool addPiece(Piece& piece, Position position);
	void removePiece(Position position);
	char checkForPiece(Position position);
	int movePiece(Position src, Position dst);
};
