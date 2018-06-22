#include "Database.h"

void Database::saveGame(std::vector<CVEHICLE>& vehicleList, std::vector<CANIMAL>& animalList, CPEOPLE & player)
{
	std::ofstream SaveFile(SAVE_PATH, std::ios::binary);
	SaveFile.write((char*)((void*)(player)), sizeof(player));

	size_t temp = vehicleList.size();
	SaveFile.write((char*)(&temp), sizeof(size_t));
	SaveFile.write(reinterpret_cast<char*>(&vehicleList[0]), vehicleList.size() * sizeof(CVEHICLE));

	temp = animalList.size();
	SaveFile.write((char*)(&temp), sizeof(size_t));
	SaveFile.write(reinterpret_cast<char*>(&animalList[0]), animalList.size() * sizeof(CANIMAL));
	SaveFile.close();
}

void Database::loadGame(std::vector<CVEHICLE>& vehicleList, std::vector<CANIMAL>& animalList, CPEOPLE & player)
{
	std::ifstream SaveFile(SAVE_PATH, std::ios::binary);
	SaveFile.read((char*)((void*)(player)), sizeof(player));
	size_t Size = 0;
	SaveFile.read(reinterpret_cast<char*>(&Size), sizeof(size_t));
	vehicleList.clear();
	vehicleList.resize(Size);
	SaveFile.read(reinterpret_cast<char*>(&vehicleList[0]), Size * sizeof(CVEHICLE));

	Size = 0;
	SaveFile.read(reinterpret_cast<char*>(&Size), sizeof(size_t));
	animalList.clear();
	animalList.resize(Size);
	SaveFile.read(reinterpret_cast<char*>(&animalList[0]), Size * sizeof(CANIMAL));
	SaveFile.close();
}
