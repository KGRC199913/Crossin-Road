#include "Menu.h"
#include "CGAME.h"
// Use to Debug only
// pseudo-main
int main() {
	CGAME cg;
	GUI::setWindowSize();
	GUI::fixConsoleWindows();
	Menu menu;
	menu.CreateLoopMenu();
	do {
		cg.startGame();
		cg.resetGame();
	} while (!cg.isExit());
	return 0;
}
//