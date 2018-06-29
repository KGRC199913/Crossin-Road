#include "Menu.h"
#include "CGAME.h"

int main()
{
	Menu test;
	test.CreateLoopMenu();
	CGAME cg;
	cg.startGame();
	return EXIT_SUCCESS;
}