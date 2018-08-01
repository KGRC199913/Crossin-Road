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
#include <SFML\Audio.hpp>

#define NORMAL_SPEED 75
#define HARDCORE_SPEED 50
#define LUNATIC_SPEED 25

#define BGM_PATH "./bgm.ogg"
#define BIRD_SOUND "./Bird.ogg"
#define DINO_SOUND "./Dino.ogg"
#define CAR_SOUND "./Car.ogg"
#define TRUCK_SOUND "./Truck.ogg"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100

class Database;

class CGAME final
{
	static CGAME* s_instance;
	CPEOPLE* _player;
	std::array<bool, 4> _trafficLight;
	std::array<bool, 4> _reverseLane;
	int _gameSpeed = 0;
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
	std::array<sf::SoundBuffer, 4> soundBufferArray;
	sf::Sound soundPlayer;

	void trafficLightManage();
	void gameloop();
	void inputKey();
	void updatePosPeople();
	void updatePosVehicle();
	void updatePosAnimal();
	void updatePosObjs();
	void init();
	void exitGame();
	void pauseGame();
	void loadGame();
	void saveGame();
	void soundEffectPlay();
	CGAME();
public:
	static CGAME* getInstance();

	void startGame(bool & isLoadSelected);
	void clearGame();

	CGAME(const CGAME& other) = delete;
	void operator=(const CGAME& other) = delete;
	
	void setDifficulties(int diffVal);
	void setSoundVol(int sfx_volume);

	bool isExit() const;
	bool won() const;
	bool wonPreviousLevel() const;


	~CGAME();
};

#endif CGAME_H_





