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
public:
	Position(char let, int num);
	Position(const Position& pos);
	Position& operator=(const Position& other);
	bool operator==(const Position& other) const;
	int turnToNum() const;
	void setPos(string pos);
	string toString() const;
	bool checkBounds() const;
	char getLet() const;
	int getNum() const;
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