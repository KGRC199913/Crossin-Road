#include "Menu.h"
#include "Function.h"
#include "GUI.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"

Menu::Menu()
{
	_pressKey = NULL;
	_pointer = 0;
}

Menu & Menu::PushBackBeginOptions() {
	std::vector<std::string> ops = { "NEW GAME", "LOAD GAME", "SETTINGS", "ABOUT US", "EXIT" };
	for (size_t i = 0; i < ops.size(); ++i)
		_options.push_back(ops[i]);

	return *this;
}

void Menu::PrintMenuOptions() {
	GUI::clearConsoleScreen();
	DrawGameName();
	DrawTree();
	DrawBox();
	DrawMan();
	DrawDinos();
	DrawBirds();
	DrawCloud();
	DrawCars();
	DrawTrucks();
	GUI::gotoXY(45, 30); std::cout << "BE SAFE PASSER!!!!";
	
	int coordY = 21;
	for (size_t i = 0; i < _options.size(); ++i) {
		if (_pointer == i) {
			GUI::gotoXY(46, coordY);  std::cout << ">> " << _options[i] << " <<";
			coordY += 1;
		}
		else {
			GUI::gotoXY(46, coordY); std::cout <<"   "<< _options[i];
			coordY += 1;
		}
	}
}

void Menu::CreateLoopMenu() {
	START: while (true) {
		this->PrintMenuOptions();
		while (true) {
			_pressKey = _getch();
			if (_pressKey == 72) {
				if (_pointer > 0)
					--_pointer;
				else
					_pointer = _options.size() - 1;
				break;
			}
			if (_pressKey == 80) {
				if (_pointer < _options.size() - 1)
					++_pointer;
				else
					_pointer = 0;
				break;
			}
			if (_pressKey == 13) {
				switch (_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					//std::cout << "Game Start!!" << std::endl;
					GUI::drawPlayArea();
					system("pause > nul");
					goto START;
					break;
				}

				case 2: {
					GUI::clearConsoleScreen();
					std::cout << "Choose Options!!" << std::endl;
					system("pause");
					goto START;
					break;
				}

				case 3: {
					GUI::clearConsoleScreen();
					std::cout << "Cat Rules The World!" << std::endl;
					system("pause");
					goto START;
					break;
				}

				case 4: {
					GUI::clearConsoleScreen();
					std::cout << "EXIT!" << std::endl;

					return;
				}
				}
			}
		}
	}
}

Menu::~Menu() {}


