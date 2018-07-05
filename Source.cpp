#include "Menu.h"
#include "CGAME.h"

int main() {
	CGAME* cg = CGAME::getInstance();
	GUI::initWindows();
	Menu::CreateLoopMenu();
	do {
		cg->startGame();
		GUI::clearConsoleScreen();
		if ((cg->isExit()) || (cg->won()))
			break;
	} while (Menu::AskPlayAgainMenu());
	delete cg;
	return 0;
}
