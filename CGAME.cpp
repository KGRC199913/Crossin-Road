#include "CGAME.h"


CGAME* CGAME::_instance = nullptr;

CGAME::CGAME()
{
	_vehicles.clear();
	_animals.clear();
	_player = new CPEOPLE;
	_exitFLAG = false;
	_inputKeyHolder = ' ';
	_movementKeyHolder = ' ';
	for (auto& i : _trafficLight)
		i = false;
	for (auto& i : _reverseLane)
		i = false;
	_wonFLAG = false;
	_stopFLAG = false;
	_pauseFLAG = false;
	
	soundBufferArray[0].loadFromFile(BIRD_SOUND);
	soundBufferArray[1].loadFromFile(DINO_SOUND);
	soundBufferArray[2].loadFromFile(CAR_SOUND);
	soundBufferArray[3].loadFromFile(TRUCK_SOUND);
}

CGAME::~CGAME()
{
	clearGame();
	delete _player;
	_player = nullptr;
}

CGAME * CGAME::getInstance()
{
	if (_instance == nullptr) {
		_instance = new CGAME;
	}
	return _instance;
}

void CGAME::init()
{
	_stopFLAG = false;
	FINISH_FLAG = false;
	_exitFLAG = false;
	_wonPreviousLevel = false;
	_inputKeyHolder = ' ';
	_movementKeyHolder = ' ';
	int enemiesCount = _player->Level() * 4;
	int distance = 50 / (enemiesCount / 2);

	_vehicles.resize(enemiesCount);
	_animals.resize(enemiesCount);


	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_vehicles[i] = new CCAR;
			_vehicles[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 21);
			_animals[i] = new CBIRD;
			_animals[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 18);
		}
		else {
			_vehicles[i] = new CTRUCK;
			_vehicles[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 12);
			_animals[i] = new CDINOSAUR;
			_animals[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 15);
		}
	}

	_player->setCoord(41, 26);

	if (_player->Level() >= 4) {
		srand(time(NULL));

		for (auto& i : _trafficLight) {
			i = (((rand() % 10) % 2) == 0) ? true : false;
		}
	}

	GUI::drawInfoBox(*_player, _gameSpeed);
}

void CGAME::clearGame()
{
	for (auto& it : _vehicles) {
		delete it;
	}
	_vehicles.clear();

	for (auto& it : _animals) {
		delete it;
	}
	_animals.clear();
	for (auto& it : _trafficLight) {
		it = false;
	}
}

void CGAME::exitGame()
{
	_exitFLAG = true;
	_stopFLAG = true;
}

void CGAME::pauseGame()
{
	bool a = false;
	while (_pauseFLAG) {
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void CGAME::startGame(bool & isLoadSelected)
{
	if (isLoadSelected) {
		loadGame();
	}
	else
		init();
	_trafficManage = std::thread(&CGAME::trafficLightManage, this);
	_keyManage = std::thread(&CGAME::inputKey, this);
	gameloop();
	if (_trafficManage.joinable())
		_trafficManage.join();
	if (_keyManage.joinable())
		_keyManage.join();
	clearGame();
}

void CGAME::setDifficulties(int diffVal)
{
	switch (diffVal)
	{
	case 0: {
		_gameSpeed = NORMAL_SPEED;
		break;
	}
	case 1: {
		_gameSpeed = HARDCORE_SPEED;
		break;
	}
	case 2: {
		_gameSpeed = LUNATIC_SPEED;
		break;
	}
	default: {
		_gameSpeed = NORMAL_SPEED;
		break;
	}
		
	}
}

void CGAME::setSoundVol(int sfx_volume)
{
	soundPlayer.setVolume(sfx_volume);
}

bool CGAME::isExit() const
{
	return _exitFLAG;
}

bool CGAME::won() const
{
	return _wonFLAG;
}

bool CGAME::wonPreviousLevel() const
{
	return _wonPreviousLevel;
}

void CGAME::loadGame()
{
	clearGame();
	Database::loadGame(_vehicles, _animals, *_player, _trafficLight, _reverseLane, _gameSpeed);
	GUI::drawInfoBox(*_player, _gameSpeed);
}

void CGAME::saveGame()
{
	Database::saveGame(_vehicles, _animals, *_player, _trafficLight, _reverseLane, _gameSpeed);
}

void CGAME::soundEffectPlay()
{
	static int hitcount = 0;
	if (hitcount >= 10) {
		srand(int(time(NULL)));
	}

	if (soundPlayer.getStatus() != sf::SoundSource::Status::Playing) {
		int soundPick = rand() % 100;
		if (soundPick <= 3) {
			soundPlayer.setBuffer(soundBufferArray[soundPick]);
			soundPlayer.play();
			++hitcount;
		}
	}
}

void CGAME::trafficLightManage()
{
	while (!_stopFLAG) {
		if (_player->Level() >= 4) {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			for (auto& i : _trafficLight)
				i = !i;
		}
		else if (_trafficLight[0]) {
			std::fill(_trafficLight.begin(), _trafficLight.end(), false);
		}
	}
}

void CGAME::gameloop()
{
	
	while (!_stopFLAG) {
		GUI::gotoXY(0, 0);
		GUI::drawPlayArea();
		
		if (_inputKeyHolder == '1') {
			_inputKeyHolder = ' ';
			saveGame();
		}
		if (_inputKeyHolder == '2') {
			_inputKeyHolder = ' ';
			loadGame();
		}
			

		updatePosObjs();

		if (!_devModeFLAG) {
			for (auto it : _vehicles) {
				if (_player->isImpact(it)) {
					_stopFLAG = true;
					_wonFLAG = false;
					// insert effect code here
					break;
				}
			}

			for (auto it : _animals) {
				if (_player->isImpact(it)) {
					_stopFLAG = true;
					_wonFLAG = false;
					// insert effect code here
					break;
				}
			}
		}

		GUI::render(_vehicles, _animals, *_player, _trafficLight);
		soundEffectPlay();
		if (FINISH_FLAG == true) {
			if (_player->Level() == 5)
				_wonFLAG = true;
			break;
		}

		if (_pauseFLAG) {
			pauseGame();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(_gameSpeed));
	}

	if (FINISH_FLAG) {
		FINISH_FLAG = false;
		_wonPreviousLevel = true;
		_player->LevelUp();
	}

	_stopFLAG = true;
}

void CGAME::inputKey()
{
	char c = '\0';
	while (!_stopFLAG) {
		_inputKeyHolder = _getch();
		if (_inputKeyHolder == 'p')
			_pauseFLAG = !_pauseFLAG;
			
		if ((_inputKeyHolder == 27) && (!_pauseFLAG)) {
			exitGame();
			break;
		}
		if (((_inputKeyHolder == KEY_UP) || (_inputKeyHolder == KEY_DOWN)
			|| (_inputKeyHolder == KEY_LEFT) || (_inputKeyHolder == KEY_RIGHT)) && (!_pauseFLAG)) {
			_movementKeyHolder = _inputKeyHolder;
			_inputKeyHolder = ' ';
		}
		if (_inputKeyHolder == 'o') {
			_devModeFLAG = !_devModeFLAG;
		}
	}
}

void CGAME::updatePosPeople()
{
	if (_movementKeyHolder == KEY_UP) {
		_player->Up();
		_movementKeyHolder = ' ';
		return;
	}
		
	if (_movementKeyHolder == KEY_DOWN){
		_player->Down();
		_movementKeyHolder = ' ';
		return;
	}
		
	if (_movementKeyHolder == KEY_LEFT) {
		_player->Left();
		_movementKeyHolder = ' ';
		return;
	}
		
	if (_movementKeyHolder == KEY_RIGHT) {
		_player->Right();
		_movementKeyHolder = ' ';
		return;
	}
}

void CGAME::updatePosVehicle()
{
	int carMove = _trafficLight[0] ? 0 : 2;
	int truckMove = _trafficLight[3] ? 0 : 5;

	int enemiesCount = _player->Level() * 4;
	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_vehicles[i]->Move(carMove);
		}
		else {
			_vehicles[i]->Move(truckMove);
		}
	}
}

void CGAME::updatePosAnimal()
{
	int birdMove = _trafficLight[2] ? 0 : 3;
	int dinoMove = _trafficLight[1] ? 0 : 4;

	int enemiesCount = _player->Level() * 4;
	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_animals[i]->Move(birdMove);
		}
		else {
			_animals[i]->Move(dinoMove);
		}
	}
}

void CGAME::updatePosObjs()
{
	updatePosVehicle();
	updatePosAnimal();
	updatePosPeople();
}
