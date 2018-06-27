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
	if ((_x + blockX >= LEFT_EDGE) && (_x + blockX <= RIGHT_EDGE)) {
		_x += blockX;		
	}
	else {
		_x = 20;
	}
}

COORD CANIMAL::getCoord() const
{
	COORD coord;
	coord.X = _x;
	coord.Y = _y;
	return coord;
}
