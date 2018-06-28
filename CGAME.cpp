#include "CGAME.h"

char input_key;
bool STOP_FLAG;
char movement_key;

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
	int enemiesCount = _player->Level() * 4;
	int distance = 40 / (enemiesCount / 2);

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
		// GUI::clearConsoleScreen();
		GUI::gotoXY(0, 0);
		GUI::drawPlayArea();
		if (input_key == 'g') {
			input_key = ' ';
			while (input_key != 'g') {}
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
			GUI::deleteObjects(_vehicles, _animals, *_player);
			GUI::redrawObjects(_vehicles, _animals, *_player);
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
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
		if ((input_key == KEY_UP) || (input_key == KEY_DOWN)
			|| (input_key == KEY_LEFT) || (input_key == KEY_RIGHT)) {
			movement_key = input_key;
		}

		if (input_key == 27) {
			STOP_FLAG = true;
			break;
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
	int enemiesCount = _player->Level() * 4;
	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_vehicles[i]->Move(1);
		}
		else {
			_vehicles[i]->Move(5);
		}
	}
}

void CGAME::updatePosAnimal()
{
	int enemiesCount = _player->Level() * 4;
	for (auto i = 0; i < enemiesCount; ++i) {
		if (i <= (enemiesCount / 2) - 1) {
			_animals[i]->Move(3);
		}
		else {
			_animals[i]->Move(4);
		}
	}
}
