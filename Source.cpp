#include "Menu.h"
#include "CGAME.h"


int main() {
	GUI::initWindows();
	if (Menu::CreateLoopMenu()) {
		CGAME* cg = CGAME::getInstance();
		do {
			cg->startGame();
			GUI::clearConsoleScreen();
			if ((cg->isExit()) || (cg->won()))
				break;
		} while (Menu::AskPlayAgainMenu());

		delete cg;
	}

	return 0;
}
