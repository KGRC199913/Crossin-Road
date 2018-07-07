#include "Menu.h"
#include "CGAME.h"
#include <SFML\Audio.hpp>

auto main(void) -> int {
	GUI::initWindows();

	sf::Music music;
	if (music.openFromFile(BGM_PATH)) {
		music.play();
		music.setLoop(true);
		music.setVolume(50);
	}
	else
		std::cerr << "Error loading bgm";


	if (Menu::CreateLoopMenu()) {
		CGAME* cg = CGAME::getInstance();
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
