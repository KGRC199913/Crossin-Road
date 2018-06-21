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

bool STOP_FLAG = false;
bool FINISH_FLAG = false;
class CGAME final
{
	std::vector <CTRUCK> _truckArray;
	std::vector <CCAR> _carArray;
	std::vector <CDINOSAUR> _dinosaurArray;
	std::vector <CBIRD> _birdArray;
	CPEOPLE _player;
public:
	CGAME();
	~CGAME();

	void init();

	CPEOPLE getPeople();
	std::vector<CVEHICLE> getVehicle() const;
	std::vector<CANIMAL> getAnimal() const;

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





