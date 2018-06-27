#include "CGAME.h"
// Use to Debug only
// pseudo-main
int main() {
	std::vector<CVEHICLE*> vecH;
	std::vector<CANIMAL*> vecA;
	CCAR carTemp;
	CTRUCK truckTemp;
	CBIRD birdTemp;
	CDINOSAUR dinoTemp;
	CPEOPLE playerTemp;

	carTemp.setCoord(10, 10);
	truckTemp.setCoord(10, 15);
	birdTemp.setCoord(10, 20);
	dinoTemp.setCoord(10, 25);

	vecH.push_back(&carTemp);
	vecH.push_back(&truckTemp);

	vecA.push_back(&birdTemp);
	vecA.push_back(&dinoTemp);

	GUI::FixConsoleWindows();
	GUI::SetWindowSize();
	GUI::redrawObjects(vecH, vecA, playerTemp);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	GUI::deleteObjects(vecH, vecA, playerTemp);
	return 0;
}
//