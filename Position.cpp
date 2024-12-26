#include "Position.h"

#define MAX_NUM 10
#define MIN_NUM 0

#define MAX_LET 'h'
#define MIN_LET 'a'

/*
desc: Constructor for the position class sets the fields 
input: 
	char let: the letter position to put into _let
	int num: the number position to put into _num 
output: None
*/
Position::Position(char let, int num)
{
	CheckBounds(let, num);

	_let = let;
	_num = num;
}

/*
desc: sets position for the Piece with a string "_let,_num"
input: string pos: the string to change the position with 
output: None
*/
void Position::setPos(string pos)
{
	int num = stoi(pos.substr(2)); // changes string to number and puts it in a variable
	char let = pos[0];
	CheckBounds(let, num); // check if position within bounds
	
	
	if (pos[1] != ',') // check for proper formating
	{
		throw PositionException();
	}
	

	_let = let; // changes _let field
	_num = num; // changes _num field

}

/*
desc: converts the position of the piece to a string
input: None
output: string of the position formatted like "LETTER,NUMBER", for example "c,4"
*/
string Position::toString()
{
	string st = "";
	st += _let;
	st += ",";
	st += std::to_string(_num);
	return st;
}

/*
desc: function to throw exception if position is not within bounds
input: 
	int num: pos on y
	char let: pos on x
output: None
*/
void CheckBounds(int let, char num)
{
	if (let < MIN_LET || let > MAX_LET) // check if position out of bounds
	{
		throw PositionException();
	}
	if (num < MIN_NUM || num > MAX_NUM) // check if position out of bounds
	{
		throw PositionException();
	}
}