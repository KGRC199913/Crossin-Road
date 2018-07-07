#include "Menu.h"
#include "CGAME.h"

auto main(void) -> int {
	GUI::initWindows();

	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	sf::Music music;
	if (music.openFromFile(BGM_PATH)) {
		music.play();
		music.setLoop(true);
		music.setVolume(20);
	}
	else
		std::cerr << "Error loading bgm";

	if (Menu::CreateLoopMenu()) {
		CGAME* cg = CGAME::getInstance();
		cg->setDifficulties(Menu::DrawDifficultiesMenu());
		do {
			cg->startGame();
			GUI::clearConsoleScreen();
			if ((cg->isExit()) || (cg->won()))
				break;
		} while (Menu::DrawPlayAgainMenu());

		delete cg;
	}

	music.stop();

	return 0;
}

