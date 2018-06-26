#ifndef GUI_H_
#define GUI_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"

#define SPACE_ASCII						(char)(32)
#define UNDERSCORE_ASCII				(char)(95)
#define TOP_HALF_BLOCK_ASCII			(char)(223)
#define BOTTOM_HALF_BLOCK_ASCII			(char)(220)
#define BLOCK_ASCII						(char)(219)
#define A_WITH_DIAERESIS				(char)(142)
#define BOX_VERTICAL_ASCII				(char)(186)
#define BOX_HORIZONTAL_ASCII			(char)(205)
#define BOX_TOP_LEFT_CORNER_ASCII		(char)(201)
#define BOX_TOP_RIGHT_CORNER_ASCII		(char)(187)
#define BOX_BOTTOM_LEFT_CORNER_ASCII	(char)(200)
#define BOX_BOTTOM_RIGHT_CORNER_ASCII	(char)(188)

class CVEHICLE;
class CANIMAL;
class CPEOPLE;

class GUI final
{
	GUI() = default;
	~GUI() = default;
public:
	// go to (x, y) pos on console screen
	void static gotoXY(int x, int y);
	// use to clear the console, DO NOT use the system("cls");
	void static clearConsoleScreen();
	// draw the playground
	void static drawPlayArea();
	// use to draw objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void static redrawObjects(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList, CPEOPLE& player);
	// use to delete objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void static deleteObjects(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList, CPEOPLE& player);
	// Disable Maximize/Minimize button
	// Disable Maximize/Minimize button
	void static FixConsoleWindows();
	// Set Console size to WIDTH x HEIGHT
	void static SetWindowSize();
};

#endif GUI_H_




