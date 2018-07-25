#include "CVEHICLE.h"

int CVEHICLE::getType() const
{
	return _type;
}

void CVEHICLE::setCoord(int x, int y)
{
	_x = x;
	_y = y;
}

void CVEHICLE::Move(int blockX)
{
	if (_x + blockX < LEFT_EDGE) {
		_x = RIGHT_EDGE;
	}
	else if (_x + blockX > RIGHT_EDGE) {
		_x = LEFT_EDGE;
	}
	else
		_x += blockX;	
}

COORD CVEHICLE::getCoord() const
{
	COORD coord;
	coord.X = _x;
	coord.Y = _y;
	return coord;
}
