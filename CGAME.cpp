#include "CGAME.h"


CGAME* CGAME::s_instance = nullptr;

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
	s_instance = nullptr;
}

CGAME * CGAME::getInstance()
{
	if (s_instance == nullptr) {
		s_instance = new CGAME;
	}
	return s_instance;
}


// init the game's data
void CGAME::init()
{
	// init the flag
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

	// create enemies
	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) { //divide by half for each type of enemy
			_vehicles[i] = new CCAR;
			_vehicles[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 21);
			_animals[i] = new CBIRD;
			_animals[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 18);
		}
		else { // this too
			_vehicles[i] = new CTRUCK;
			_vehicles[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 12);
			_animals[i] = new CDINOSAUR;
			_animals[i]->setCoord(21 + distance*(i % (enemiesCount / 2)), 15);
		}
	}

	// set start position
	_player->setCoord(41, 24);

	// random light status
	if (_player->Level() >= 4) {
		srand(time(NULL));
		// create a random number from 0 - 10, if odd => red, even => green
		for (auto& i : _trafficLight) {
			i = (((rand() % 10) % 2) == 0) ? true : false;
		}	
	}

	for (auto& i : _reverseLane) {
		i = (((rand() % 10) % 2) == 0) ? true : false;
	}

	GUI::drawInfoBox(*_player, _gameSpeed);
}

void CGAME::clearGame()
{
	for (auto it : _vehicles) {
		delete(it);
	}
	_vehicles.clear();
	_vehicles.shrink_to_fit();

	for (auto it : _animals) {
		delete(it);
	}
	_animals.clear();
	_animals.shrink_to_fit();
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
	while (_pauseFLAG) {
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void CGAME::startGame(bool & isLoadSelected)
{
	if (isLoadSelected) {
		Database::triggerMainPaused(true);
		loadGame();
		Database::triggerMainPaused(false);
		GUI::clearConsoleScreen();
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
			std::this_thread::sleep_for(std::chrono::seconds(1));
			for (auto& i : _trafficLight)
				i = !i;
		}
		else if (_trafficLight[0]) {
			std::fill(_trafficLight.begin(), _trafficLight.end(), false);
		}
	}
}

// main game loop
// being call by CGAME::startgame()
// do not try to call
void CGAME::gameloop()
{
	// draw the play area
	GUI::gotoXY(0, 0);
	GUI::drawPlayArea();

	// the loop
	while (!_stopFLAG) {
		GUI::redrawRoads();
		
		// move the vehicle
		updatePosObjs();
		GUI::render(_vehicles, _animals, *_player, _trafficLight, _reverseLane);
		// check if impact
		if (!_devModeFLAG) {
			for (auto it : _vehicles) {
				if (_player->isImpact(it)) {
					//_player->draw_dead_self();
					_stopFLAG = true;
					_wonFLAG = false;
					GUI::drawLosingScene();
					break;
				}
			}

			if (_stopFLAG)
				break;

			for (auto it : _animals) {
				if (_player->isImpact(it)) {
					//_player->draw_dead_self();
					_stopFLAG = true;
					_wonFLAG = false;
					GUI::drawLosingScene();
					break;
				}
			}

			if (_stopFLAG)
				break;
		}

		// render eveything other than play area

		soundEffectPlay();

		// check if win
		if (FINISH_FLAG == true) {
			if (_player->Level() == 5) {
				_wonFLAG = true;
				//_player->draw_win_dance();
			}
			break;
		}

		// check if pause
		if (_pauseFLAG) {
			GUI::clearConsoleScreen();
			Database::triggerMainPaused(true);
			pauseGame();
			Database::triggerMainPaused(false);
			GUI::gotoXY(0, 0);
			GUI::drawPlayArea();
			continue;
		}

		// pause the loop (speed depends on difficulty
		std::this_thread::sleep_for(std::chrono::milliseconds(_gameSpeed));
	}

	// check if won
	if (FINISH_FLAG) {
		FINISH_FLAG = false;
		_wonPreviousLevel = true;
		_player->LevelUp();
		_player->draw_win_dance();
	}

	_stopFLAG = true;
}

void CGAME::inputKey()
{
	char c = '\0';
	while (!_stopFLAG) {
		_inputKeyHolder = _getch();
		
		// check in needs of saving
		if (_inputKeyHolder == '1') {
			_pauseFLAG = true;
			_inputKeyHolder = ' ';
			saveGame();
			_pauseFLAG = false;
		}
		// or loading
		if (_inputKeyHolder == '2') {
			_pauseFLAG = true;
			_inputKeyHolder = ' ';
			loadGame();
			_pauseFLAG = false;
		}

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
	if (_reverseLane[0])
		carMove *= -1;

	int truckMove = _trafficLight[3] ? 0 : 5;
	if (_reverseLane[3])
		truckMove *= -1;

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
	if (_reverseLane[1])
		birdMove *= -1;

	int dinoMove = _trafficLight[1] ? 0 : 4;
	if (_reverseLane[2])
		dinoMove *= -1;

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
