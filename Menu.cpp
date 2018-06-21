#include "Menu.h"
#include "Function.h"
#include "GUI.h"

Menu::Menu()
{
	_pressKey = NULL;
	_pointer = 0;
}

Menu & Menu::PushBackBeginOptions() {
	std::vector<std::string> ops = { "NEW GAME", "LOAD GAME", "SETTINGS", "ABOUT US", "EXIT" };
	for (int i = 0; i < ops.size(); ++i)
		_options.push_back(ops[i]);

	return *this;
}

void Menu::PrintMenuOptions() {
	GUI gui;
	gui.SetWindowSize();
	system("cls");
	DrawGameName();
	DrawTree();
	DrawBox();
	DrawMan();
	DrawDinos();
	DrawBirds();
	DrawCloud();
	DrawCars();
	DrawTrucks();
	GotoXY(45, 30); std::cout << "BE SAFE PASSER!!!!";
	
	int coordY = 21;
	for (int i = 0; i < _options.size(); ++i) {
		if (_pointer == i) {
			GotoXY(46, coordY);  std::cout << ">> " << _options[i] << " <<";
			coordY += 1;
		}
		else {
			GotoXY(46, coordY); std::cout <<"   "<< _options[i];
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
					system("cls");
					//std::cout << "Game Start!!" << std::endl;
					GUI test;
					test.drawPlayArea();
					system("pause");
					goto START;
					break;
				}

				case 1: {
					system("cls");
					std::cout << "Choose Options!!" << std::endl;
					system("pause");
					goto START;
					break;
				}

				case 2: {
					system("cls");
					std::cout << "Cat Rules The World!" << std::endl;
					system("pause");
					goto START;
					break;
				}

				case 3: {
					system("cls");
					std::cout << "EXIT!" << std::endl;

					return;
				}
				}
			}
		}
	}
}

Menu::~Menu() {}


