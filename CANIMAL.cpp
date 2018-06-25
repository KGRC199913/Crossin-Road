#include "CANIMAL.h"

void CANIMAL::setCoord(int x, int y)
{
	_x = x;
	_y = y;
}

void CANIMAL::Move(int blockX, int blockY)
{
	_x += blockX;
	_y += blockY;
}
