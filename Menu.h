#ifndef MENU_H_
#define MENU_H_

#include "MasterHeader.h"

class Menu
{
private:
	std::vector<std::string> _options;
	char _pressKey;
	int _pointer;
public:
	Menu();
	Menu& PushBackBeginOptions();
	void PrintMenuOptions();
	void CreateLoopMenu();
	~Menu();
};

void DrawGameName();
void DrawBox();
void DrawMan();
void DrawDinos();
void DrawBirds();
void DrawCars();
void DrawTrucks();
void DrawTree();
void DrawCloud();

#endif MENU_H_