#include "CDINOSAUR.h"

void CDINOSAUR::draw_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << (char)(223);
	std::cout << (char)(219);
	GUI::gotoXY(_x, _y);
	std::cout << (char)(32);
	std::cout << (char)(219);
	std::cout << (char)(219);
	std::cout << (char)(220);
}

void CDINOSAUR::delete_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << (char)(32);
	std::cout << (char)(32);
	GUI::gotoXY(_x, _y);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
}
