#ifndef MENU_H_
#define MENU_H_

#include "MasterHeader.h"

class Menu
{
private:
	static std::vector<std::string> _options;
	static char _pressKey;
	static int _pointer;
	static void PushBackBeginOptions();
	static void PrintMenuOptions();
	//MENU's DECORATION METHOD
	static void DrawGameName();
	static void DrawMenuBox();
	static void DrawMan();
	static void DrawDinos();
	static void DrawBirds();
	static void DrawCars();
	static void DrawTrucks();
	static void DrawTree();
	static void DrawCloud();
	static void PrintSubMenuOptions();
	static void PushBackLevelMenu();
	static void ChooseLevelBox();
	static void PushBackDifficultiesMenu();
	static void DifficultiesBox();
	static void PushBackPlayAgainMenu();
	static void PlayAgainBox();
	
public:
	Menu();
	static void CreateLoopMenu();
	static void DrawChooseLevelMenu();
	static void DrawDifficultiesMenu();
	static void DrawPlayAgainMenu();
	~Menu();
};

#endif MENU_H_