#include "Database.h"

void Database::loadVehicles(std::ifstream & saveFile, int objCount, std::vector<CVEHICLE*>& vehicleList)
{
	CVEHICLE * vechiclePtr = nullptr;
	vehicleList.resize(objCount);
	for (int i = 0; i < objCount; ++i) {
		if (i <= (objCount / 2) - 1) {
			vechiclePtr = new CCAR;
			saveFile.read(reinterpret_cast<char*>(vechiclePtr), sizeof(CCAR));
			vehicleList[i] = new CCAR(*reinterpret_cast<CCAR*>(vechiclePtr));
			delete vechiclePtr;
		}
		else {
			vechiclePtr = new CTRUCK;
			saveFile.read(reinterpret_cast<char*>(vechiclePtr), sizeof(CTRUCK));
			vehicleList[i] = new CTRUCK(*reinterpret_cast<CTRUCK*>(vechiclePtr));
			delete vechiclePtr;
		}
	}
}

void Database::loadAnimals(std::ifstream & saveFile, int objCount, std::vector<CANIMAL*>& animalList)
{
	CANIMAL * animalPtr = nullptr;
	animalList.resize(objCount);
	for (int i = 0; i < objCount; ++i) {
		if (i <= (objCount / 2) - 1) {
			animalPtr = new CBIRD;
			saveFile.read(reinterpret_cast<char*>(animalPtr), sizeof(CBIRD));
			animalList[i] = new CBIRD(*reinterpret_cast<CBIRD*>(animalPtr));
			delete animalPtr;
		}
		else {
			animalPtr = new CDINOSAUR;
			saveFile.read(reinterpret_cast<char*>(animalPtr), sizeof(CDINOSAUR));
			animalList[i] = new CDINOSAUR(*reinterpret_cast<CDINOSAUR*>(animalPtr));
			delete animalPtr;
		}
	}
}

void Database::loadStatuses(std::ifstream & saveFile, std::array<bool, 4>& trafficLightStatus, std::array<bool, 4>& reverseLaneStatus, int & gameSpeed)
{
	saveFile.read(static_cast<char*>(static_cast<void*>(&trafficLightStatus)), sizeof(trafficLightStatus));
	saveFile.read(static_cast<char*>(static_cast<void*>(&reverseLaneStatus)), sizeof(reverseLaneStatus));
	saveFile.read(static_cast<char*>(static_cast<void*>(&gameSpeed)), sizeof(gameSpeed));
}

void Database::saveGame(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList,
	CPEOPLE & player, std::array<bool, 4> trafficLightStatus, std::array<bool, 4> reverseLaneStatus, int & gameSpeed)
{
	std::ofstream saveFile(SAVE_PATH, std::ios::binary);
	if (!saveFile) {
		std::cerr << "Error Saving Game" << std::endl;
		return;
	}
	saveFile.write(static_cast<char*>(static_cast<void*>(&player)), sizeof(player));
	for (auto& it : vehicleList) {
		saveFile.write(static_cast<char*>(static_cast<void*>(it)), sizeof(CVEHICLE));
	}
	for (auto& it : animalList) {
		saveFile.write(static_cast<char*>(static_cast<void*>(it)), sizeof(CANIMAL));
	}
	saveFile.write(static_cast<char*>(static_cast<void*>(&trafficLightStatus)), sizeof(trafficLightStatus));
	saveFile.write(static_cast<char*>(static_cast<void*>(&reverseLaneStatus)), sizeof(reverseLaneStatus));
	saveFile.write(static_cast<char*>(static_cast<void*>(&gameSpeed)), sizeof(gameSpeed));

	saveFile.close();
}

// DO NOT TRY TO CHANGE THIS METHOD WITHOUT ASKING
// Load game from a binary file
// Please ensure that the object in vehicle and animal were been clean before calling this function, or memory leak may occurs
void Database::loadGame(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList,
	CPEOPLE & player, std::array<bool, 4> & trafficLightStatus, std::array<bool, 4> & reverseLaneStatus, int & gameSpeed)
{
	try {
		std::ifstream saveFile(SAVE_PATH, std::ios::binary);
		if (!saveFile) {
			throw std::exception::exception("FATAL ERROR: ERROR LOADING SAVE FILE");
		}

		// read player
		saveFile.read(static_cast<char*>(static_cast<void*>(&player)), sizeof(player));
		int objCount = player.Level() * 4;


		// read the enemies
		// vehicles
		Database::loadVehicles(saveFile, objCount, vehicleList);

		// animals
		Database::loadAnimals(saveFile, objCount, animalList);

		// read the remain status
		Database::loadStatuses(saveFile, trafficLightStatus, reverseLaneStatus, gameSpeed);

		// shrink vectors
		vehicleList.shrink_to_fit();
		animalList.shrink_to_fit();
		saveFile.close();
	}
	catch (std::exception e) {
		CGAME* cg = CGAME::getInstance();
		cg->~CGAME();
		exit(FAST_FAIL_FATAL_APP_EXIT);
	}
}
