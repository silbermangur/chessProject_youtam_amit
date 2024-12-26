#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <sstream> // to convert numbers to strings
using namespace std;


class Position
{
private:
	int _num; // number that represent the y position
	char _let; // letter that represents the x 
protected:
	void setPos(string pos);
public:
	Position(char let, int num);
	Position(Position& pos);
	Position& operator=(const Position& other);
	bool operator==(const Position& other);

	string toString();
};


// exception class for invalid positions
class PositionException : public exception
{
	const char* what() const noexcept override
	{
		return "invalid Position!";
	}
};

#endif // POSITION_H