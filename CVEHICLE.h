#ifndef CVEHICLE_H_
#define CVEHICLE_H_
#include "MasterHeader.h"
#include "GUI.h"

class CVEHICLE
{
protected:
	int _x, _y;
	int _type; // 0 = car, 1 = truck;
public:
	CVEHICLE() = default;

	// 0 = car, 1 = truck;
	int getType() const;

	void setCoord(int x, int y);
	void Move(int blockX);
	COORD getCoord() const;

	virtual void draw_self() = 0;
	virtual void delete_self() = 0;
};


#endif CVEHICLE_H_

