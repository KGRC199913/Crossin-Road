#include "Menu.h"
#include "CGAME.h"

int main() {
	CGAME* cg = CGAME::getInstance();
	GUI::initWindows();
	Menu::CreateLoopMenu();
	do {
		cg->startGame();
		GUI::clearConsoleScreen();
		if (!cg->won()) {
			if (!Menu::AskPlayAgainMenu()) {
				break;
			}
		}	
	} while (!cg->isExit());
	delete cg;
	return 0;
}
