#include "Position.h"

#define MAX_NUM 8
#define MIN_NUM 0

#define MAX_LET 'h'
#define MIN_LET 'a'

/*
desc: function to check if position is not within bounds
input: none
output: true if withing bounds, false if not
*/
bool Position::checkBounds() const
{
	if (_let < MIN_LET || _let > MAX_LET) // check if position out of bounds
	{
		return false;
	}
	if (_num < MIN_NUM || _num > MAX_NUM) // check if position out of bounds
	{
		return false;
	}
	return true;
}

/*
desc: Constructor for the position class sets the fields 
input: 
	char let: the letter position to put into _let
	int num: the number position to put into _num 
output: None
*/
Position::Position(char let, int num)
{
	_let = let;
	_num = num;
}

/*
desc: copy constructor for the position class copys the fields from pos to this
input: Position& pos: position to copy from
output: none
*/
Position::Position(const Position& pos)
{
	_let = pos._let;
	_num = pos._num;
}

/*
desc: ctor that creates a position out of an index in the array
input: the index
output: none
*/
Position::Position(int index)
{
	this->_let = index % MAX_NUM + 'a';
	this->_num = index / MAX_NUM + 1;
}

Position::Position()
{
	this->_let = 'a';
	this->_num = '1';
}

/*
desc: = operator for the Position class copys from one side to another
input: Position& other: Position to copy from
output: returns this into this 
*/
Position& Position::operator=(const Position& other)
{
	this->_let = other._let;
	this->_num = other._num;
	return *this;
}

/*
desc: operator == of the Position class that compares two Positions  
input: Position& other: the point to compare
output: 
*/
bool Position::operator==(const Position& other) const
{
	if (_let == other._let && _num == other._num)
	{
		return true;
	}
	return false;
}

/*
desc: sets position for the Piece with a string "_let,_num"
input: string pos: the string to change the position with 
output: None
*/
void Position::setPos(string pos)
{
	int num = stoi(pos.substr(2)); // changes string to number and puts it in a variable
	char let = pos[0];; 
	
	
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
string Position::toString() const
{
	string st = "";
	st += _let;
	st += ",";
	st += std::to_string(_num);
	return st;
}

/*
desc: converts the position of the piece to number representing it in an array
input: None
output: the number that will access the position in an 8 by 8 array
*/
int Position::turnToNum() const
{
	int number = 0;
	number = (this->_num-1) * MAX_NUM;
	number += this->_let - 'a';
	return number;
}

/*
desc: return the letter coord of the position
input: None
output: the letter
*/
char Position::getLet() const
{
	return this->_let;
}

/*
desc: return the number coord of the position
input: None
output: the number
*/

int Position::getNum() const
{
	return this->_num;
}

Position& Position::operator+=(const int* other)
{
	this->_let += other[0];
	this->_num += other[1];
	return *this;
}