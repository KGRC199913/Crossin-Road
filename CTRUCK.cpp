#include "CTRUCK.h"

void CTRUCK::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << (char)(219);
	std::cout << (char)(219);
	std::cout << (char)(220);
}

void CTRUCK::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
}
