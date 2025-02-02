#pragma once
#include "Piece.h"

class Piece;

class Manager
{
private:
	//w = white turn, b = black turn
	char turn;
public:
	int totalMoves;
	Piece* board[8][8];
	Manager();
	string toString() const;
	void addPiece(Piece& piece, Position position);
	char checkForPiece(Position position) const;
	int movePiece(Position src, Position dst);
	int movePieceStr(std::string  msg);
	bool isSquareSafe(Position square, char col) const;
	void changeTurn();
	char oppColor() const;
	Position findOppKing() const;
};
