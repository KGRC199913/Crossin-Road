#include "CANIMAL.h"

int CANIMAL::getType() const
{
	return _type;
}

void CANIMAL::setCoord(int x, int y)
{
	_x = x;
	_y = y;
}

void CANIMAL::Move(int blockX)
{
	if (true) {
		_x += blockX;
		
	}
	
}

COORD CANIMAL::getCoord() const
{
	COORD coord;
	coord.X = _x;
	coord.Y = _y;
	return coord;
}
