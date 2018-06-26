#include "CDINOSAUR.h"

void CDINOSAUR::draw_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	GUI::gotoXY(_x, _y);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
}

void CDINOSAUR::delete_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
	GUI::gotoXY(_x, _y);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
	std::cout << char(UNDERSCORE_ASCII);
}
