#include "Piece.h"

/*
desc: throws an exception if the piece's color is not valid
input: char col: color to check for
output: none
*/
void checkColor(char col) 
{
	if (col != 'w' || col != 'b')
	{
		throw PieceColorException();
	}
}


/*
desc: constructor for the piece class 
input:
	Position pos: The position of the piece
	char color: the color of the piece ('b' or 'w')
	string type: the type of the piece
output:
*/
Piece::Piece(Position pos, char col, string type) : _pos(pos), _color(col), _type(type) // constructor of piece
{
	checkColor(col);	
}

/*
desc: sets the position of the piece with a string "LET,NUM"
input: string pos: the string to set the position with
output: None
*/
void Piece::setPos(string pos) // sets position of a piece with _pos setPos method
{
	_pos.setPos(pos);
}


/*
desc: gets the position of the piece as a string "LET,NUM"
input: None
output: String of the position
*/
string Piece::getPos() // gets the position as a string with _pos toString method
{
	return _pos.toString();
}
