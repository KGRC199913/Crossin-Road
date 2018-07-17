#include "CCAR.h"

CCAR::CCAR()
{
	_type = 0;
	_x = _y = 0;
}

void CCAR::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
}

void CCAR::draw_self_bw()
{
	draw_self();
}
