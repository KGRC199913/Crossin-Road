#include "Menu.h"
#include "GUI.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"
#include "CGAME.h"

std::vector<std::string> Menu::_options;
char Menu::_pressKey = ' ';
int Menu::_pointer = 0;

Menu::Menu()
{
	Menu::_pressKey = NULL;
	Menu::_pointer = 0;
}

void Menu::PushBackBeginOptions() {
	std::vector<std::string> ops = { "NEW GAME", "LOAD GAME", "SETTINGS", "ABOUT US", "EXIT" };
	Menu::_options.clear();
	Menu::_options.insert(Menu::_options.end(), ops.begin(), ops.end());
}

void Menu::PrintMenuOptions() {
	GUI::clearConsoleScreen();
	DrawGameName();
	DrawTree();
	DrawMenuBox();
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
			GUI::gotoXY(46, coordY);  
			std::cout << ">> " << _options[i] << " <<";
			coordY += 1;
		}
		else {
			GUI::gotoXY(46, coordY); 
			std::cout <<"   "<< _options[i];
			coordY += 1;
		}
	}
}

bool Menu::CreateLoopMenu() {
	PushBackBeginOptions();
	while (true) {
		Menu::PrintMenuOptions();
		while (true) {
			_pressKey = _getch();
			if (_pressKey == KEY_UP) {
				if (_pointer > 0)
					--_pointer;
				else
					_pointer = _options.size() - 1;
				break;
			}
			if (_pressKey == KEY_DOWN) {
				if ((size_t)_pointer < _options.size() - 1)
					++_pointer;
				else
					_pointer = 0;
				break;
			}
			if (_pressKey == ENTER) {
				switch (_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					return true;
					//std::cout << "Game Start!!" << std::endl;
					//GUI::drawPlayArea();
					system("pause > nul");
					break;
				}

				case 2: {
					GUI::clearConsoleScreen();
					std::cout << "Choose Options!!" << std::endl;
					system("pause");
					break;
				}

				case 3: {
					GUI::clearConsoleScreen();
					std::cout << "Cat Rules The World!" << std::endl;
					system("pause");
					break;
				}

				case 4: {
					GUI::clearConsoleScreen();
					return false;
				}
				}
			}
		}
	}
}


void Menu::DrawGameName() {
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

void Menu::DrawMenuBox() {


	for (int coordX = 44; coordX < 61; ++coordX) {
		GUI::gotoXY(coordX, 20); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 26); std::cout << char(BOX_HORIZONTAL_ASCII);
	}

	for (int coordY = 21; coordY <= 25; ++coordY) {
		GUI::gotoXY(44, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(61, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}

	GUI::gotoXY(61, 20); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(61, 26); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(44, 20); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(44, 26); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);

}

void Menu::DrawMan() {
	GUI::gotoXY(100, 23);
	std::cout << R"abcd(
                    ___   O
                  ____   /_\_
                 ___   __/ \
                     ___   /
          
)abcd";
}

void Menu::DrawDinos() {
	GUI::gotoXY(80, 25);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
	std::cout << char(SPACE_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(TOP_HALF_BLOCK_ASCII) << std::endl;
	GUI::gotoXY(81, 26);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
}

void Menu::DrawBirds() {
	GUI::gotoXY(80, 20);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
	std::cout << char(TOP_HALF_BLOCK_ASCII);
}

void Menu::DrawCars() {
	GUI::gotoXY(5, 25);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
}

void Menu::DrawTrucks() {
	GUI::gotoXY(13, 25);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BLOCK_ASCII);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	;
}

void Menu::DrawTree() {
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

void Menu::DrawCloud() {
	GUI::gotoXY(100, 18);
	std::cout << R"abcd(
   ____           ____
 _(    )        _(    ) 
(___(__)       (___(__)             
)abcd";
}

void Menu::PrintSubMenuOptions()
{
	int coordY = 14;
	for (size_t i = 0; i < _options.size(); ++i) {
		if (_pointer == i) {
			GUI::gotoXY(43, coordY); 
			std::cout << ">> " << _options[i]<< " <<" ;
			coordY += 1;
		}
		else {
			GUI::gotoXY(43, coordY); 
			std::cout << "   " << _options[i] << "   ";
			coordY += 1;
		}
	}
}

void Menu::PushBackLevelMenu()
{
	std::vector<std::string> ops = { "LEVEL 1", "LEVEL 2", "LEVEL 3", "LEVEL 4", "LEVEL 5" , "EXIT" };
	Menu::_options.clear();
	Menu::_options.insert(Menu::_options.end(), ops.begin(), ops.end());
}

void Menu::ChooseLevelBox()
{
	for (int coordX = 42; coordX < 58; coordX++)
	{
		GUI::gotoXY(coordX, 13); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 20); std::cout << char(BOX_HORIZONTAL_ASCII);
	}
	for (int coordY = 14; coordY <= 19; coordY++)
	{
		GUI::gotoXY(41, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(58, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(58, 13); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(58, 20); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(41, 13); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(41, 20); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);
}

void Menu::DrawChooseLevelMenu() {
	PushBackLevelMenu();
	while (true) {
		ChooseLevelBox();
		PrintSubMenuOptions();
		while (true) {
			_pressKey = _getch();
			if (_pressKey == KEY_UP) {
				if (_pointer > 0)
					--_pointer;
				else
					_pointer = _options.size() - 1;
				break;
			}
			if (_pressKey == KEY_DOWN) {
				if ((size_t)_pointer < _options.size() - 1)
					++_pointer;
				else
					_pointer = 0;
				break;
			}
			if (_pressKey == ENTER) {
				switch (_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					std::cout << "Level 1" << std::endl;
					break;
				}

				case 1: {
					GUI::clearConsoleScreen();
					std::cout << "Level 2" << std::endl;
					break;
				}

				case 2: {
					GUI::clearConsoleScreen();
					std::cout << "Level 3" << std::endl;
					break;
				}

				case 3: {
					GUI::clearConsoleScreen();
					std::cout << "Level 4" << std::endl;
					break;
				}

				case 4: {
					GUI::clearConsoleScreen();
					std::cout << "Level 5" << std::endl;
					break;
				}

				case 5: {
					GUI::clearConsoleScreen();
					exit(EXIT_SUCCESS);
					return;
				}
				}
			}
		}
	}
}

void Menu::PushBackDifficultiesMenu()
{
	std::vector<std::string> ops = { "NORMAL", "HARDCORE", "LUNATIC", "EXIT" };
	Menu::_options.clear();
	Menu::_options.insert(Menu::_options.end(), ops.begin(), ops.end());
}

void Menu::DifficultiesBox()
{
	for (int coordX = 42; coordX < 57; coordX++)
	{
		GUI::gotoXY(coordX, 13); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 18); std::cout << char(BOX_HORIZONTAL_ASCII);
	}
	for (int coordY = 14; coordY <= 17; coordY++)
	{
		GUI::gotoXY(41, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(57, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(57, 13); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(57, 18); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(41, 13); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(41, 18); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);
}

void Menu::DrawDifficultiesMenu() {
	PushBackDifficultiesMenu();
	while (true) {
		DifficultiesBox();
		PrintSubMenuOptions();
		while (true) {
			_pressKey = _getch();
			if (_pressKey == KEY_UP) {
				if (_pointer > 0)
					--_pointer;
				else
					_pointer = _options.size() - 1;
				break;
			}
			if (_pressKey == KEY_DOWN) {
				if ((size_t)_pointer < _options.size() - 1)
					++_pointer;
				else
					_pointer = 0;
				break;
			}
			if (_pressKey == ENTER) {
				switch (_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					std::cout << "Normal" << std::endl;
					break;
				}

				case 1: {
					GUI::clearConsoleScreen();
					std::cout << "Hardcore" << std::endl;
					break;
				}

				case 2: {
					GUI::clearConsoleScreen();
					std::cout << "Lunatic" << std::endl;
					break;
				}

				case 3: {
					GUI::clearConsoleScreen();
					exit(EXIT_SUCCESS);
					return;
				}
				}
			}
		}
	}
}

void Menu::PushBackPlayAgainMenu()
{
	CGAME* cg = CGAME::getInstance();
	std::string option1String = cg->wonPreviousLevel() ? "NEXT LEVEL" : "PLAY AGAIN";
	std::vector<std::string> ops = { option1String, "EXIT" };
	Menu::_options.clear();
	Menu::_options.insert(Menu::_options.end(), ops.begin(), ops.end());
}

void Menu::PlayAgainBox()
{
	for (int coordX = 42; coordX < 61; coordX++)
	{
		GUI::gotoXY(coordX, 13); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 16); std::cout << char(BOX_HORIZONTAL_ASCII);
	}
	for (int coordY = 14; coordY <= 15; coordY++)
	{
		GUI::gotoXY(42, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(61, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(61, 13); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(61, 16); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(42, 13); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(42, 16); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);
}

bool Menu::DrawPlayAgainMenu()
{
	PushBackPlayAgainMenu();
	while (true) {
		PlayAgainBox();
		PrintSubMenuOptions();
		while (true) {
			_pressKey = _getch();
			if (_pressKey == KEY_UP) {
				if (_pointer > 0)
					--_pointer;
				else
					_pointer = _options.size() - 1;
				break;
			}
			if (_pressKey == KEY_DOWN) {
				if ((size_t)_pointer < _options.size() - 1)
					++_pointer;
				else
					_pointer = 0;
				break;
			}
			if (_pressKey == ENTER) {
				switch (_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					return true;
				}

				case 1: {
					GUI::clearConsoleScreen();
					return false;
				}
				}
			}
		}
	}
}

Menu::~Menu() {}


