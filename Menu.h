#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>

class Menu
{
private:
	 std::vector<std::string> options;
	 char pressKey;
	 int pointer;
public:
	Menu();
	Menu& PushBackBeginOptions();
	void PrintMenuOptions();
	void CreateLoopMenu();
	~Menu();
};

void DrawGameName();
void FixConsoleWindow();