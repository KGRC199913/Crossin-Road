#ifndef GUI_H_
#define GUI_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"


class GUI final
{
	
	
	// go to (x, y) pos on console screen
	void static gotoXY(int x, int y);
public:
	GUI() = default;
	~GUI() = default;
	// use to clear the console, DO NOT use the system("cls");
	void static clearConsoleScreen();
	// draw the playground
	void static drawPlayArea();

	// use to draw objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void static redrawObjects(std::vector<CVEHICLE> & vehicleList, std::vector<CANIMAL> & animalList, CPEOPLE& player);
	// use to delete objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void static deleteObjects(std::vector<CVEHICLE> & vehicleList, std::vector<CANIMAL> & animalList, CPEOPLE& player);
	// Disable Maximize/Minimize button
	void static FixConsoleWindows();
	// Set Console size to WIDTH x HEIGHT
	void static SetWindowSize();
};

#endif GUI_H_




