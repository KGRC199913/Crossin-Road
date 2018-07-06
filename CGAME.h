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

#define NORMAL_SPEED 75
#define HARDCORE_SPEED 25
#define LUNATIC_SPEED 5

#define BGM_PATH "DeepInAbyss.wav"
#define BIRD_SOUND "Bird.wav"
#define DINO_SOUND "Dino.wav"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100

class CGAME final
{
	static CGAME* _instance;
	CPEOPLE* _player;
	std::array<bool, 4> _trafficLight;
	std::array<bool, 4> _reverseLane;
	char _movementKeyHolder;
	char _inputKeyHolder;
	bool _exitFLAG;
	bool _wonFLAG;
	bool _stopFLAG;
	bool _devModeFLAG = false;
	bool _pauseFLAG = false;
	bool _wonPreviousLevel = false;
	std::vector<CVEHICLE*> _vehicles;
	std::vector<CANIMAL*> _animals;
	std::thread _trafficManage;
	std::thread _keyManage;

	void trafficLightManage();
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
	void loadGame();
	void saveGame();
	CGAME();
	
public:
	
	static CGAME* getInstance();
	CGAME(const CGAME& other) = delete;
	void operator=(const CGAME& other) = delete;

	void startGame();
	bool isExit() const;
	bool won() const;
	bool wonPreviousLevel() const;

	~CGAME();
};

#endif CGAME_H_





