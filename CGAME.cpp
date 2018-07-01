#include "CGAME.h"

bool STOP_FLAG;


CGAME::CGAME()
{
	_vehicles.clear();
	_animals.clear();
	_player = new CPEOPLE;
	_exitFlag = false;
	input_key = ' ';
	movement_key = ' ';
	for (auto& i : _trafficLight)
		i = false;
	for (auto& i : _reverseLane)
		i = false;
}


CGAME::~CGAME()
{
	clearGame();

	delete _player;
	_player = nullptr;
}

void CGAME::init()
{
	STOP_FLAG = false;
	FINISH_FLAG = false;
	_exitFlag = false;
	input_key = ' ';
	movement_key = ' ';
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

void CGAME::resetGame()
{
	clearGame();
}

void CGAME::exitGame()
{
	_exitFlag = true;
	STOP_FLAG = true;
}

void CGAME::pauseGame()
{
	input_key = ' ';
	while (input_key != 'g') {}
	input_key = ' ';
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
}

bool CGAME::isExit() const
{
	return _exitFlag;
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
	while (!STOP_FLAG) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		for (auto& i : _trafficLight)
			i = !i;
	}
}

void CGAME::gameloop()
{
	while (!STOP_FLAG) {
		// GUI::clearConsoleScreen();
		GUI::gotoXY(0, 0);
		GUI::drawPlayArea();

		updatePosObjs();

		for (auto it : _vehicles) {
			if (_player->isImpact(it)) {
				STOP_FLAG = true;
				// insert effect code here
				break;
			}
		}

		for (auto it : _animals) {
			if (_player->isImpact(it)) {
				STOP_FLAG = true;
				// insert effect code here
				break;
			}
		}
		//GUI::deleteObjects(_vehicles, _animals, *_player);
		GUI::redrawObjects(_vehicles, _animals, *_player);
		if (FINISH_FLAG == true) {
			//GUI::deleteObjects(_vehicles, _animals, *_player);
			GUI::redrawObjects(_vehicles, _animals, *_player);
			break;
		}

		if (input_key == 'g')
			pauseGame();

		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}

	if (FINISH_FLAG) {
		FINISH_FLAG = false;
		_player->LevelUp();
	}

	STOP_FLAG = true;
}

void CGAME::inputKey()
{
	char c = '\0';
	while (!STOP_FLAG) {
		input_key = _getch();
		if (input_key == 27) {
			exitGame();
			break;
		}
		if ((input_key == KEY_UP) || (input_key == KEY_DOWN)
			|| (input_key == KEY_LEFT) || (input_key == KEY_RIGHT)) {
			movement_key = input_key;
			input_key = ' ';
		}

	}
}

void CGAME::updatePosPeople()
{
	if (movement_key == KEY_UP) {
		_player->Up();
		movement_key = ' ';
		return;
	}
		
	if (movement_key == KEY_DOWN){
		_player->Down();
		movement_key = ' ';
		return;
	}
		
	if (movement_key == KEY_LEFT) {
		_player->Left();
		movement_key = ' ';
		return;
	}
		
	if (movement_key == KEY_RIGHT) {
		_player->Right();
		movement_key = ' ';
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
