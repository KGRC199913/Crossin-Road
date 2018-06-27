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

void DrawBox() {


	for (int coordX = 44; coordX < 61; ++coordX) {
		GUI::gotoXY(coordX, 20); std::cout << (char)(205);
		GUI::gotoXY(coordX, 26); std::cout << (char)(205);;
	}

	for (int coordY = 21; coordY <= 25; ++coordY) {
		GUI::gotoXY(44, coordY); std::cout << (char)(186);
		GUI::gotoXY(61, coordY); std::cout << (char)(186);
	}

	GUI::gotoXY(61, 20); std::cout << (char)(187);
	GUI::gotoXY(61, 26); std::cout << (char)(188);
	GUI::gotoXY(44, 20); std::cout << (char)(201);
	GUI::gotoXY(44, 26); std::cout << (char)(200);

}

void DrawMan() {
	GUI::gotoXY(100, 23);
	std::cout << R"abcd(
		     \o/
		      | 
		     / \ 
)abcd";
}

void DrawDinos() {
	GUI::gotoXY(80, 25);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(32);
	std::cout << (char)(219);
	std::cout << (char)(223) << std::endl;
	GUI::gotoXY(81, 26);
	std::cout << (char)(220);
	std::cout << (char)(219);
	std::cout << (char)(219);
}

void DrawBirds() {
	GUI::gotoXY(80, 20);
	std::cout << (char)(223);
	std::cout << (char)(223);
	std::cout << (char)(220);
	std::cout << (char)(223);
	std::cout << (char)(223);
}

void DrawCars() {
	GUI::gotoXY(5, 25);
	std::cout << (char)(220);
	std::cout << (char)(219);
	std::cout << (char)(220);
}

void DrawTrucks() {
	GUI::gotoXY(13, 25);
	std::cout << (char)(219);
	std::cout << (char)(219);
	std::cout << (char)(220);
}

void DrawTree() {
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

void DrawCloud() {
	GUI::gotoXY(100, 18);
	std::cout << R"abcd(
   ____           ____
 _(    )        _(    ) 
(___(__)       (___(__)             
)abcd";
}


