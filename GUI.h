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

#ifndef NORMAL_SPEED
#define NORMAL_SPEED 75
#define HARDCORE_SPEED 50
#define LUNATIC_SPEED 25
#endif


class CVEHICLE;
class CANIMAL;
class CPEOPLE;

class GUI final
{
	GUI() = delete;
	~GUI() = delete;
	void static fixConsoleWindows();
	void static setWindowSize();
	// use to draw objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void static drawRedTrafficLight();
	void static drawGreenTrafficLight();
	void static drawTrafficLight(std::array<bool, 4> trafficState);
	void static redrawObjects(std::vector<CVEHICLE*> & vehicleList,
		std::vector<CANIMAL*> & animalList, CPEOPLE& player, std::array<bool, 4> reverseLaneFlag);
public:
	// go to (x, y) pos on console screen
	void static gotoXY(int x, int y);
	// use to clear the console, DO NOT use the system("cls");
	void static clearConsoleScreen();
	// draw the playground
	void static drawPlayArea();
	void static redrawRoads();
	// use to delete objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	
	void static drawInfoBox(CPEOPLE & playerInfo, int gameSpeed);
	// Disable Maximize/Minimize button
	// Set Console size to WIDTH x HEIGHT
	void static initWindows();
	void static render(std::vector<CVEHICLE*> & vehicleList,
				std::vector<CANIMAL*> & animalList, CPEOPLE& player, std::array<bool, 4> trafficState, std::array<bool, 4> reverseLanes);
	
};

#endif GUI_H_




