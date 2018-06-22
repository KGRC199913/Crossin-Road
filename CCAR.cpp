#include "CCAR.h"

void CCAR::draw_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << (char)(220);
	std::cout << (char)(219);
	std::cout << (char)(220);
}

void CCAR::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
}
