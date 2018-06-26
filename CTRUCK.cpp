#include "CTRUCK.h"

void CTRUCK::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
}

void CTRUCK::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
}
