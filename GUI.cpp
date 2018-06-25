#include "GUI.h"



void GUI::drawPlayArea() {
	GUI::SetWindowSize();
	//LeftOutline x = 19
	//RightOutline x = 71
	//1stLine y = 10
	//Distance between 2 line are 3 ( 10, 13, 16, 19, 22, 25)
	std::cout << R"abcd(
                       @@@@        
                      @@@@~@ 
                     @@@~@@@@@                         /  /          /  / 
                      @@@@~@@                          \O/           \O/ 
                       @@_@        {o}{o}{o}            |             |
                        ||          |  |  |            / \           / \
                       _||_        \|/\|/\|/          /  /          /  /
                  
                  
                  =========================================================
                  |                                                       |
                  |                                                       |
                  |_______________________________________________________|
                  |                                                       |
                  |                                                       |
                  |_______________________________________________________|
                  |                                                       |
                  |                                                       |
                  |_______________________________________________________|
                  |                                                       |
                  |                                                       |
                  |_______________________________________________________|
                  |                                                       |
                  |                                                       |
                  =========================================================
                  
                   \  \                                             @@@@
                    \O/        ////-----------------\\\\           @@@@~@
                     |         ||  |   GOOOO!!!    |  ||          @@@~@@@@@
                    / \        ||  |      GOOOO!!  |  ||           @@@@~@@
                   /  /        ||\\-----------------//||            @@_@
                               ||                     ||             ||
                             __||__                 __||__          _||_	
)abcd";
}

void GUI::clearConsoleScreen()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void GUI::redrawObjects(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList, CPEOPLE & player)
{
	for (auto& it : vehicleList)
		it->draw_self();
	for (auto& it : animalList)
		it->draw_self();
	player.draw_self();
}

void GUI::deleteObjects(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList, CPEOPLE & player)
{
	for (auto& it : vehicleList)
		it->delete_self();
	for (auto& it : animalList)
		it->delete_self();
	player.delete_self();
}


void GUI::FixConsoleWindows()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GUI::SetWindowSize()
{
	HWND console = GetConsoleWindow();
	RECT r = { 0 };
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, WIDTH, HEIGHT, TRUE);
}

void GUI::gotoXY(int x, int y)
{
	COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
