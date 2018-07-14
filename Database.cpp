#include "Database.h"

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


// Please ensure that the object in vehicle and animal were been clean before calling this function, or memory leak may occurs
void Database::loadGame(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList,
	CPEOPLE & player, std::array<bool, 4> & trafficLightStatus, std::array<bool, 4> & reverseLaneStatus, int & gameSpeed)
{
	std::ifstream saveFile(SAVE_PATH, std::ios::binary);
	if (!saveFile) {
		std::cerr << "Error Saving Game" << std::endl;
		return;
	}
	vehicleList.clear();
	animalList.clear();
	vehicleList.shrink_to_fit();
	animalList.shrink_to_fit();

	saveFile.read(static_cast<char*>(static_cast<void*>(&player)), sizeof(player));
	int objCount = player.Level() * 4;

	vehicleList.resize(objCount);
	for (int i = 0; i < objCount; ++i) {
		if (i <= (objCount / 2) - 1) {
			CCAR* carPointer = new CCAR;
			saveFile.read(reinterpret_cast<char*>(carPointer), sizeof(CCAR));
			vehicleList[i] = new CCAR(*carPointer);
			delete carPointer;
		}
		else {
			CTRUCK* truckPointer = new CTRUCK;
			saveFile.read(reinterpret_cast<char*>(truckPointer), sizeof(CTRUCK));
			vehicleList[i] = new CTRUCK(*truckPointer);
			delete truckPointer;
		}
	}

	animalList.resize(objCount);
	for (int i = 0; i < objCount; ++i) {
		if (i <= (objCount / 2) - 1) {
			CBIRD* birdPointer = new CBIRD;
			saveFile.read(reinterpret_cast<char*>(birdPointer), sizeof(CBIRD));
			animalList[i] = new CBIRD(*birdPointer);
			delete birdPointer;
		}
		else {
			CDINOSAUR* dinoPointer = new CDINOSAUR;
			saveFile.read(reinterpret_cast<char*>(dinoPointer), sizeof(CDINOSAUR));
			animalList[i] = new CDINOSAUR(*dinoPointer);
			delete dinoPointer;
		}
	}

	saveFile.read(static_cast<char*>(static_cast<void*>(&trafficLightStatus)), sizeof(trafficLightStatus));
	saveFile.read(static_cast<char*>(static_cast<void*>(&reverseLaneStatus)), sizeof(reverseLaneStatus));
	saveFile.read(static_cast<char*>(static_cast<void*>(&gameSpeed)), sizeof(gameSpeed));

	vehicleList.shrink_to_fit();
	animalList.shrink_to_fit();
	saveFile.close();
}
