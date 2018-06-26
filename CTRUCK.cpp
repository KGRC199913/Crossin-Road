#include "CTRUCK.h"

void CTRUCK::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
}

void CTRUCK::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
}
