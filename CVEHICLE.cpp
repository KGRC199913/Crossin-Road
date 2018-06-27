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
	if (true) {
		_x += blockX;
		
	}
	
}

COORD CVEHICLE::getCoord() const
{
	COORD coord;
	coord.X = _x;
	coord.Y = _y;
	return coord;
}
