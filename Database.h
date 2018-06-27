#ifndef Database_H_
#define Database_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"

class Database final
{
	Database() = default;
	~Database() = default;
public:
	void static saveGame(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList, CPEOPLE& player);
	void static loadGame(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList, CPEOPLE& player);
};

#endif Database_H_



