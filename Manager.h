#pragma once
#include "Piece.h"

class Piece;

class Manager
{
private:
	//w = white turn, b = black turn
	char turn;
public:
	Piece* board[8][8];
	Manager();
	string toString() const;
	void addPiece(Piece& piece, Position position);
	void removePiece(Position position);
	char checkForPiece(Position position) const;
	int movePiece(Position src, Position dst);
	bool isSquareSafe(Position square, char col);
	void changeTurn();
	Position findOppKing() const;
};
