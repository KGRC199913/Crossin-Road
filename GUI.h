#ifndef GUI_H_
#define GUI_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"


class GUI final
{
	// draw the playground
	void drawPlayArea();
public:
	GUI();
	~GUI();
	
	// use to draw objects like CVEHICLE, CANIMAL, CPEOPLE in gameloop
	void redrawObjects(const std::vector<CVEHICLE> & vehicleList, const std::vector<CANIMAL> & animalList, const CPEOPLE& player);
	void deleteObjects(const std::vector<CVEHICLE> & vehicleList, const std::vector<CANIMAL> & animalList, const CPEOPLE& player);

};

#endif GUI_H_




