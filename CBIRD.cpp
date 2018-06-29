#include "CBIRD.h"

CBIRD::CBIRD()
{
	_type = 0;
	_x = _y = 0;
}

void CBIRD::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
}

void CBIRD::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
}

void CBIRD::draw_self_bw()
{

	draw_self();
}

void CBIRD::delete_self_bw()
{
	delete_self();
}