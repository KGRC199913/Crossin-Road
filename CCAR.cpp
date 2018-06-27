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

void CCAR::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
}

void CCAR::draw_self_bw()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
}

void CCAR::delete_self_bw()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
}
