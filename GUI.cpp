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

void GUI::redrawRoads()
{
	GUI::gotoXY(19, 9);
	std::cout << R"abcd(
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

void GUI::redrawObjects(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList,
	CPEOPLE & player, std::array<bool, 4> reverseLaneFlag)
{
	player.draw_self();

	int enemiesCount = player.Level() * 4;
	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
				vehicleList[i]->draw_self();
				animalList[i]->draw_self();
		}
		else {
			if (reverseLaneFlag[3])
				vehicleList[i]->draw_self();
			else
				vehicleList[i]->draw_self_bw();

			if (reverseLaneFlag[2])
				animalList[i]->draw_self();
			else
				animalList[i]->draw_self_bw();
		}
	}
}

void GUI::hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
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
	GUI::hideCursor();
}

void GUI::render(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList,
	CPEOPLE & player, std::array<bool, 4> trafficState, std::array<bool, 4> reverseLanes)
{
	GUI::redrawObjects(vehicleList, animalList, player, reverseLanes);
	GUI::drawTrafficLight(trafficState);
}

void GUI::drawLoadingBar()
{
	GUI::clearConsoleScreen();

	int coordY;


	for (coordY = 34; coordY < 75; coordY++)
	{
		GUI::gotoXY(coordY, 14); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordY, 16); std::cout << char(BOX_HORIZONTAL_ASCII);;
	}
	for (coordY = 14; coordY < 16; coordY++)
	{
		GUI::gotoXY(34, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(75, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(75, 14); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(75, 16); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(34, 14); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(34, 16); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);


	int per = 0;
	GUI::gotoXY(50, 13);  std::cout << "LOADING";
	for (int i = 0; i < 20; i++)
	{
		GUI::gotoXY(35 + 2 * i, 15);  std::cout << char(BLOCK_ASCII);
		for (int i = 1; i < 6; i++)
		{
			GUI::gotoXY(51, 17); std::cout << per + i << "%";
			Sleep(20);
		}
		per += 5;
	}
}

void GUI::drawWinningScene()
{
	GUI::gotoXY(0, 0);
	GUI::clearConsoleScreen();
	std::cout << R"abcd(
           __  __              __                              
          /\ \/\ \  __        /\ \__                           
          \ \ \ \ \/\_\    ___\ \ ,_\   ___   _ __   __  __    
           \ \ \ \ \/\ \  /'___\ \ \/  / __`\/\`'__\/\ \/\ \   
            \ \ \_/ \ \ \/\ \__/\ \ \_/\ \L\ \ \ \/ \ \ \_\ \  
             \ `\___/\ \_\ \____\\ \__\ \____/\ \_\  \/`____ \ 
              `\/__/  \/_/\/____/ \/__/\/___/  \/_/   `/___/> \
                                                         /\___/
                                                         \/__/ 


                           --THANKS FOR PLAYING--
                            --HOPE YOU ENJOY IT--
)abcd";
	std::cout << std::endl;
}

void GUI::drawLosingScene()
{
	GUI::gotoXY(0, 0);
	GUI::clearConsoleScreen();
	std::cout << R"abcd(
                                   +-------------+         
                                   |   HOSPITAL  |         
                                   +---n-----n---+ 
                         _._._._       |._._.|       _._._._ 
                         | ___ |_._._._| ___ |_._._._| ___ |
                         | |_| |  ___  | |_| |  ___  | |_| |
                         |_III_|  |_|  |_III_|  |_|  |_III_| 
                         | ___ |__III__| ___ |__III__| ___ |
                         | |_| |  ___  | |_| |  ___  | |_| |   
                         |_III_|  |_|  |_III_|  |_|  |_III_|  ( )
                         | ___ |__III__| ___ |__III__| ___ |(_) (_)
                         | |_| |  ___  | |_| |  ___  | |_| | /(|)\
                         |_III_|  |_|  |_III_|  |_|  |_III_|   H
                         | ___ |__III__|_____|__III__| ___ |   H
                         | |_| |"""""""||~|~||"""""""| |_| |   H
                         |_III_|@@@@@@@||_|_||@@@@@@@|_III_|   H 
                   @@@@@@@@@@@@@@     @/=====\@     @@@@@@@@@@@@@@

                               "YOU SHALL NOT PASS!!!!"
)abcd";
	std::cout << std::endl;
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
