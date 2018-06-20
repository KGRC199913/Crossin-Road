#ifndef Database_H_
#define Database_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"

class Database final
{
public:
	Database() = default;
	~Database() = default;

	void saveGame(std::ostream & saveStream, const std::vector<CVEHICLE> & vehicleList, const std::vector<CANIMAL> & animalList, const CPEOPLE& player);
	void loadGame(std::istream & loadStream, std::vector<CVEHICLE> & vehicleList, std::vector<CANIMAL> & animalList, CPEOPLE& player);
};

#endif Database_H_



