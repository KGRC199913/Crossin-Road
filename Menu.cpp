#include "Menu.h"



Menu::Menu()
{
	pressKey = NULL;
	pointer = 0;
}

Menu & Menu::PushBackBeginOptions()
{
	std::vector<std::string> ops = { "NEW GAME", "OPTIONS", "ABOUT US", "EXIT" };
	for (int i = 0; i < ops.size(); ++i)
		options.push_back(ops[i]);

	return *this;
}

void Menu::PrintMenuOptions()
{
	FixConsoleWindow();
	system("cls");
	DrawGameName();
	for (int i = 0; i < options.size(); ++i)
	{
		if (pointer == i)
			std::cout << "\n\t\t\t\t\t      " << ">> " << options[i] << " <<";
		else
			std::cout << "\n\t\t\t\t\t         " << options[i];
	}
}

void Menu::CreateLoopMenu()
{
	START: while (true)
	{
		this->PrintMenuOptions();
		while (true)
		{
				pressKey = _getch();
				if (pressKey == 72)
				{
					if (pointer > 0)
						--pointer;
					else
						pointer = options.size() - 1;
					break;
				}
				if (pressKey == 80)
				{
					if (pointer < options.size() - 1)
						++pointer;
					else
						pointer = 0;
					break;
				}
				if (pressKey == 13)
				{
					switch (pointer)
					{
					case 0:
					{
						system("cls");
						std::cout << "Game Start!!" << std::endl;
						system("pause");
						goto START;
						break;
					}

					case 1:
					{
						system("cls");
						std::cout << "Choose Options!!" << std::endl;
						system("pause");
						goto START;
						break;
					}

					case 2:
					{
						system("cls");
						std::cout << "Cat Rules The World!" << std::endl;
						system("pause");
						goto START;
						break;
					}

					case 3:
					{
						system("cls");
						std::cout << "EXIT!" << std::endl;
						
						return;
					}
					}
				}
		}
	}
}

Menu::~Menu()
{}

void DrawGameName()
{
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

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
