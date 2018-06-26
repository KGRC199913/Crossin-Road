#include "Menu.h"
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
				if ((size_t)_pointer < _options.size() - 1)
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

//MENU's DECORATION FUNCTION
void DrawGameName() {
	std::cout << R"abcd(
			 ____                                                         
			/\  _`\                                __                     
			\ \ \/\_\  _ __   ___     ____    ____/\_\    ___      __     
			 \ \ \/_/_/\`'__\/ __`\  /',__\  /',__\/\ \ /' _ `\  /'_ `\   
			  \ \ \L\ \ \ \//\ \L\ \/\__, `\/\__, `\ \ \/\ \/\ \/\ \L\ \  
			   \ \____/\ \_\\ \____/\/\____/\/\____/\ \_\ \_\ \_\ \____ \ 
			    \/___/  \/_/ \/___/  \/___/  \/___/  \/_/\/_/\/_/\/___L\ \
			                                                       /\____/
			                                                       \_/__/ 
			            ____                         __                   
			           /\  _`\                      /\ \                  
			           \ \ \L\ \    ___      __     \_\ \                 
			            \ \ ,  /   / __`\  /'__`\   /'_` \                
			             \ \ \\ \ /\ \L\ \/\ \L\.\_/\ \L\ \               
			              \ \_\ \_\ \____/\ \__/.\_\ \___,_\              
			               \/_/\/ /\/___/  \/__/\/_/\/__,_ /      
)abcd";
	std::cout << std::endl;
}

void DrawBox() {


	for (int coordX = 44; coordX < 61; ++coordX) {
		GUI::gotoXY(coordX, 20); std::cout << BOX_HORIZONTAL_ASCII;
		GUI::gotoXY(coordX, 26); std::cout << BOX_HORIZONTAL_ASCII;;
	}

	for (int coordY = 21; coordY <= 25; ++coordY) {
		GUI::gotoXY(44, coordY); std::cout << BOX_VERTICAL_ASCII;
		GUI::gotoXY(61, coordY); std::cout << BOX_VERTICAL_ASCII;
	}

	GUI::gotoXY(61, 20); std::cout << BOX_TOP_RIGHT_CORNER_ASCII;
	GUI::gotoXY(61, 26); std::cout << BOX_BOTTOM_RIGHT_CORNER_ASCII;
	GUI::gotoXY(44, 20); std::cout << BOX_TOP_LEFT_CORNER_ASCII;
	GUI::gotoXY(44, 26); std::cout << BOX_BOTTOM_LEFT_CORNER_ASCII;

}

void DrawMan() {
	GUI::gotoXY(100, 23);
	std::cout << R"abcd(
                    ___   O
                  ____   /_\_
                 ___   __/ \
                     ___   /
          
)abcd";
}

void DrawDinos() {
	GUI::gotoXY(80, 25);
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
	std::cout << SPACE_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII << std::endl;
	GUI::gotoXY(81, 26);
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
}

void DrawBirds() {
	GUI::gotoXY(80, 20);
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII;
	std::cout << TOP_HALF_BLOCK_ASCII;
}

void DrawCars() {
	GUI::gotoXY(5, 25);
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
}

void DrawTrucks() {
	GUI::gotoXY(13, 25);
	std::cout << BLOCK_ASCII;
	std::cout << BLOCK_ASCII;
	std::cout << BOTTOM_HALF_BLOCK_ASCII;
	;
}

void DrawTree() {
	GUI::gotoXY(20, 19);
	std::cout << R"abcd(
                                                                                             @@@@
                                                                                            @@@@~@
                                                                                           @@@~@@@@@
                                                                                            @@@@~@@
                                                                                             @@_@
                                                                                              ||
                                                                                             _||_
)abcd";
}

void DrawCloud() {
	GUI::gotoXY(100, 18);
	std::cout << R"abcd(
   ____           ____
 _(    )        _(    ) 
(___(__)       (___(__)             
)abcd";
}

Menu::~Menu() {}


