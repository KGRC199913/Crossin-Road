#include "Menu.h"
#include "CGAME.h"
// Use to Debug only
// pseudo-main
int main() {
	CGAME cg;
	GUI::initWindows();
	Menu::CreateLoopMenu();
	do {
		cg.startGame();
		cg.resetGame();
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	} while (!cg.isExit());
	return 0;
}
//