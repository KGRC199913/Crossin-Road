#ifndef CVEHICLE_H_
#define CVEHICLE_H_
#include "MasterHeader.h"
#include "GUI.h"

class CVEHICLE
{
protected:
	short _x, _y;
	short _type; // 0 = car, 1 = truck;
	CVEHICLE() = default;
public:
	// 0 = car, 1 = truck;
	int getType() const;

	void setCoord(int x, int y);
	void Move(int blockX);
	COORD getCoord() const;

	virtual void draw_self() = 0;
	virtual void draw_self_bw() = 0;
};


#endif CVEHICLE_H_

