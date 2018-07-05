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
	while (_pauseFLAG);
}

void CGAME::startGame()
{
	init();
	std::thread trafficManage;
	if (_player->Level() >= 4)
		trafficManage = std::thread(&CGAME::trafficLightManage, this);
	std::thread keyManageThread(&CGAME::inputKey, this);
	gameloop();
	if (trafficManage.joinable())
		trafficManage.join();
	keyManageThread.join();
	clearGame();
}

bool CGAME::isExit() const
{
	return _exitFLAG;
}

bool CGAME::won() const
{
	return _wonFLAG;
}

void CGAME::loadGame(std::istream &)
{
	Database::loadGame(_vehicles, _animals, *_player);
}

void CGAME::saveGame(std::istream &)
{
	Database::saveGame(_vehicles, _animals, *_player);
}

void CGAME::trafficLightManage()
{
	while (!_stopFLAG) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		for (auto& i : _trafficLight)
			i = !i;
	}
}

void CGAME::gameloop()
{
	while (!_stopFLAG) {
		// GUI::clearConsoleScreen();
		GUI::gotoXY(0, 0);
		GUI::drawPlayArea();

		if (_pauseFLAG)
			pauseGame();

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

		//GUI::deleteObjects(_vehicles, _animals, *_player);
		GUI::redrawObjects(_vehicles, _animals, *_player);
		if (FINISH_FLAG == true) {
			//GUI::deleteObjects(_vehicles, _animals, *_player);
			GUI::redrawObjects(_vehicles, _animals, *_player);
			_wonFLAG = true;
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(LUNATIC_SPEED));
	}

	if (FINISH_FLAG) {
		FINISH_FLAG = false;
		_player->LevelUp();
	}

	_stopFLAG = true;
}

void CGAME::inputKey()
{
	char c = '\0';
	while (!_stopFLAG) {
		_inputKeyHolder = _getch();
		if (_inputKeyHolder == 'g')
			_pauseFLAG = !_pauseFLAG;
		if (_inputKeyHolder == 27) {
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
