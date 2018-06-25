#include "CVEHICLE.h"

void CVEHICLE::setCoord(int x, int y)
{
	_x = x;
	_y = y;
}

void CVEHICLE::Move(int blockX, int blockY)
{
	_x += blockX;
	_y += blockY;
}
