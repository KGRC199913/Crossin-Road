#include "CDINOSAUR.h"

void CDINOSAUR::draw_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	GUI::gotoXY(_x, _y);
	std::cout << UNDERSCORE_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
}

void CDINOSAUR::delete_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
	GUI::gotoXY(_x, _y);
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
	std::cout << UNDERSCORE_ASCII;
}
