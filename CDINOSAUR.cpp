#include "CDINOSAUR.h"

CDINOSAUR::CDINOSAUR()
{
	_type = 1;
	_x = _y = 0;
}

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

void CDINOSAUR::draw_self_bw()
{
}

void CDINOSAUR::delete_self_bw()
{
}
