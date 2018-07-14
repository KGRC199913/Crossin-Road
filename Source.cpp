#include "Menu.h"
#include "CGAME.h"

auto main(void) -> int {
	GUI::initWindows();

	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

	sf::Music music;
	if (music.openFromFile(BGM_PATH)) {
		music.play();
		music.setLoop(true);
	}
	else
		std::cerr << "Error loading bgm";

	bool isLoadSelected = false;

	int music_vol = 100, sfx_vol = 100;
	if (Menu::CreateLoopMenu(isLoadSelected, music_vol, sfx_vol)) {
		CGAME* cg = CGAME::getInstance();
		
		music.setVolume(music_vol);

		if (!isLoadSelected)
			cg->setDifficulties(Menu::DrawDifficultiesMenu());
		do {
			cg->startGame(isLoadSelected);
			GUI::clearConsoleScreen();
			if ((cg->isExit()) || (cg->won()))
				break;

			isLoadSelected = false;
		} while (Menu::DrawPlayAgainMenu());
		if (cg->wonPreviousLevel()) {
			std::cout << "u won" << std::endl; // TODO: make a winning scene
		}
		delete cg;
	}

	music.stop();

	return 0;
}

