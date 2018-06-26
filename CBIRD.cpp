#include "CBIRD.h"

void CBIRD::draw_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII;
}

void CBIRD::delete_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
}
