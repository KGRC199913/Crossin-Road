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
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DrawBox() {


	for (int coordX = 44; coordX < 61; ++coordX) {
		GotoXY(coordX, 20); std::cout << static_cast<char>(205);
		GotoXY(coordX, 25); std::cout << static_cast<char>(205);;
	}

	for (int coordY = 21; coordY <= 24; ++coordY) {
		GotoXY(44, coordY); std::cout << static_cast<char>(186);
		GotoXY(61, coordY); std::cout << static_cast<char>(186);
	}

	GotoXY(61, 20); std::cout << static_cast<char>(187);
	GotoXY(61, 25); std::cout << static_cast<char>(188);
	GotoXY(44, 20); std::cout << static_cast<char>(201);
	GotoXY(44, 25); std::cout << static_cast<char>(200);

}

void GotoXY(int coordX, int coordY) {
	COORD coord;
	coord.X = coordX;
	coord.Y = coordY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}