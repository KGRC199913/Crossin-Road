#include "CBIRD.h"

void CBIRD::draw_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << (char)(223); 
	std::cout << (char)(223);
	std::cout << (char)(220);
	std::cout << (char)(223);
	std::cout << (char)(223);
}

void CBIRD::delete_self()
{
	GUI::gotoXY(_x, _y - 1);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
}
