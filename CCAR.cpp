#include "CCAR.h"

void CCAR::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
}

void CCAR::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
}
