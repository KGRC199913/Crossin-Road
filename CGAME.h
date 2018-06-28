#ifndef CGAME_H_
#define CGAME_H_
#include "masterheader.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"
#include "CPEOPLE.h"
#include "GUI.h"
#include "Database.h"

class CGAME final
{
	std::vector<CVEHICLE*> _vehicles;
	std::vector<CANIMAL*> _animals;
	CPEOPLE* _player;
	void gameloop();
	void inputKey();
	void updatePosPeople();
	void updatePosVehicle();
	void updatePosAnimal();
	void init();
	void clearGame();
public:
	CGAME();
	~CGAME();

	CPEOPLE getPeople() const;
	std::vector<CVEHICLE*> getVehicle() const;
	std::vector<CANIMAL*> getAnimal() const;

	void resetGame();
	void exitGame();
	void startGame();
	
	void loadGame(std::istream &);
	void saveGame(std::istream &);

	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
};

#endif CGAME_H_





