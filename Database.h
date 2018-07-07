#ifndef Database_H_
#define Database_H_
#include "MasterHeader.h"
#include "CPEOPLE.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"

#define SAVE_PATH "./save.dat"


class Database final
{
	Database() = default;
	~Database() = default;
public:
	void static saveGame(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList, CPEOPLE& player, std::array<bool, 4> trafficLightStatus, std::array<bool, 4> reverseLaneStatus);
	void static loadGame(std::vector<CVEHICLE*> & vehicleList, std::vector<CANIMAL*> & animalList, CPEOPLE& player, std::array<bool, 4> & trafficLightStatus, std::array<bool, 4> & reverseLaneStatus);
};

#endif Database_H_



 