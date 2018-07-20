#include "GUI.h"



void GUI::drawPlayArea() {
	GUI::setWindowSize();
	//LeftOutline x = 19
	//RightOutline x = 71
	//1stLine y = 10
	//Distance between 2 line are 3 ( 10, 13, 16, 19, 22, 25)
	std::cout << R"abcd(
                       @@@@
                      @@@@~@
                     @@@~@@@@@
                      @@@@~@@
                       @@_@        {o}{o}{o}
                        ||          |  |  | 
                       _||_        \|/\|/\|/

                                                                           
                  ========================================================= 
                  |                                                       | 
                  |                                                       | 
                  |__  __  __  __  __  __  __  __  __  __  __  __  __  __ | 
                  |                                                       | 
                  |                                                       | 
                  | __  __  __  __  __  __  __  __  __  __  __  __  __  __| 
                  |                                                       | 
                  |                                                       | 
                  |__  __  __  __  __  __  __  __  __  __  __  __  __  __ | 
                  |                                                       | 
                  |                                                       | 
                  | __  __  __  __  __  __  __  __  __  __  __  __  __  __| 
                  |                                                       | 
                  |                                                       | 
                  =========================================================
                                                                           
                                                                    @@@@
                               ////-----------------\\\\           @@@@~@
                               ||  |   GOOOO!!!    |  ||          @@@~@@@@@
                               ||  |      GOOOO!!  |  ||           @@@@~@@
                               ||\\-----------------//||            @@_@
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
	player.draw_self();
	for (auto& it : vehicleList)
		it->draw_self_bw();
	for (auto& it : animalList)
		it->draw_self_bw();
}

void GUI::fixConsoleWindows()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GUI::setWindowSize()
{
	HWND console = GetConsoleWindow();
	RECT r = { 0 };
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, WIDTH, HEIGHT, TRUE);
}

void GUI::drawInfoBox(CPEOPLE & player, int gameSpeed)
{
	GUI::gotoXY(51, 0);
	std::cout << "Level: " << player.Level();

	GUI::gotoXY(51, 1);
	if (gameSpeed == NORMAL_SPEED)
		std::cout << "Mode: NORMAL" << std::endl;
	else if (gameSpeed == HARDCORE_SPEED)
		std::cout << "Mode: HARDCORE" << std::endl;
	else if (gameSpeed == LUNATIC_SPEED)
		std::cout << "Mode: LUNATIC" << std::endl;
	else std::cout << gameSpeed << std::endl;
		
	GUI::gotoXY(0, 0);
}

void GUI::initWindows()
{
	GUI::setWindowSize();
	GUI::fixConsoleWindows();
}

void GUI::render(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList, CPEOPLE & player, std::array<bool, 4> trafficState)
{
	GUI::redrawObjects(vehicleList, animalList, player);
	GUI::drawTrafficLight(trafficState);
}



void GUI::drawRedTrafficLight()
{
	//GUI::gotoXY(75, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII) << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
}

void GUI::drawGreenTrafficLight()
{
	//GUI::gotoXY(75, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	std::cout << char(TOP_HALF_BLOCK_ASCII) << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
}

void GUI::drawTrafficLight(std::array<bool, 4> trafficState)
{
	const unsigned coordX = 75;
	unsigned coordYRed = 11;
	unsigned coordYGreen = 12;
	for (int i = 0; i < trafficState.size(); ++i) {
		if (trafficState[i]) {
			GUI::gotoXY(coordX, coordYRed + (3 * i));
			GUI::drawRedTrafficLight();
		}
		else {
			GUI::gotoXY(coordX, coordYGreen + (3 * i));
			GUI::drawGreenTrafficLight();
		}
	}
}

void GUI::gotoXY(int x, int y)
{
	COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
