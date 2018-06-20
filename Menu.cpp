#include "Menu.h"
#include "Function.h"

Menu::Menu()
{
	pressKey = NULL;
	pointer = 0;
}

Menu & Menu::PushBackBeginOptions() {
	std::vector<std::string> ops = { "NEW GAME", "OPTIONS", "ABOUT US", "EXIT" };
	for (int i = 0; i < ops.size(); ++i)
		options.push_back(ops[i]);

	return *this;
}

void Menu::PrintMenuOptions() {
	FixConsoleWindow();
	system("cls");
	DrawGameName();
	DrawBox();
	int t = 21;
	for (int i = 0; i < options.size(); ++i) {
		if (pointer == i) {
			GotoXY(46, t);  std::cout << ">> " << options[i] << " <<";
			t += 1;
		}
		else {
			GotoXY(46, t); std::cout <<"   "<< options[i];
			t += 1;
		}
	}
}

void Menu::CreateLoopMenu() {
	START: while (true) {
		this->PrintMenuOptions();
		while (true) {
			pressKey = _getch();
			if (pressKey == 72) {
				if (pointer > 0)
					--pointer;
				else
					pointer = options.size() - 1;
				break;
			}
			if (pressKey == 80) {
				if (pointer < options.size() - 1)
					++pointer;
				else
					pointer = 0;
				break;
			}
			if (pressKey == 13) {
				switch (pointer) {
				case 0: {
					system("cls");
					std::cout << "Game Start!!" << std::endl;
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


