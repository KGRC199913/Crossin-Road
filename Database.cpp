#include "Database.h"

// DO NOT USE YET
void Database::saveGame(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList, CPEOPLE & player)
{
	/*std::ofstream SaveFile(SAVE_PATH, std::ios::binary);
	SaveFile.write((char*)((void*)(player)), sizeof(player));

	size_t temp = vehicleList.size();
	SaveFile.write((char*)(&temp), sizeof(size_t));
	for (auto& it : vehicleList) {
		SaveFile.write(reinterpret_cast<char*>((void*)(it)), sizeof(CVEHICLE));
	}

	temp = animalList.size();
	SaveFile.write((char*)(&temp), sizeof(size_t));
	for (auto& it : animalList) {
		SaveFile.write(reinterpret_cast<char*>((void*)(it)), sizeof(CANIMAL));
	}
	SaveFile.close();*/
}

//DO NOT USE YET
void Database::loadGame(std::vector<CVEHICLE*>& vehicleList, std::vector<CANIMAL*>& animalList, CPEOPLE & player)
{
	//std::ifstream savefile(save_path, std::ios::binary);
	//savefile.read((char*)((void*)(player)), sizeof(player));
	//size_t size = 0;
	//savefile.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	//vehiclelist.clear();
	//vehiclelist.resize(size);
	//for (auto& it : vehiclelist) {

	//}

	//size = 0;
	//savefile.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	//animallist.clear();
	//animallist.resize(size);
	//savefile.read(reinterpret_cast<char*>(&animallist[0]), size * sizeof(canimal));
	//savefile.close();
}
