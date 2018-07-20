#include "Menu.h"
#include "CGAME.h"

auto main(void) -> int {

	// lock the size, change the console size to WIDTH x HEIGHT
	GUI::initWindows();
	
	// set the priority of this thread to highest to minimize the latency
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

	// music
	sf::Music music;
	if (music.openFromFile(BGM_PATH)) {
		music.play();
		music.setLoop(true);
	}
	else
		std::cerr << "Error loading bgm";
	//

	bool isLoadSelected = false;

	int music_vol = 100, sfx_vol = 100;
	// main game loop
	if (Menu::CreateLoopMenu(isLoadSelected, music_vol, sfx_vol)) {
		CGAME* cg = CGAME::getInstance();
		
		music.setVolume(music_vol);

		// choose difficulty only if start new game
		if (!isLoadSelected)
			cg->setDifficulties(Menu::DrawDifficultiesMenu());
		do {
			cg->startGame(isLoadSelected);
			// reset after each round
			GUI::clearConsoleScreen();
			if ((cg->isExit()) || (cg->won()))
				break;

			isLoadSelected = false;
		} while (Menu::DrawPlayAgainMenu());
		// wining effect here
		if (cg->wonPreviousLevel()) {
			std::cout << "u won" << std::endl; // TODO: make a winning scene
		}

		// delete the cg to avoid huge memory leak
		delete cg;
	}
	//
	music.stop();

	return 0;
}

