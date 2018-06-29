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
	bool EXIT_FLAG;
	char input_key;
	char movement_key;

	void gameloop();
	void inputKey();
	void updatePosPeople();
	void updatePosVehicle();
	void updatePosAnimal();
	void updatePosObjs();
	void init();
	void clearGame();
	void exitGame();
	void pauseGame();
	void loadGame(std::istream &);
	void saveGame(std::istream &);
public:
	CGAME();
	~CGAME();

	void resetGame();
	
	void startGame();
	bool isExit() const;

	
};

#endif CGAME_H_





