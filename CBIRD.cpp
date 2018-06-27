#include "CBIRD.h"

void CBIRD::draw_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
}

void CBIRD::delete_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
}
