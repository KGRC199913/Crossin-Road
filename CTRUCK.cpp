#include "CTRUCK.h"

CTRUCK::CTRUCK()
{
	_type = 1;
	_x = _y = 0;
}

void CTRUCK::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
}

void CTRUCK::draw_self_bw()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
}

void CTRUCK::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
}
