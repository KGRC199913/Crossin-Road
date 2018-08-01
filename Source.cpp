//

#include "Menu.h"
#include "CGAME.h"



auto main(void) -> int {
	// lock the size, change the console size to WIDTH x HEIGHT
	GUI::initWindows();
	std::ios_base::sync_with_stdio(false);
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
	bool contiPlayFlag = false;
	// main game loop
	
	try {
		while (true) {
			if (Menu::CreateLoopMenu(isLoadSelected, music, sfx_vol)) {
				GUI::drawLoadingBar();
				GUI::clearConsoleScreen();
				CGAME* cg = CGAME::getInstance();
				cg->setSoundVol(sfx_vol);

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
					contiPlayFlag = Menu::DrawPlayAgainMenu();
				} while (contiPlayFlag);
				// wining effect here
				if (cg->wonPreviousLevel()) {
					//std::cout << "u won" << std::endl; // TODO: make a winning scene
					GUI::drawWinningScene();
				}

				if (cg->isExit() || !contiPlayFlag) {
					delete cg;
					break;
				}

				// delete the cg to avoid huge memory leak
				delete cg;
			}
			else
				break;
		}

	}
	catch (std::exception& e) {
		LogHere(Log::LOG_WRITE_MODE::FILE, Log::LOG_TAGS::FATAL, e.what());
	}
	catch (...) {
		LogHere(Log::LOG_WRITE_MODE::FILE, Log::LOG_TAGS::FATAL, "UNKNOW");
	}
	//
	music.stop();
	return 0;


	return 0;
}

