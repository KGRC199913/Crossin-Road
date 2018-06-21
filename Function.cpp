#include "Function.h"

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

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, r.left, r.top, WIDTH, HEIGHT, TRUE);
}

void DrawBox() {


	for (int coordX = 44; coordX < 61; ++coordX) {
		GotoXY(coordX, 20); std::cout << static_cast<char>(205);
		GotoXY(coordX, 26); std::cout << static_cast<char>(205);;
	}

	for (int coordY = 21; coordY <= 25; ++coordY) {
		GotoXY(44, coordY); std::cout << static_cast<char>(186);
		GotoXY(61, coordY); std::cout << static_cast<char>(186);
	}

	GotoXY(61, 20); std::cout << static_cast<char>(187);
	GotoXY(61, 26); std::cout << static_cast<char>(188);
	GotoXY(44, 20); std::cout << static_cast<char>(201);
	GotoXY(44, 26); std::cout << static_cast<char>(200);

}

void GotoXY(int coordX, int coordY) {
	COORD coord;
	coord.X = coordX;
	coord.Y = coordY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawMan() {
	GotoXY(100, 23);
	std::cout << R"abcd(
		     \o/
		      | 
		     / \ 
)abcd";
}

void DrawDinos() {
	GotoXY(80, 25);
	std::cout << static_cast<char>(32);
	std::cout << static_cast<char>(32);
	std::cout << static_cast<char>(32);
	std::cout << static_cast<char>(219);
	std::cout << static_cast<char>(223) << std::endl;
	GotoXY(81, 26);
	std::cout << static_cast<char>(220);
	std::cout << static_cast<char>(219);
	std::cout << static_cast<char>(219);
}

void DrawBirds() {
	GotoXY(80, 20);
	std::cout << static_cast<char>(223);
	std::cout << static_cast<char>(223);
	std::cout << static_cast<char>(220);
	std::cout << static_cast<char>(223);
	std::cout << static_cast<char>(223);
}

void DrawCars() {
	GotoXY(5, 25);
	std::cout << static_cast<char>(220);
	std::cout << static_cast<char>(219);
	std::cout << static_cast<char>(220);
}

void DrawTrucks() {
	GotoXY(13, 25);
	std::cout << static_cast<char>(219);
	std::cout << static_cast<char>(219);
	std::cout << static_cast<char>(220);
}

void DrawTree() {
	GotoXY(20, 19);
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
	GotoXY(100, 18);
	std::cout << R"abcd(
   ____           ____
 _(    )        _(    ) 
(___(__)       (___(__)             
)abcd";
}


