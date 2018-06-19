#ifndef CGAME_H_
#define CGAME_H_
#include "MasterHeader.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"
#include "CPEOPLE.h"

bool STOP_FLAG = false;
bool FINISH_FLAG = false;
class CGAME
{
	CTRUCK* _truckArray;
	CCAR* _carArray;
	CDINOSAUR* _dinosaurArray;
	CBIRD* _birdArray;
	CPEOPLE player;
public:
	CGAME();
	~CGAME();

	void drawGame();

	CPEOPLE getPeople();
	CVEHICLE* getVehicle();
	CANIMAL* getAnimal();
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void loadGame(std::istream &);
	void saveGame(std::istream &);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();
};

#endif CGAME_H_





