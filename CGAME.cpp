#include "CGAME.h"

char input_key;
bool STOP_FLAG;

CGAME::CGAME()
{
	_vehicles.clear();
	_animals.clear();
	_player = new CPEOPLE;
}


CGAME::~CGAME()
{
	for (auto& it : _vehicles) {
		delete it;
	}
	_vehicles.clear();

	for (auto& it : _animals) {
		delete it;
	}
	_animals.clear();

	delete _player;
	_player = nullptr;
}

void CGAME::init()
{
	int enemiesCount = _player->Level() * 2;
	
	_vehicles.resize(enemiesCount);
	_animals.resize(enemiesCount);

	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_vehicles[i] = new CCAR;
			_vehicles[i]->setCoord(21 + i, 21);
		}
		else {
			_vehicles[i] = new CTRUCK;
			_vehicles[i]->setCoord(21 + i, 12);
		}
	}

	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_animals[i] = new CBIRD;
			_animals[i]->setCoord(21 + i, 18);
		}
		else {
			_animals[i] = new CDINOSAUR;
			_animals[i]->setCoord(21 + i, 15);
		}
	}

	_player->setCoord(41, 26);
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
}

CPEOPLE CGAME::getPeople() const
{
	return *_player;
}

void CGAME::resetGame()
{
	clearGame();
}

void CGAME::exitGame()
{
	STOP_FLAG = true;
}

void CGAME::startGame()
{
	init();
	std::thread keyManageThread(&CGAME::inputKey, this);
	gameloop();
	keyManageThread.join();
}

void CGAME::loadGame(std::istream &)
{
	Database::loadGame(_vehicles, _animals, *_player);
}

void CGAME::saveGame(std::istream &)
{
	Database::saveGame(_vehicles, _animals, *_player);
}

void CGAME::pauseGame(HANDLE)
{
}

void CGAME::resumeGame(HANDLE)
{
}

void CGAME::gameloop()
{
	while (!STOP_FLAG) {
		GUI::clearConsoleScreen();
		GUI::drawPlayArea();
		if (input_key == 'p') {
			while (input_key != 'o') {}
		}

		updatePosVehicle();
		updatePosAnimal();
		updatePosPeople();

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
		GUI::deleteObjects(_vehicles, _animals, *_player);
		GUI::redrawObjects(_vehicles, _animals, *_player);
		if (FINISH_FLAG == true) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	FINISH_FLAG = false;
	_player->LevelUp();
}

void CGAME::inputKey()
{
	char c = '\0';
	STOP_FLAG = false;
	input_key = '\0';
	while (!STOP_FLAG) {
		input_key = _getch();
		if (input_key == 27) {
			STOP_FLAG = true;
			break;
		}
	}
}

void CGAME::updatePosPeople()
{
}

void CGAME::updatePosVehicle()
{
}

void CGAME::updatePosAnimal()
{
}
