#ifndef GUI_H_
#define GUI_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"

#define SPACE_ASCII                     32
#define UNDERSCORE_ASCII                95
#define TOP_HALF_BLOCK_ASCII            223
#define BOTTOM_HALF_BLOCK_ASCII         220
#define BLOCK_ASCII                     219
#define A_WITH_DIAERESIS                142
#define BOX_VERTICAL_ASCII              186
#define BOX_HORIZONTAL_ASCII            205
#define BOX_TOP_LEFT_CORNER_ASCII       201
#define BOX_TOP_RIGHT_CORNER_ASCII      187
#define BOX_BOTTOM_LEFT_CORNER_ASCII    200
#define BOX_BOTTOM_RIGHT_CORNER_ASCII   188

class CVEHICLE;
class CANIMAL;
class CPEOPLE;

class GUI final
{
	GUI() = default;
	~GUI() = delete;
	
	void static fixConsoleWindows();
	void static setWindowSize();
	// use to draw objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	
public:
	// go to (x, y) pos on console screen
	void static gotoXY(int x, int y);
	// use to clear the console, DO NOT use the system("cls");
	void static clearConsoleScreen();
	// draw the playground
	void static drawPlayArea();
	void static redrawObjects(std::vector<CVEHICLE*> & vehicleList,
		std::vector<CANIMAL*> & animalList, CPEOPLE& player);
	// use to delete objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void static deleteObjects(std::vector<CVEHICLE*> & vehicleList,
		std::vector<CANIMAL*> & animalList, CPEOPLE& player);
	
	// Disable Maximize/Minimize button
	// Set Console size to WIDTH x HEIGHT
	void static initWindows();
	void static render(std::vector<CVEHICLE*> & vehicleList,
				std::vector<CANIMAL*> & animalList, CPEOPLE& player);

};

#endif GUI_H_




